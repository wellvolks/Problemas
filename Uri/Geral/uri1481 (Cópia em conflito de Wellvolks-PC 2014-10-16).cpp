#include <bits/stdc++.h>
  
using namespace std;
  
typedef long long int64;
typedef unsigned long long uint64;

#ifdef _WIN32
    #define getchar_unlocked getchar
    #define putchar_unlocked putchar
#endif
   
   
bool read( int &n ) {
    n = 0LL;
    register bool neg = false;
    register char c = getchar_unlocked();
    if( c == EOF) { n = -1; return false; }
    while (!('0' <= c && c <= '9')) {
        if( c == '-' ) neg = true;
        c = getchar_unlocked();
    }
    while ('0' <= c && c <= '9') {
        n = n * 10 + c - '0';
        c = getchar_unlocked();
    }
    n = (neg ? (-n) : (n));
    return true;
}
 
inline void writeInt(int n){
    register int idx = 20;
    if( n < 0 ) putchar_unlocked('-');
    n = abs(n);
    char out[21];
    out[20] = ' ';
    do{
        idx--;
        out[idx] = n % 10 + '0';
        n/= 10;
    }while(n);
    do{ putchar_unlocked(out[idx++]); } while (out[idx] != ' ');
}

struct tri{
    int x, y, z, w, h;
    tri( int x = 0, int y = 0, int z = 0, int w = 0, int h = 0 ) : x(x), y(y), z(z), h(h) { }
};

int n;
int mat1[1002][1002], mat2[1002][1002], mat3[1002][1002], vis = 1;

int main(){
    ios::sync_with_stdio(false);
    while( read(n) && n ){
        tri at;
        int x = 1e9, y = 1e9, z = -1e9, w = -1e9, h;
        memset(mat1,0,sizeof(mat1));
        for( int i = 0; i < n; i++ ){
            read(at.x);
            read(at.y);
            read(at.z);
            read(at.w);
            read(at.h);
            at.x += 20;
            at.y += 20;
            at.z += 20;
            at.w += 20; 
            if( at.x == at.z ) for( int i = min(at.y,at.w); i <= max(at.y,at.w); i++ ) mat1[i][at.x] = at.h;
            else for( int i = min(at.x,at.z); i <= max(at.x,at.z); i++ ) mat1[at.y][i] = at.h;
            x = min(x,min(at.x,at.z));
            z = max(z,max(at.x,at.z));
            y = min(y,min(at.y,at.w));
            w = max(w,max(at.y,at.w));
        }
        read(h);
        int qtd = 0;
        
        /*cout << x << " " << z << " " << y << " " << w << endl;
        cout << " ";
        for( int j = x; j <= z; j++ ) cout << j << " ";
        cout << '\n';
        for( int i = y; i <= w; i++ ){
            cout << i << " ";
            for( int j = x; j <= z; j++ ){
                cout << mat1[i][j] << " ";
            }
            cout << "\n";
        }*/

        for( int j = x; j <= z; j++ ){
            for( int i = y; i <= w; i++ ){
                mat2[i][j] = vis;
                if( mat1[i][j] >= h ) break;
            }
            for( int i = w; i >= y; i-- ){
                mat2[i][j] = vis;
                if( mat1[i][j] >= h ){
                    if( mat2[i-1][j] != vis ) mat2[i][j] = 0;
                    break;
                }
            }
        }
        for( int i = y; i <= w; i++ ){
            for( int j = x; j <= z; j++ ){
                mat2[i][j] = vis;
                if( mat1[i][j] >= h ) break;
            }
            for( int j = z; j >= x; j-- ){
                mat2[i][j] = vis;
                if( mat1[i][j] >= h ){
                    if( mat2[i][j-1] != vis ) mat2[i][j] = 0;
                    break;
                }
            }
        }

        for( int i = y; i <= w; i++ ){
            for( int j = x; j <= z; j++ ){
                cout << (mat2[i][j] != vis) << " ";
                if( mat2[i][j] != vis ) qtd++; 
            }
            cout << '\n';
        }
        writeInt(qtd);
        putchar_unlocked('\n');
        vis++;
    }
    return 0;
}
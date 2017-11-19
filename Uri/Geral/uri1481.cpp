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
    tri( int x = 0, int y = 0, int z = 0, int w = 0, int h = 0 ) : x(x), y(y), z(z), w(w), h(h) { }
};

int n, h;
int mat1[3002][3002], used[3002][3002], mat[3004][3004], vis = 1, vis2 = 1;
vector < tri > vet;
int px[] = {-2,0,2,0,-2,2,-2,2};
int py[] = {0,2,0,-2,-2,2,2,-2};

void bfs( int lox, int loy, int hix, int hiy ){
    queue < tri > fila;
    fila.push(tri(lox,loy,0,0,0));
    while( !fila.empty() ){
        tri at = fila.front();
        fila.pop();
        for( int i = 0; i < 4; i++ ){
            int xx = at.x + px[i];
            int yy = at.y + py[i];
            if( xx >= lox && xx <= hix && yy >= loy && yy <= hiy && mat[xx-px[i]/2][yy-py[i]/2] < h && used[xx][yy] != vis ){
                fila.push(tri(xx,yy,0,0,0));
                used[xx][yy] = vis;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    while( read(n) && n ){
        tri at;
        int x = 1e9, y = 1e9, z = -1e9, w = -1e9;
        memset(mat,-1,sizeof(mat));
        vet.clear();
        for( int i = 0; i < n; i++ ){
            read(at.y);
            read(at.x);
            read(at.w);
            read(at.z);
            read(at.h);
            vet.push_back(at);
            x = min(x,min(at.x,at.z));
            z = max(z,max(at.x,at.z));
            y = min(y,min(at.y,at.w));
            w = max(w,max(at.y,at.w));
        }
        read(h);
        int qtd = 0;
        x = abs(x);
        y = abs(y);
        z += x+1;
        w += y+1;
        
        for( int j = 0; j < n; j++ ){
            at = vet[j];
            at.x += x+1;
            at.y += y+1;
            at.z += x+1;
            at.w += y+1;
            if( at.x == at.z ){
                for( int i = min(at.y,at.w)+min(at.y,at.w)-1, a =  min(at.y,at.w), k = 1; a <= max(at.y,at.w); i++, k++ ){
                    mat[i][at.x + at.x-1] = max(mat[i][at.x + at.x-1],at.h); 
                    if(k & 1) a++;
                }
            }
            else if( at.y == at.w ){
                for( int i = min(at.x,at.z)+min(at.x,at.z)-1, a = min(at.x,at.z), k = 1; a <= max(at.x,at.z); i++, k++ ){
                    mat[at.y+at.y-1][i] = max(mat[at.y+at.y-1][i],at.h);
                    if(k & 1) a++;
                }
            }
        }

        bfs(0,0,2*(z+10),2*(w+10));
        
        for( int i = 0; i <= 2*(z+10); i+=2){
            for( int j = 0; j <= 2*(w+10); j+=2){
                if( used[i][j] != vis ) qtd++;
            }
        }

        writeInt(qtd);
        putchar_unlocked('\n');
        vis++; vis2++;
    }
    return 0;
}
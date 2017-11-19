#include <bits/stdc++.h>
 
using namespace std;
 
 #ifdef _WIN32  
    #define getchar_unlocked getchar 
    #define putchar_unlocked putchar 
#endif 
 
inline bool read( int &n ) { 
    n = 0; 
    register bool neg = false; 
    register char c = getchar_unlocked(); 
    if( c == EOF) { n = -1; return false; } 
    while (!('0' <= c && c <= '9')) { 
        if( c == '-' ) neg = true; 
        c = getchar_unlocked(); 
    } 
    if( c == EOF) { n = -1; return false; }
    while ('0' <= c && c <= '9') { 
        n = n * 10 + c - '0'; 
        c = getchar_unlocked(); 
    } 
    n = (neg ? (-n) : (n)); 
    return true;
} 
    
 
void writeInt(int n){ 
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
 
typedef unsigned long long uint64;
#define LINF 0x3F3F3F3FFFFFFFFFLL
struct tri{
    double x, y, r;
    tri(double x = 0, double y = 0, double r = 0) : x(x), y(y), r(r) { }
};

double grafo[110][110];
vector < tri > vet;
int n;

double getDist(int i, int j) { return sqrt((vet[i].x-vet[j].x)*(vet[i].x-vet[j].x)+(vet[i].y-vet[j].y)*(vet[i].y-vet[j].y)); }

int main(){
    ios::sync_with_stdio(false);
    while( cin >> n && n ){
        double x, y, r;
        int a, b, q;
        for( int i = 0; i < n; i++ ){
            cin >> x >> y >> r;
            vet.push_back(tri(x,y,r));
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if( i == j ) grafo[i][j] = 0;
                else grafo[i][j] = ((getDist(i,j) > (vet[i].r)) ? (1e9) : (getDist(i,j)));;
            }
        }

        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    grafo[i][j] = min(grafo[i][j],grafo[i][k]+grafo[k][j]);
                }
            }
        }

        cin >> q;
        while( q-- ){
            cin >> a >> b;
            double ans = grafo[a-1][b-1];
            if( ans < 1e9 ) cout << (int) ans << '\n';
            else cout << "-1\n";
        }

        vet.clear();

    }
    return 0;
}
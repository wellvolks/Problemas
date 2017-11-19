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
    int at, custo;
    tri(int at = 0, int custo = 0) : at(at), custo(custo) { }
};
 
struct est{
    int at, t;
    uint64 custo;
    est(uint64 custo = 0, int t = 0, int at = 0) : custo(custo), t(t), at(at) { }
    bool operator < (const est &a) const{
        if( a.custo != custo ) return custo > a.custo;
        if( a.t != t ) return t < a.t;
        return at < a.at;
    }
};
 
int n, m, t;
vector < vector < tri > > grafo;
uint64 comprar[100];
uint64 dist[20][60];
 
int solve(){
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= t; j++){
            dist[i][j] = LINF;
        }
    }
    priority_queue < est > fila;
    fila.push(est(0,t,0));
    dist[0][t] = 0;
    while(!fila.empty()){
        est at = fila.top();
        fila.pop();
        if(at.at == n-1) return at.custo;
        for(int i = 0; i < grafo[at.at].size(); i++){
            tri u = grafo[at.at][i];
            for(int j = at.t; j <= t; j++){
                if( u.custo > j ) continue;
                uint64 custo = j - at.t;
                if( dist[u.at][j] > (at.custo + (custo*comprar[at.at])) ){
                    dist[u.at][j] = at.custo + (custo*comprar[at.at]);
                    fila.push(est(dist[u.at][j],j-u.custo,u.at));
                }
            }
        }
    }
    return -1;
}
 
int main(){
    ios::sync_with_stdio(false);
    int de, para, custo;
    while(cin >> n >> m >> t && (n+m+t)){
        grafo.resize(n+10);
        for(int i = 0; i < m; i++){
            cin >> de >> para >> custo;
            de--; para--;
            grafo[de].push_back(tri(para,custo));
            grafo[para].push_back(tri(de,custo));
        }
        for(int i = 0; i < n; i++) cin >> comprar[i];
        cout << solve() << '\n';
        grafo.clear();
    }
 
    return 0;
}
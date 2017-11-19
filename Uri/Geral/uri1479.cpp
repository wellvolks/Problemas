#include <map>
#include <set>
#include <deque>
#include <list>
#include <stack>
#include <cmath>
#include <queue>
#include <ctime>
#include <cfloat>
#include <vector>
#include <string>
#include <cstdio>
#include <bitset>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <iomanip>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>
    
using namespace std;
    
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define RFOR(i, b, a) for(int i = b; i >= a; --i)
#define REP(i, N) for(int i = 0; i < N; ++i)
#define RREP(i, N) for(int i = N-1; i >= 1; --i)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )
#define MAXN 10000
#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFFLL
#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) __typeof((X).begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) int((V).size())
#define pb push_back
#define mp make_pair
    
#ifdef _WIN32
    #define getchar_unlocked getchar
#endif
    
inline void read(  int &n ) {
    n = 0;
    register bool neg = false;
    register char c = getchar_unlocked();
    if( c == EOF) { n = -1; return; }
    while (!('0' <= c && c <= '9')) {
        if( c == '-' ) neg = true;
        c = getchar_unlocked();
    }
    while ('0' <= c && c <= '9') {
        n = n * 10 + c - '0';
        c = getchar_unlocked();
    }
    n = (neg ? (-n) : (n));
}
    
struct tri{
    int atual, custo;
    tri ( int atual = 0, int custo = 0) : atual(atual), custo(custo) { }
};
    
struct par{
    int de, para;
    par(int de = 0, int para = 0) : de(de), para(para) { }
};
    
int n, m;
typedef vector < int > vi;
typedef vector < vi > vii;
typedef vector < tri > vtri;
typedef vector < vtri > vvtri;
typedef long long int64;
typedef unsigned long long uint64;
    
int grafoPos[10010][10010]; 
vector < vector < tri > > grafo;
    
long long dist[100010], in_queue[100010];
int  vis = 1;
    
    
long long spfa( int v ){
    REP(i,n) dist[i] = INF;
    dist[0] = 0;
    queue < int > q; 
    q.push(0);
    in_queue[0] = vis;
    while( !q.empty() ){
        int u = q.front();
        q.pop();
        in_queue[u] = 0;
        int tam = grafo[u].size();
        REP(i,tam){
            if( grafo[u][i].custo < 0 ) continue;
            tri at = grafo[u][i];
            if( dist[u] + at.custo <= dist[at.atual] ){
                dist[at.atual] = dist[u] + at.custo;
                if( in_queue[at.atual] != vis ){
                    q.push( at.atual );
                    in_queue[at.atual] = vis;
                }
            }
        }
    }
    return (( dist[v] < INF ) ? ( dist[v] ) : ( -1 ));
}
    
    
int main(){
    ios::sync_with_stdio(false);
    int q, de, para, w, k;
    char c;
    while( cin >> n >> m && ( n + m ) ){
        grafo.resize( n + 10 );
        REP(i,n+5) FOR(j,i,n+5) grafoPos[i][j] = grafoPos[j][i] = -1;
        REP(i,m){
            cin >> de >> para >> w;
            de--; para--;
            grafoPos[de][para] = grafo[de].size();
            grafo[de].pb(tri(para, w));
        }
        cin >> q;
        bool flag = true;
        while( q-- ){
            cin >> c;
            if( c == 'P' ){
                cin >> de;
                de--;
                cout << spfa(de) << "\n";
                vis++;
            }
            else if( c == 'R' ){
                cin >> de >> para;
                de--; para--;
                grafo[de][grafoPos[de][para]].custo = -10000;
            }
            else{
                cin >> de >> para >> k;
                de--; para--;
                if( grafoPos[de][para] == -1 ){
                    grafoPos[de][para] = grafo[de].size();
                    grafo[de].pb(tri(para, k));
                }
                else{
                    grafo[de][grafoPos[de][para]].custo = k;
                }
            }
        }
        cout << "\n";
        grafo.clear();
        vis++;
    }
    return 0;
}
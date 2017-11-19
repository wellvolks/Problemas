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
#define INF 0x3F3F3F3
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
    int atual;
    int custo;
    tri ( int atual = 0, int custo = 0LL) : atual(atual), custo(custo) { }
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
      
int used[1100][1100]; 
vector < vector < tri > > grafo;
      
int dist[1100];
int path[1100], vis = 1;
      

      
int dijkstra( int de, int para ){
    REP(i,n) dist[i] = INF;
    dist[de] = 0LL;
    priority_queue < pair<int,int> > q;
    q.push (make_pair (0LL, de));
	path[de] = -1;
    while (!q.empty()) {
        int v = q.top().second;
        int cur_d = -q.top().first;
        q.pop();
		if( v == para ) return cur_d;
        if (cur_d > dist[v])  continue;
        int tam = grafo[v].size();
        REP(j,tam) {
            int to = grafo[v][j].atual;
            int len = grafo[v][j].custo;
			if( used[v][to] == vis ) continue;
            if (dist[v] + len <= dist[to]) {
                dist[to] = dist[v] + len;
				path[to] = v;
                q.push (make_pair (-dist[to], to));
            }
        }
    }
	return INF;
}
     
	 
void getPath( int de, int para ){
	int at = path[para];
	if( at == -1 ) used[de][para] = vis;
	while( at != -1 ){
		used[at][para] = vis;
		para = at;
		at = path[at];
	}
}
	 
int main(){
    int q, de, para, w, k, c;
    while( true ){
        read(n); read(m);
        if( !(n+m) ) break;
		read(w); read(k);
		grafo.resize( n );
		REP(i,m){
			read(de); read(para); read(c);
			grafo[de].pb(tri(para,c));
		}
		int ans = dijkstra(w,k);
		getPath( w, k );
		if( ans >= INF ) cout << "-1\n";
		else{
			int ret = dijkstra(w,k);
			getPath( w, k );
			while( ans == ret ){
				ret = dijkstra(w,k);
				getPath( w, k );
			}
			if( ret >= INF ) cout << "-1\n";
			else cout << ret << "\n";
		}
		grafo.clear();
		vis++;
	}
	return 0;
}
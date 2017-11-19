#include <set>
//#include <tr1/unordered_map>
#include <map>
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
//using namespace tr1;

#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define RFOR(i, b, a) for(int i = b; i >= a; --i)
#define REP(i, N) for(int i = 0; i < N; ++i)
#define RREP(i, N) for(int i = N-1; i >= 0; --i)
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

const double EPS = 1e-9;

typedef unsigned long long uint64;
struct tri{
	int atual, custo;
	tri ( int atual = 0, int custo = 0) : atual(atual), custo(custo) { }
	bool operator < (const tri &a ) const{
		return custo < a.custo;
	}
};

int cmp(double a, double b = 0.0){
	if(fabs(a-b) < EPS) return 0;
	return a > b ? 1 : -1;
}

#ifdef _WIN32 
    #define getchar_unlocked getchar
#endif
 
inline void read( int &n ) {
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

vector < vector < tri > > grafo;
int visit[100000], vis = 1, dist[100000];
int cam[100000];
int melhor = INF;
int memo[110][10000];

int solve(int de, int alt, int para ){
	if( de == para ){ melhor = min(melhor,alt); return memo[de][alt+1001] = alt; } 
	if( memo[de][alt+1001] != -1 ) return memo[de][alt+1001];
	int tam = grafo[de].size();
	int ans = INF;
	memo[de][alt+1001] = ans;
	if( alt >= melhor ) return INF;
	REP(i,tam){
		//if( visit[grafo[de][i].atual] != vis ){
		//	visit[grafo[de][i].atual] = vis;s
			ans = min( ans, solve(grafo[de][i].atual, max(alt,grafo[de][i].custo), para));
		//	visit[grafo[de][i].atual] = 0;
		//}
	}
	return memo[de][alt+1001] = ans;
}

int main(){
	ios::sync_with_stdio(false);
	int n, m, de, para, alt, q, t = 1;
	while( true ){
		read(n);
		read(m);
		grafo.resize(n+10);
		if( !(n + m) ) break;
		REP(i,m){
			read(de);
			read(para);
			read(alt);
			grafo[de-1].pb(tri(para-1,alt));
			grafo[para-1].pb(tri(de-1,alt));
		}
		REP(i,n) sort(ALL(grafo[i]));
		read(q);
		printf("Instancia %d\n",t++);
		while( q-- ){
			read(de); 
			read(para);
			memset(memo,-1,sizeof(memo));
			int ans = solve(de-1,-1000,para-1);
			printf("%d\n",(ans == -1000) ? (0) : (ans));
			vis++;
			melhor = INF;
		}
		printf("\n");
		grafo.clear();
	}
	return 0;
}
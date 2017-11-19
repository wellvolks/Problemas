#include <list>
#include <set>
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
#define RREP(i, N) for(int i = N-1; i >= 0; --i)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )
#define MAXN 100010 
#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFFLL
#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) __typeof((X).begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) int((V).size())
#define pb push_back
#define mp make_pair
  
typedef  long long int64;

int n, m;
int c1, c2, q, de, para;

vector < vector < int > > grafo;

int visit[100100], vis = 1;
int grau[100100];

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

int bfs( int cur ){
	queue < pair < int, int > > fila;
	pair < int, int > at;
	vis++;
	FOR(i,1,c1+c2+2) if( !grau[i] ) visit[i] = vis;
	if( cur ){
		FOR(i,c1+1,c1+c2) if( !grau[i] ) REP(j,grafo[i].size())  fila.push( make_pair( grafo[i][j], 2 ) );
		FOR(i,1,c1) REP(j,grafo[i].size()) if( !grau[i] || !grau[grafo[i][j]] ) fila.push( make_pair( grafo[i][j], 3  ) ); 
	}
	else{
		FOR(i,1,c1) if( !grau[i] ) REP(j,grafo[i].size())  fila.push( make_pair( grafo[i][j], 2 ) );
		FOR(i,c1+1,c1+c2) REP(j,grafo[i].size()) if( !grau[i] || !grau[grafo[i][j]] ) fila.push( make_pair( grafo[i][j], 3 ) );
	}
	int ans = 2;
	while( !fila.empty() ){
		at = fila.front();
		fila.pop();
		if( visit[at.first] == vis ) continue;
		visit[at.first] == vis;
		ans = max(ans,at.second);
		int tam = grafo[at.first].size();
		REP(i,tam){
			fila.push(make_pair(grafo[at.first][i], at.second + 1));
		}
	}
	return ans + 1 ;
}

int main(){

	while( true ){
		read( c1 ); 
		read( c2 );
		read( q );
		if( !(c1 + c2 + q) ) break;
		grafo.resize( c1 + c2 + 10 );
		REP(i,c1+c2+2) grau[i] = 0; 
		REP(i,q){
			read(de); read(para);
			if( (de <= c1 && para <= c1) || (de > c1 && para > c1 )) continue;
			grafo[para].pb(de);
			grau[de]++;
		}
		printf("%d\n",min( bfs(0), bfs(1) ));
		grafo.clear();
	}
	
	return 0;
}
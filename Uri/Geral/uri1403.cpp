#include <set>
#include <map>
#include <tr1/unordered_map>
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
#include <bitset>
 
using namespace std; 
using namespace tr1;

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
 
struct tri{
    int ant, novo;
    tri ( int ant = 0, int novo = 0) : ant(ant), novo(novo) { }
};
 
struct estado{
	int id, apa;
	estado( int id = 0, int apa = 0 ) : id(id) , apa(apa) { }
};
 
typedef vector < int > vi;
typedef vector < vi > vii;
typedef vector < tri > vtri;
typedef vector < vtri > vvtri;
typedef long long int64;
typedef unsigned long long uint64;
 
int x[] = {-1,-1,-1, 0, 1, 1, 1, 0 };
int y[] = {-1, 0, 1, 1, 1, 0,-1,-1 };
 
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

unordered_map < int, int > mapa;
unordered_map < int, int > :: iterator it;
vector < estado > ranq;

bool comp( const estado &a, const estado &b ){
	if( a.apa != b.apa ) return (a.apa > b.apa);
	return (a.id < b.id);
}

int main(){
	register int n, m, v;
	read(n); read(m);
	while( (n+m) ){
		REP(i,n) REP(j,m){ read(v); mapa[v]++; }
		for( it = mapa.begin(); it != mapa.end(); it++ ) ranq.pb(estado(it->first,it->second));
		sort(ALL(ranq), comp);
		register int tam = ranq.size();
		register int score = ranq[1].apa;
		FOR(i,1,tam-1){
			if( ranq[i].apa == score ) fprintf(stdout,"%d ",ranq[i].id); 
			else break;
		}
		fprintf(stdout,"\n");
		ranq.clear();
		mapa.clear();
		read(n); read(m);
	}
	return 0;
}
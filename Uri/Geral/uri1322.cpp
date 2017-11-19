#include <set>
#include <tr1/unordered_map>
#include <tr1/unordered_set>
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
using namespace tr1;

#define fori(i, n) for ( int i = 0; i < (n); ++i )
#define forr(i, a, b) for ( int i = (a); i <= (b); ++i )
#define ford(i, a, b) for ( int i = (a); i >= (b); --i ) 
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define RFOR(i, b, a) for(int i = b; i >= a; --i)
#define REP(i, N) for(int i = 0; i < N; ++i)
#define RREP(i, N) for(int i = N-1; i >= 0; --i)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )
#define MAXN 1006003
#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFFLL
#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) __typeof((X).begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) int((V).size())
#define pb push_back
#define mp make_pair
  
  
struct tri{
    int qtd, pts, id, insc;
	tri( int qtd = 0, int pts = 0, int id = 0, int insc = 0) : qtd(qtd) , pts(pts), id(id), insc(insc) { }
};
 
typedef vector < int > vi;
typedef vector < vi > vii;
typedef vector < tri > vtri;
typedef vector < vtri > vvtri;
typedef long long int64;
typedef unsigned long long uint64;

#ifdef _WIN32 
    #define getchar_unlocked getchar
#endif

inline void read( unsigned int &n ) {
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

int visit[100000*2], used[100000*2], vis2 = 1, startCiclo[100000*2], vis = 1;
vector < unsigned int > grafo[100000*2];
unordered_map < unsigned int, int > id;


int ans = 0;

void dfs(int p, int de, int qtd){
	int tam = grafo[p].size();
	if( visit[p] == vis ) return ;
	startCiclo[p] = qtd;
	visit[p] = vis;
	REP(i,tam){
		int k = grafo[p][i];
		if( de == k ) continue;
		if( visit[k] != vis ) dfs(k,p,qtd+1);
		else if( used[k] != vis2 ) ans = qtd - startCiclo[k]+1;
	}
	used[p] = vis2;
}

int main(){
	unsigned int k, w, de, para, n;
	unordered_map < unsigned int, int > grau;
	while( true ){
		read(k); read(w);
		if( !(k+w) ) break;
		n = k;
		bool ok = true;
		int qtd = 0;
		while( w-- ){
			read(de); read(para);
			if(!id.count(de) ) id[de] = qtd++;
            if(!id.count(para)) id[para] = qtd++;
			de = id[de];
			para = id[para];
			grafo[de].pb(para);
			grafo[para].pb(de);
		}
		bool ret = false;
		REP(i,qtd){
            sort(ALL(grafo[i]));
			grafo[i].erase(unique(ALL(grafo[i])),grafo[i].end());
			if( grafo[i].size() > 2 ) ok = false;
        }
		ans = -1;
		if( ok ){
			REP(i,qtd){
				if( visit[i] == vis ) continue;
				dfs(i,-1,0);
			}
		}
		else ans = -INF;
		fprintf(stdout,"%c\n",(ans == -1 || ans == k) ? ('Y') : ('N'));
		ans = 0;
		vis++;
		vis2++;
		id.clear();
		REP(i,qtd+1) grafo[i].clear();
	}
}

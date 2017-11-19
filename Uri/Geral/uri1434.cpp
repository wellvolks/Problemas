#include <map>
#include <set>
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
#define a first
#define b second

struct aresta{
	int atual, valor;
	aresta ( int atual = 0, int valor = 0) : atual(atual), valor(valor) { }
};

int c, r, n, s, vii = 1; 
typedef long long int64;
typedef unsigned long long uint64;

struct tri{
	long long valor, vi;
	tri(long long valor = 0, long long vi = 0) : valor(valor), vi(vi) { } 
};

tri tree[100010];

long long query(int tam, long long a, long long b) {
    if (a == 0) {
        long long sum = 0;
        for (; b >= 0; b = (b & (b + 1)) - 1){
		  if(tree[b].vi != vii) tree[b].valor = 0;
          sum += tree[b].valor;
		  tree[b].vi = vii;
		}
        return sum; 
    } else {
        return query(tam, 0, b) - query(tam, 0, a-1);
    }
}

void increase(int tam, long long k, long long inc) {
    for (; k < tam+1; k |= k + 1){
		if(tree[k].vi != vii) tree[k].valor = 0;
        tree[k].valor += inc;
		tree[k].vi = vii;
	}
}

vector < vector < aresta > > grafo;

int ans = 0;

void dfs(int u, int ciclo, int custo, int k){
	int escolha = -INF, id;
	if( ciclo >= n ) return ;
	if ( k == custo ){
		REP(i,grafo[u].size()){
			int ici = query(c, grafo[u][i].atual, grafo[u][i].atual);
			if( ici > escolha ){
				escolha = ici;
				id = i;
			}
			else if( ici == escolha && i < id) id = i;
		}
		REP(i,c)  increase(c, i, 1);
		if( grafo[u][id].valor == 1 ){
			int valor = query(c,grafo[u][id].atual,grafo[u][id].atual);
			increase(c, grafo[u][id].atual, -valor);
		}
		ans += query(c, 0, c-1);
		dfs(grafo[u][id].atual, ciclo + 1, grafo[u][id].valor, 1);
	}
	else{
		int iei = 0;
		if( k + 1 == custo ){
			REP(i,c)  increase(c, i, 1);
			int valor = query(c,u,u);
			increase(c, u, -valor);
			ans += query(c, 0, c-1);
			dfs(u, ciclo + 1, custo, k + 1);
		}
		else{
			REP(i,c)  increase(c, i, 1);
			iei = query(c, 0, c-1);
			ans += iei;
			dfs(u, ciclo + 1, custo, k + 1);
		}
	}
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

int main(){
	ios::sync_with_stdio(false);
	int x, y, km;
	read(c); read(r); read(n); read(s);
	while( (c+r+n+s) ){
		grafo.resize(c+10);
		REP(i,r){
			read(x); read(y); read(km);
			grafo[x-1].pb(aresta(y-1,km));
			grafo[y-1].pb(aresta(x-1,km));
		}
		dfs(s-1, 0, 0, 0);
		printf("%d\n",ans);
		grafo.clear();
		vii++;
		ans = 0;
		read(c); read(r); read(n); read(s);
	}
	return 0;
}

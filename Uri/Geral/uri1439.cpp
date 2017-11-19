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
#define INF 0x3f3f3f3f
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
 
struct aresta{
    int atual, valor;
    aresta ( int atual = 0, int valor = 0) : atual(atual), valor(valor) { }
};
 
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

struct carta{
	int valor;
	char naipe;
	carta ( int valor = 0, char naipe = '*' ) : valor(valor), naipe(naipe) { }
	bool operator < ( const carta &a ) const {
		if( a.valor != valor ) return valor > a.valor;
		return naipe > a.naipe;
	}
};

stack < carta > saque, descarte;

vector < vector < carta > > player;

int p, n, m;

// valete = 11, dama = 12, rei = 13

int game(){
	carta ant = descarte.top();
	bool cartaEspecial = ( ant.valor == 12 || ant.valor == 1 || ant.valor == 7 || ant.valor == 11);
	int dire = 1, idx = -1;
	bool start = true;
	vector < carta > :: iterator it;
	while( true ){
		ant = descarte.top();
		idx += dire;
		if( idx < 0 ) idx = p-1;
		else idx %= p;
		if( cartaEspecial ){
			if( ant.valor == 7 ){
				player[idx].pb(saque.top());
				saque.pop();
				player[idx].pb(saque.top());
				saque.pop();
				sort(ALL(player[idx]));
			}
			else if( ant.valor == 1 ){
				player[idx].pb(saque.top());
				sort(ALL(player[idx]));
				saque.pop();
			}
			else if( ant.valor == 11 );
			else if( ant.valor == 12 ){
				if( !start ) dire = -dire;
				else{ dire = -1; idx = 1; }
			}
			cartaEspecial = false;
		}
		else{
			if( !player[idx].size() ) return idx;
			bool ok = false;
			REP(i,2){
				for(it = player[idx].begin(); it != player[idx].end(); it++){
					if( ant.valor == it->valor || ant.naipe == it->naipe ){
						ant = *it;
						player[idx].erase(it);
						ok = true;
						break;
					}				
				}
				if( !player[idx].size() ) return idx;
				if( ok ) break;
				if( !i ){
					player[idx].pb(saque.top());
					sort(ALL(player[idx]));
					saque.pop();
				}
			}
			if( ok ){
				descarte.push(ant);
				cartaEspecial = ( ant.valor == 12 || ant.valor == 1 || ant.valor == 7 || ant.valor == 11);
				if( ant.valor == 12 ){
					dire = -dire;
					cartaEspecial = false;
				}
			}
		}
		start = false;
	}
	return 0;
}

int main(){
	ios::sync_with_stdio(false);
	carta c, start;
	vector < carta > aux;
	while ( true ){
		read(p); read(m); read(n);
		if( !(p + m + n) ) break;
		player.resize(p+10);
		REP(i,p) REP(j,m){
			read(c.valor);
			c.naipe = getchar_unlocked();
			player[i].pb(c);
		}
		read(start.valor);
		start.naipe = getchar_unlocked();
		//cin >> start.valor >> start.naipe;
		descarte.push(start);
		FOR(i,(p*m)+1, n-1){
			//cin >> c.valor >> c.naipe;
			read(c.valor);
			c.naipe = getchar_unlocked();
			aux.pb(c);
		}
		REP(i,p) sort(ALL(player[i]));
		RFOR(i,aux.size()-1, 0) saque.push(aux[i]);
		printf("%d\n",game() + 1); 
		player.clear();
		aux.clear();
		while( !saque.empty() ) saque.pop();
		while( !descarte.empty() ) descarte.pop();
	}
	return 0;
}
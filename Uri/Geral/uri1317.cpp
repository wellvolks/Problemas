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
    int id;
	string at;
    tri ( int id = 0, string at = "") : id(id), at(at) { }
};
  
struct pt{
    int t1, t2;
    pt ( int t1 = 0, int t2 = 0 ) : t1(t1), t2(t2) { }
};

struct st{
	int id, t1, t2;
	int k1, k2, k3;
	string a, b, c;
	st( int id = 0, string a = "", string b = "", string c = "", int t1 = 0, int t2 = 0, int k1 = 0, int k2 = 0, int k3 = 0 ) : id(id), a(a), b(b), c(c), t1(t1), t2(t2), k1(k1), k2(k2), k3(k3) { }
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

vector < vector < tri > > atri;
vector < pt > lim;

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

int x[] = {-1,-1,-1, 0, 1, 1, 1, 0 };
int y[] = {-1, 0, 1, 1, 1, 0,-1,-1 };
int n;

vector < vector < int > > grafo;
vector < string > names;

int visitado[100][100], vis = 1;

vector < vector < int > > stado;
vector < uint64 > used;
vector < vector < int > > ans;
vector < string > spam;

int pos( int tam, int de ){
	if( tam < lim[de].t1 ) return atri[de][0].id;
	if( lim[de].t1 <= tam && tam < lim[de].t2 ) return atri[de][1].id;;
	return atri[de][2].id;;
}

void solve( int p ){
	int qt = stado[p].size();
	REP(i,qt){
		if( !(used[p] & (uint64(1) << stado[p][i])) ){
			used[p] |= (uint64(1) << stado[p][i]);
			int k = pos( grafo[p].size(), stado[p][i] );
			ans[p].pb(k);
		}
	}
	bool ok = false;
	int qtd = grafo[p].size();
	if( p == 4 )
		int opa = 0;
	REP(i,grafo[p].size()){
		int de = grafo[p][i];
		REP(j,qt){
			if( !(used[de] & (uint64(1) << stado[p][j] ) ) ){  
				stado[de].pb(stado[p][j]);
				ok = true;
			}
		}
	}
	stado[p].clear();
	if( !ok ) return;
	REP(i,qtd) solve(grafo[p][i]);
}

int main(){
	int k;
	while( true ){
		read(n);
		if( !n ) break;
		lim.resize(n);
		grafo.resize(n);
		atri.resize(n);
		used.resize(n);
		ans.resize(n);
		REP(i,n){
			read(k);
			while( k ){
				grafo[i].pb(k-1);
				read(k);
			}
		}
		read(k);
		stado.resize(n);
		char cc;
		int w = 0, start = k-1;
		queue < st > fila;
		while( k ){
			stado[k-1].pb(k-1);
			read(lim[k-1].t1);  
			read(lim[k-1].t2);
			cc = getchar_unlocked();
			int p = 0;
			while( cc != '\n' ){
				while( !isalpha(cc) ) cc = getchar_unlocked();
				atri[k-1].pb(tri(w,""));
				while( isalpha(cc) ){
					atri[k-1][p].at += cc;
					cc = getchar_unlocked();
				}
				spam.pb(atri[k-1][p].at);
				w++;
				p++;
			}
			fila.push(st(k-1,atri[k-1][0].at, atri[k-1][1].at, atri[k-1][2].at, lim[k-1].t1, lim[k-1].t2, atri[k-1][0].id, atri[k-1][1].id, atri[k-1][2].id)); 
			//st( int id = 0, string a = "", string b = "", string c = "", int t1 = 0, int t2 = 0, int k1 = 0, int k2 = 0, int k3 = 0 )
			read(k);
		}
		names.resize(n);
		cc = getchar_unlocked();
		REP(i,n){ 
			while( !isalpha(cc) ) cc = getchar_unlocked();
			while( isalpha(cc) ){
				names[i] += cc;
				cc = getchar_unlocked();
			}
		}	
		st atual;
		while( !fila.empty() ){
			atual = fila.front();
			fila.pop();
			atri[atual.id].clear();
			stado[atual.id].clear();
			lim[atual.id].t1 = atual.t1;
			lim[atual.id].t2 = atual.t2;
			stado[atual.id].pb(atual.id);
			atri[atual.id].pb(tri(atual.k1,atual.a));
			atri[atual.id].pb(tri(atual.k2,atual.b));
			atri[atual.id].pb(tri(atual.k3,atual.c));
			lim[atual.id].t1 = atual.t1;
			lim[atual.id].t2 = atual.t2;
			solve(atual.id);
		}
		REP(i,n){
			sort(ALL(ans[i]));
			printf("%s:",names[i].c_str());
			int qt = ans[i].size();
			REP(j,qt) printf(" %s",spam[ans[i][j]].c_str());
			printf("\n");
		}
		lim.clear();
		grafo.clear();
		atri.clear();
		used.clear();
		ans.clear();
		names.clear();
		spam.clear();
		stado.clear();
	}
	return 0;
}

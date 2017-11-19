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
    int id, l1, l2, k1, k2, k3;
	string a, b, c;
    tri ( int id = 0, int k1 = 0, int k2 = 0, int k3 = 0, int l1 = 0, int l2 = 0, string a = "", string b = "", string c = "") : id(id), k1(k1), k2(k2), k3(k3), l1(l1), l2(l2), a(a), b(b), c(c) { }
};
  
struct pt{
    int x, y;
    pt ( int x = 0, int y = 0 ) : x(x), y(y) { }
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

/*
inline void readString( char *cc ){
	int p = 0;
	char c = getchar_unlocked();
	while( !isalpha(c) ) c = getchar_unlocked();
	while( isalpha(c) ){ cc[p++] = c; c = getechar_unlocked(); }
}*/

vector < vector < int > > grafo;
vector < tri > atri;
vector < string > names, spam;
vector < vector < int > > ans;
tri atual;
vector < uint64 > used;
vector < vector < int > > state;
int n;
int visit[1000], vis = 1;
uint64 pot[30];

void potProcess(){
	pot[0] = 1LL;
	REP(i,21) pot[i+1] = pot[i] << 1;
}

int pos( int qtdEnd ){
	if( qtdEnd < atual.l1 ) return atual.k1;
	if( atual.l1 <= qtdEnd && qtdEnd < atual.l2 ) return atual.k2;
	return atual.k3;
}

void solve( int p ){
	register int qt = state[p].size();
	if( !qt ) return ;
	visit[p] = vis;
	REP(i,qt){
		if( !(used[p] & pot[atual.id]) ){
			used[p] |= pot[atual.id];
			register int k = pos( grafo[p].size());
			ans[p].pb(k);
		}
	}
	register bool ok = false;
	register int qtd = grafo[p].size();
	register int tt = grafo[p].size();
	REP(i,tt){
		register int de = grafo[p][i];
		if(qt && !(used[de] & pot[atual.id]) ){  
			state[de].pb(atual.id);
			ok = true;
		}
	}
	state[p].clear();
	if( !ok ) return;
	REP(i,qtd) solve(grafo[p][i]);
}


int main(){
	register int k;
	potProcess();
	while( true ){
		//cin >> n;
		read(n);
		if( !n ) break;
		atri.resize(n);
		grafo.resize(n);
		ans.resize(n);
		state.resize(n);
		used.resize(n);
		REP(i,n){
			//cin >> k;
			read(k);
			while( k ){
				grafo[i].pb(k-1);
				read(k);
			}
		}
		read(k);
		register int l1, l2, p = 0, qt = 0;
		string st1, st2, st3;
		queue < tri > fila;
		while( k ){
			read(l1); read(l2);
			qt++;
			st1 = ""; st2 = ""; st3 = "";
			register char cc = getchar_unlocked();
			while(!isalpha(cc)) cc = getchar_unlocked();
			while(isalpha(cc)){ st1 += cc; cc = getchar_unlocked(); }
			while(!isalpha(cc)) cc = getchar_unlocked();
			while(isalpha(cc)){ st2 += cc; cc = getchar_unlocked(); }
			while(!isalpha(cc)) cc = getchar_unlocked();
			while(isalpha(cc)){ st3 += cc; cc = getchar_unlocked(); }
			spam.pb(st1); spam.pb(st2); spam.pb(st3);
			fila.push(tri(k-1, p, p+1, p+2, l1, l2, st1, st2, st3));
			p += 3;
			read(k);
		}
		while( !fila.empty() ){
			atual = fila.front();
			fila.pop();
			state[atual.id].pb(atual.id);
			solve(atual.id);
			REP(i,n){
				state[i].clear();
				used[i] = 0LL;
				if( visit[i] != vis ){
					register int pp = pos( (( i == atual.id ) ? (grafo[i].size()) : (-1)) );
					ans[i].pb(pp);
				}
			}
			vis++;
		}
		char str[1000], pp = 0;
		REP(i,n){
			register char cc = getchar_unlocked();
			while(!isalpha(cc)) cc = getchar_unlocked();
			while(isalpha(cc)){ str[pp++] = cc; cc = getchar_unlocked(); }
			str[pp] = '\0';
			fprintf(stdout,"%s:",str);
			REP(j,qt) fprintf(stdout," %s",spam[ans[i][j]].c_str());
			fprintf(stdout," \n");
			pp = 0;
		}
		grafo.clear();
		atri.clear();
		ans.clear();
		spam.clear();
		vis++;
	}
}

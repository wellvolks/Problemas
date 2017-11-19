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
#define MAXN 100010 
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
 
int n;
map < string, int > names;
vector < string > nm;
int path[110][110], grafo[110][110];
vector < string > pat;

int floyd(){
	REP(i,n) REP(j,n) path[i][j] = i;
	REP(k,n){
		REP(i,n){
			REP(j,n){
				if( grafo[i][j] > grafo[i][k] + grafo[k][j] ){
					grafo[i][j] = grafo[i][k] + grafo[k][j];
					path[i][j] = path[k][j];
				}
			}
		}
	}
}

void caminho(int i, int j){
	if( i != j ) caminho(i, path[i][j]); 
	pat.pb(nm[j]);
}
 
int main(){
	register int c, p, v;
	read(c);
	string name;
	while( c-- ){
		read(n);
		register char cc;
		REP(i,n){
			cc = getchar_unlocked();
			while( !isalpha( cc ) ) cc = getchar_unlocked();
			while( isalpha( cc ) || (cc >= '0' && cc <= '9') ){ name += cc; cc = getchar_unlocked(); }
			names[name] = i;
			nm.pb(name);
			name = "";
		}
		REP(i,n){
			REP(j,n){
				read(grafo[i][j]);
				if( grafo[i][j] < 0 ) grafo[i][j] = INF;
			}
		}
		register int p, cust = INF;
		string de, para, opera;
		read(p);
		floyd();
		while( p-- ){
			opera = ""; de = ""; para = "";
			cc = getchar_unlocked();
			while( !isalpha( cc ) ) cc = getchar_unlocked();
			while( isalpha( cc ) || (cc >= '0' && cc <= '9')){ opera += cc; cc = getchar_unlocked(); }	
			while( !isalpha( cc ) ) cc = getchar_unlocked();
			while( isalpha( cc ) || (cc >= '0' && cc <= '9')){ de += cc; cc = getchar_unlocked(); }	
			while( !isalpha( cc ) ) cc = getchar_unlocked();
			while( isalpha( cc ) || (cc >= '0' && cc <= '9')){ para += cc; cc = getchar_unlocked(); }	
			register int dd = names[de], pp = names[para];
			cust = grafo[dd][pp];
			if( cust < INF ){
				printf("Mr %s to go from %s to %s, you will receive %d euros\n",opera.c_str(), de.c_str(), para.c_str(), cust);
				printf("Path:%s",de.c_str());
				caminho(dd, pp);
				if( pat.size() == 1 ) printf(" %s\n",para.c_str());
				else{
					int tam = pat.size();
					FOR(i,1,tam-1) printf(" %s",pat[i].c_str());
					printf("\n");
				}
			}
			else printf("Sorry Mr %s you can not go from %s to %s\n",opera.c_str(), de.c_str(), para.c_str());
			pat.clear();
		}
		names.clear();
		nm.clear();
	}
	return 0;
}
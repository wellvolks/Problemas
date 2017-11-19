#include <tr1/unordered_map>
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
    int atual, tipo;
    tri ( int atual = 0, int tipo = 0) : atual(atual), tipo(tipo) { }
};
 
int n, m;
typedef vector < int > vi;
typedef vector < vi > vii;
typedef vector < tri > vtri;
typedef vector < vtri > vvtri;
typedef long long int64;
typedef unsigned long long uint64;
const double pi = acos(-1.0);
const double EPS = 1e-9;
 
int cmp(double a, double b = 0.0){
    if(fabs(a-b) < EPS) return 0;
    return a > b ? 1 : -1;
}
int x[] = {-1,-1,-1, 0, 1, 1, 1, 0 };
int y[] = {-1, 0, 1, 1, 1, 0,-1,-1 };
 
struct estado{
    int valor, id;
    estado (int valor = 0, int id = 0) : valor(valor), id(id) { }
    bool operator < (const estado &a) const{
        if( valor != a.valor ) return valor < a.valor;
        return id > a.id;
    }
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

estado vet[1000010];
 
char str[100];
 
int main(){
    register int t, qt, v, c = 1;
    register bool ok = false;
    unordered_map < int, int > mapa;
    unordered_map < int, int > :: iterator it;
    while( 1 ){
		read(t);
		if( !t ) return 0;
        if(ok) printf("\n");
        ok = true;
        mapa.clear();
        register double sumQt =0., sumV =0.;
        register int p = 0;
		REP(i,t){
            //scanf("%d %d",&qt, &v);
            read(qt); read(v);
			sumQt += (double)qt; sumV += (double)v;
            register int ret = v/qt;
			mapa[ret] += qt;
        }
        for(it = mapa.begin(); it != mapa.end(); it++){ vet[p].valor = it->first; vet[p++].id = it->second; }
        sort(vet, vet+p);
        printf("Cidade# %d:\n",c++);
        printf("%d-%d",vet[0].id, vet[0].valor);
        for(int i = 1; i < p; i++) printf(" %d-%d",vet[i].id, vet[i].valor);
        register double ans = sumV/sumQt;
        sprintf(str, "%.4lf", ans);
        str[strlen(str)-2] = '\0'; 
        printf("\nConsumo medio: %s m3.\n",str);
    }
    return 0;
}

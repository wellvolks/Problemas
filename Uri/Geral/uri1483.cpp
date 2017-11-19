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
#define RREP(i, N) for(int i = N-1; i >= 1; --i)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )
#define MAXN 10000
#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFFLL
#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) __typeof((X).begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) int((V).size())

#define pb push_back
#define mk make_pair

struct tri{
	int atual, custo;
	tri ( int atual = 0, int custo = 0) : atual(atual), custo(custo) { }
};

struct mao{
	int qt, topo, p;
	mao(int qt = 0, int topo = 0, int p = 0) : qt(qt) , topo(topo), p(p) { }
};

int n, m, tamanho;
typedef vector < int > vi;
typedef vector < vi > vii;
typedef vector < tri > vtri;
typedef vector < vtri > vvtri;
typedef long long int64;
typedef unsigned long long uint64;
int b[110][1010], tamm;
int x[] = {-1,-1,-1, 0, 1, 1, 1, 0 };
int y[] = {-1, 0, 1, 1, 1, 0,-1,-1 };
int bicho[200];
char aposta[1000], sorteado[1000];

 #ifdef _WIN32
    #define getchar_unlocked getchar
#endif

inline void readInt( int &n ) {
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


inline void readDouble( double &n ) {
    n = 0.;
    register bool neg = false;
    register char c = getchar_unlocked();
    if( c == EOF) { n = -1.; return; }
    while (!('0' <= c && c <= '9')) {
        if( c == '-' ) neg = true;
        c = getchar_unlocked();
    }
	register double k = 1.;
	register bool ok = true;
    while (('0' <= c && c <= '9')) {
        n = n * 10 + c - '0';
        c = getchar_unlocked();
		if( !ok ) k *= 10.;
		if( c == '.' ){  c = getchar_unlocked(); ok = false; }
		
    }
	n /= k;
    n = (neg ? (-n) : (n));
}


int main(){
	//ios::sync_with_stdio(false);
	double valor;
	int n, m, pos = 1, p1, p2, b1, b2;
	REP(i,25) REP(j,4) bicho[pos++] = i;
	bicho[0] = -1;
	readDouble(valor); readInt(n); readInt(m);
	while((valor + n + m)){
		n += 10000;
		m += 10000;
		sprintf(aposta, "%d", n);
		sprintf(sorteado, "%d", m);
		p1 = strlen(aposta) - 1; p2 = strlen(sorteado) - 1;
		b1 = aposta[p1]-'0';
		b1 += (aposta[p1-1]-'0')*10;
		b2 = sorteado[p2]-'0';
		b2 += (sorteado[p2-1]-'0')*10;
		if(aposta[p1] == sorteado[p2] && aposta[p1-1] == sorteado[p2-1] && aposta[p1-2] == sorteado[p2-2] && aposta[p1-3] == sorteado[p2-3])
			printf("%.2lf\n",3000.0*valor);
		else if(aposta[p1] == sorteado[p2] && aposta[p1-1] == sorteado[p2-1] && aposta[p1-2] == sorteado[p2-2])
			printf("%.2lf\n",500.0*valor);
		else if(aposta[p1] == sorteado[p2] && aposta[p1-1] == sorteado[p2-1])
			printf("%.2lf\n",50.0*valor);
		else if(bicho[b1] == bicho[b2])
			printf("%.2lf\n",16.0*valor);
		else
			printf("0.00\n");
		readDouble(valor); readInt(n); readInt(m);
	}

	return 0;
}


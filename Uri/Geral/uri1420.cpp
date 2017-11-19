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

struct calendario(){
	uint64 horas, dias, mes, ano, tot;
	calendario(uint64 horas, uint64 dias, uint64 mes, uint64 ano, uint64 tot ) : horas(horas), dias(dias), mes(mes), ano(ano), tot(tot) { } 
};

struct horas(){
	int h, m, s;
	horas(int h = 0, int m = 0, int s = 0 ) : h(h), m(m), s(s) { }
};

vector < calendario > vet;

bool ehBissexto(int ano){
	int quatro = (ano % 4);
	int quatrocento = (ano % 400);
	int cem = (ano % 100);
    if( !quatro )
        if( !cem )
            if( !quatrocento ) return true;
            else return false;
        else return true;
    else return false;
}

int mes[2][13] = {31, 28, 31, 30, 31, 30, 31, 31, 29, 31, 30, 29,
				  31, 29, 31, 30, 31, 30, 31, 31, 29, 31, 30, 29};

void process(){
	bool bi = false;
	uint64 ans = 0;
	int dia = 1;
	FOR(i,2001,2100){
		bi = ehBissexto(i);
		REP(j,12){
			REP(k,mes[bi][j]){
				vet.pb(calendario(0,dia,j,i,ans));
				ans += 86400;
				dia++;
			}
		}
	}
}

horas horasPorFavor(uint64 horas){
	horas ans;
	
	return ans;
}

int main(){
	
	return 0;
}

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
#include <ctype.h>
#include <sys/timeb.h>
using namespace std;
struct timeb ini, fim;
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define RFOR(i, b, a) for(int i = b; i >= a; --i)
#define REP(i, N) for(int i = 0; i < N; ++i)
#define RREP(i, N) for(int i = N-1; i >= 1; --i)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )
#define MAXN 10000
#define LINF 0x3F3F3F3FFFFFFFFFLL
#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) __typeof((X).begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) int((V).size())
const double INF = 1e50;
#define pb push_back
#define mk make_pair
double vet[1000];

typedef long long int64;
int a, b, t;
inline void read(int op) {
	a = 0;
	b = 0;
	register bool neg = false;
	register char c = getchar_unlocked();
	while ('0' <= c && c <= '9') {
		a = a * 10 + c - '0';
		c = getchar_unlocked();
	}
	if(op){ t = a; return; }
	c = getchar_unlocked();
	while ('0' <= c && c <= '9') {
		b = b * 10 + c - '0';
		c = getchar_unlocked();
	}
	a = (neg ? (-a) : (a));
}

int main(){
	while(true){
		read(1);
		if(!t) break;
		double media = 0.;
		REP(i,t){ 
			read(0);
			vet[i] = a*100.;
			vet[i] += b;
			vet[i] /= 100.;
			media += vet[i];
		}			
		media = ((int)((media * 100) / t)) / 100.0;
		double re = 0., pa = 0., d = 0.;
		REP(i,t){
			if(media >= vet[i]) re += media - vet[i];
			else pa += vet[i] - (media + 0.01);
		}
		if(pa > re ) printf("$%.2f\n", pa);
		else printf("$%.2f\n", re);
	}
	return 0;
}

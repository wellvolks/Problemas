#include <set>
//#include <tr1/unordered_map>
#include <map>
#include <list>
#include <stack>
#include <stdio.h>
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
typedef long long int64;
typedef unsigned long long uint64;
struct tri{
    int visit[5010], b;
	int64 sum;
	int atual, s;
	tri(int atual = 0, int b = 0, int *vi = NULL, int64 sum = 0, int s = 0) : atual(atual) , b(b), sum(sum), s(s) { 
		REP(i,s) visit[i] = vi[i];
	}
};

struct estado{
	int x, y, c;
	estado(int x = 0, int y = 0, int c = 0) : x(x), y(y), c(c) { }
};

int x[] = {-1,-1,-1, 0, 1, 1, 1, 0 };
int y[] = {-1, 0, 1, 1, 1, 0,-1,-1 };
#define getcx getchar_unlocked

inline void read( int &n ) {
	n = 0;
	register bool neg = false;
	register char c = getchar_unlocked();
    if( c == EOF){ n = -400; return; }
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
	register int v, t;
	while(true){
		read(v);
		if(v == -400) break;
		read(t);
		printf("%d\n",v*(t<<1));
	}
	return 0;
}

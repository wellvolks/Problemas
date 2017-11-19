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

int main() {
    ios::sync_with_stdio(false);
    register int N;
	readInt(N);
    while ( N ) {
        register double s0 = 0.0;
        register double v0 = 0.0;
        register double last = 0;
        register double a, b;
        for (int i = 0; i < N; ++i) {
			readDouble(a);
			readDouble(b);
            register double t = min(v0 / 2.0, a-last);
            s0 = s0  + v0 * t - t*t;
            v0 = v0 - 2.0*t;
            t = min(10.0 - v0, b-a);
            s0 = s0 + v0 * t + t * t / 2.0;
            v0 = v0 + t;
            register double rem = (b-a) - t;
            s0 = s0 + v0*rem;
            last = b;
        }
        printf("%.2lf\n",s0);
		readInt(N);
    }
    return 0;
}
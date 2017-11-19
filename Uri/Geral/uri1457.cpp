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
//#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFFLL
#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) __typeof((X).begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) int((V).size())
#define pb push_back
#define mp make_pair
const double INF = 1e50;
const double EPS = 1e-9;

typedef unsigned long long uint64;
struct tri{
	int atual, custo;
	tri ( int atual = 0, int custo = 0) : atual(atual), custo(custo) { }
};

int cmp(double a, double b = 0.0){
	if(fabs(a-b) < EPS) return 0;
	return a > b ? 1 : -1;
}

#ifdef _WIN32 
    #define getchar_unlocked getchar
#endif
 
inline void readInt( int &n, int &k, bool op ) {
    n = 0;
	k = 0;
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
	if( op ){
		while( c == '!' ){
			k++;
			c = getchar_unlocked();
		}
	}
}

uint64 memo[200][40];

uint64 solve(int n, int k){
	uint64 ans = n;
	int pos = 1;
	while((n - pos*k) > 1){
		ans *= (n - pos*k);
		pos++;
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	int t, n, k;
	readInt(t, k, false);
	while( t-- ){
		readInt(n,k, true);
		if( !memo[n][k] ) memo[n][k] = solve(n,k);
		printf("%lld\n",memo[n][k]);
	}
	return 0;
}
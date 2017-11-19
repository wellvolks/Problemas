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
#include <stdint.h>
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

 #ifdef _WIN32
    #define getchar_unlocked getchar
#endif

int n, m;
typedef vector < int > vi;
typedef vector < vi > vii;
typedef vector < tri > vtri;
typedef vector < vtri > vvtri;
typedef long long int64;
typedef unsigned long long uint64;

int s[500], b[500]; 

inline void read( int &n ) {
    n = 0;
    bool neg = false;
    char c = getchar_unlocked();
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

int used[1000], vis = 1;
vector < int > opa;
vector < int > ::iterator it;
int at;
int solve( int k ){
	if( opa.size() == m ) return 0;
	if( k  >= n ) return -2e9;
	int ans = -2e9;
	REP(i,m){
		int aa = -2e9;
		if( used[i] != vis ){
			it = upper_bound(ALL(opa),k%n);
			if( opa.size() >= 2 && it != opa.end() ) return -2e9;
			used[i] = vis;
			opa.pb(k%n);
			aa = solve( (k + 2) ) - (( s[k%n] + s[(k+1)%n] ) * b[i]);
			opa.erase(opa.begin()+opa.size()-1);
			used[i] = 0;
		}		
		ans = max(ans,aa);
	}
	return (max(ans,solve(k+1)));
}

int main(){
	ios::sync_with_stdio(false);
	while( true ){
		read( n ); read( m );
		if( !(n+m) ) break;
		REP(i, n) read( s[i] );
		REP(j, m) read( b[j] );
		int ans = -2e9;
		cout << solve( 0 ) << endl;
		vis++;
	}
	return 0;
}
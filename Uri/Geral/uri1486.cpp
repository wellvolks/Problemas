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

typedef vector < int > vi;
typedef vector < vi > vii;
typedef vector < tri > vtri;
typedef vector < vtri > vvtri;
typedef long long int64;
typedef unsigned long long uint64;
  
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

int mat[1010][1010];
int sum[1010];

int solve(int n, int m, int c){
	REP(i,n) sum[i] = 0;
	register int ans = 0;
	REP(i,n){
		REP(j,m ){
			register int &ac = mat[i][j];
			read(ac);
			register int &sm = sum[j];
			sm += ac;
			if( !ac || i+1 == n){
				if( sm >= c ){
					sm = ac;
					ans++;
				}
				else sm = 0;
			}
		} 
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	register int n, m, c;
	while( true ){	
		read(m); read(n); read(c);
		if( !(n+m+c) ) break;
		fprintf(stdout,"%d\n",solve(n,m,c));
	}
	return 0;
}
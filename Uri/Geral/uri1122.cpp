#include <map>
#include <tr1/unordered_map>
#include <set>
#include <deque>
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
#define REP(i, N) for(register int i = 0; i < N; ++i)
#define RREP(i, N) for(int i = N-1; i >= 1; --i)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )
#define MAXN 10000
#define INF 0x3F3F3F3
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
      
inline void read(  int &n ) {
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
      
struct tri{
    int x, y;
    tri ( int x = 0, int y = 0) : x(x), y(y) { }
};

      
int n, m;
typedef vector < int > vi;
typedef vector < vi > vii;
typedef vector < tri > vtri;
typedef vector < vtri > vvtri;
typedef long long int64;
typedef unsigned long long uint64;

int vet[1000];

tri res[1000];
int memo[41][90000], visit[41][90000], vis = 1;
char ans[100];

bool solve(int k, int sum){
	if ( k >= n ){  
		if( sum == m ){ 
			REP(i,k){
				if( ans[i] == '+' ) res[i].x ++;
				else res[i].y ++;
			}
			return true;
		}
		return false;
	}
	if( visit[k][sum+40000] == vis ){
		if( memo[k][sum+40000] ){
			REP(i,k){
				if( ans[i] == '+' ) res[i].x ++;
				else res[i].y ++;
			}
			return true;
		}
		return false;
	}
	ans[k] = '+';
	bool a = solve( k + 1, sum + vet[k] );
	ans[k] = '-';
	bool b = solve( k + 1, sum - vet[k] );
	visit[k][sum+40000] = vis;
	memo[k][sum+40000] = (a || b);
	return ( a || b );
}

char str[1000];

int main(){
	//ios::sync_with_stdio(false);
	while( true ){
		
		read(n); read(m);
		if( !(n+m) ) break;
		int v;
		
		REP(i,n){ str[i] = ' '; read(vet[i]); res[i] = tri(0,0); }
		
		if( solve(0,0) ){
			REP(i,n){
				if( res[i].x && !res[i].y ) str[i] = '+';
				else if( !res[i].x && res[i].y  ) str[i] = '-';
				else str[i] = '?';
			}
			str[n] = '\0';
			puts(str);
		}
		else puts("*");
		vis++;
	}
	return 0;
}
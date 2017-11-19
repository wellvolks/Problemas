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
#define MAXN 1006003
#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFFLL
#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) __typeof((X).begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) int((V).size())
#define pb push_back
#define mp make_pair
  
  
struct tri{
    int id;
	string at;
    tri ( int id = 0, string at = "") : id(id), at(at) { }
};
 
typedef vector < int > vi;
typedef vector < vi > vii;
typedef vector < tri > vtri;
typedef vector < vtri > vvtri;
typedef long long int64;
typedef unsigned long long uint64;

#ifdef _WIN32 
    #define getchar_unlocked getchar
#endif

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


int best[1010][1010], n;

int solve(){
	register int resp = 0;
	for(int i = 1; i <= n; i++){
		for(int j = i; j <= n; j++) best[j][i] += best[j-1][i-1];
		for(int k = n-1; k >= 1; k--) best[k][i] =  max(best[k][i],best[k+1][i]);
		resp = max(best[i][i],resp);
	}
	return resp;
}

int main(){
	while(true){
		read(n);
		if( !n ) break;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= i; j++){
				read(best[i][j]);
				best[i][j] += best[i-1][j];
			}		
		}
		fprintf(stdout,"%d\n",solve());
		REP(i,n+1) for( int j = i; j <= n; j++) best[i][j] = best[j][i] = 0;
	}
	return 0;
}

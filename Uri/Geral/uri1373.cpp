#include <set>
#include <tr1/unordered_map>
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
#define MAXN 5000603
#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFFLL
#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) __typeof((X).begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) int((V).size())
#define pb push_back
#define mp make_pair
 
 
struct tri{
    int atual, custo;
    tri ( int atual = 0, int custo = 0) : atual(atual), custo(custo) { }
};
 
struct aresta{
    int atual;
    string str;
    aresta( int atual = 0, string str = "" ) : atual(atual) , str(str) { }
};
 
typedef vector < int > vi;
typedef vector < vi > vii;
typedef vector < tri > vtri;
typedef vector < vtri > vvtri;
typedef long long int64;
typedef unsigned long long uint64;
 
int x[] = {-1,-1,-1, 0, 1, 1, 1, 0 };
int y[] = {-1, 0, 1, 1, 1, 0,-1,-1 };
 
#ifdef _WIN32 
    #define getchar_unlocked getchar
#endif

inline void read( int &n ) {
    n = 0;
    register bool neg = false;
    register char c = getchar_unlocked();
	while( c == '\n' ) c = getchar_unlocked();
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

int n;
char str1[1010], str2[1010];

int dp[1010][1010];
int mxc[1010][1010];


int solve(int x, int y){
	FOR(i,1,x){
		FOR(j,1,y){
			register int &d = dp[i][j];
			d = max(dp[i-1][j],dp[i][j-1]);
			if( str1[i-1] == str2[j-1] ) mxc[i][j] = mxc[i-1][j-1]+1;
			else mxc[i][j] = 0;
			if( mxc[i][j] >= n ){
				FOR(w,n,mxc[i][j]) d = max(d,dp[i-w][j-w]+w);
			}
		}
	}
	return dp[x][y];
}

int main(){
	ios::sync_with_stdio(false);
	read(n);
	while( n ){
		register int t1 = 0, t2 = 0;
		register char c = getchar_unlocked();
		while( isalpha(c) ){  str1[t1++] = c;  c = getchar_unlocked();  }
		while( !isalpha(c) ) c = getchar_unlocked();
		while( isalpha(c) ){  str2[t2++] = c;  c = getchar_unlocked();  }
		mxc[0][0] = 0;
		printf("%d\n",solve(t1,t2));
		read(n);
	}
	return 0;
}
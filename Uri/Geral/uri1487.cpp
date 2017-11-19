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
int k;
typedef vector < int > vi;
typedef vector < vi > vii;
typedef vector < tri > vtri;
typedef vector < vtri > vvtri;
typedef long long int64;
typedef unsigned long long uint64;
 
int dp[6000][7000], w[7000], v[7000];
 
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
 
 
int mochila (int n, int W){
     int a, b;
    for( int y = 0; y <= W; y++){
        dp[0][y] = 0;
        for( int i = 1; i <= n; i++){
            a = dp[i-1][y];
            if(w[i] > y) b = 0;
            else b = dp[i-1][y-w[i]] + v[i];
            dp[i][y] = max(a,b);
        }
    }
    return dp[n][W];
}
 
int main(){
     int s, n, t, c = 1;
    while(true ){
        read(n);
        read(s);
		if( !n && !s ) break;
		int k = 0;
			REP(i,n){ 
		  read(w[k+1]); 
		  read(v[k+1]);
		  if( w[k+1] ){
			int x = k+1;
			k++;
			REP(j,(s/w[x])-1){
			  w[k+1] = w[x];
			  v[k+1] = v[x];
			  k++;
			}
		  }
		}
		n = k;
		printf("Instancia %d\n%d\n\n",c++, mochila(n,s));
    }
    return 0;
}
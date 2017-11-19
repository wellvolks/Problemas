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
 
int n, m;
typedef vector < int > vi;
typedef vector < vi > vii;
typedef vector < tri > vtri;
typedef vector < vtri > vvtri;
typedef long long int64;
typedef unsigned long long uint64;
 
int x[] = {-1,-1,-1, 0, 1, 1, 1, 0 };
int y[] = {-1, 0, 1, 1, 1, 0,-1,-1 };
 
 struct pt{
	int x, y;
	bool k;
	pt( int x = 0, int y = 0, bool k = false) : x(x), y(y), k(k) { }
 };
 
pt vet[10010];
 
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

bool compare( const pt &a, const pt &b ){
    register int modA = a.y;
    register int modB = b.y;
    if( modA == modB ){
        register bool aa = (a.k), bb = (b.k);
        if( aa && bb ) return ( a.x > b.x );
        if( (aa && !bb) ) return true;
        if( (!aa && bb) ) return false;
        return ( a.x < b.x );
    }
    return ( modA < modB );
}
 
int main(){
	ios::sync_with_stdio(false);
	readInt(n); readInt(m);
    while((abs(n) + abs(m) )){
        REP(i,n){ readInt(vet[i].x); vet[i].y =  vet[i].x % m; vet[i].k = (vet[i].x & 1);  } 
        sort(vet, vet+n, compare);
        printf("%d %d\n",n,m);
        REP(i,n) printf("%d\n",vet[i].x);
		readInt(n); readInt(m);
    }
    printf("0 0\n");
    return 0;
}
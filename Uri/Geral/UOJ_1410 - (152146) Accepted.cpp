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
 
struct pos{
    int x, y;
    pos(int x = 0, int y = 0) : x(x), y(y) { }
};
 
struct estado{
    int xx, yy, mask, custo;
    estado(int xx = 0, int yy = 0, int mask = 0, int custo = 0) : 
    xx(xx), yy(yy), mask(mask), custo(custo) { }
    bool operator < (const estado& e) const{
        if(custo != e.custo) return custo > e.custo;
        return mask < e.mask;
    }
};
 
int k;
typedef vector < int > vi;
typedef vector < vi > vii;
typedef vector < tri > vtri;
typedef vector < vtri > vvtri;
typedef long long int64;
typedef unsigned long long uint64;
bool compare(const int a, const int b){
    return a > b;
}

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

int main(){
    register int a, d;
    int ta[100], tb[100];
    read(a); read(d);
    while((a+d)){
        REP(i,a) read(ta[i]);
        REP(i,d) read(tb[i]);
        sort(ta,ta+a);
        sort(tb,tb+d);
        register bool ans = false;
        REP(i,a) if(ta[i] < tb[1]){ ans = true; break; }
        if(ans) puts("Y");
        else puts("N");
	read(a); read(d);
    }
    return 0;
}
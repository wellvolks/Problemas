#include <map>
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

#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define RFOR(i, b, a) for(int i = b; i >= a; --i)
#define REP(i, N) for(int i = 0; i < N; ++i)
#define RREP(i, N) for(int i = N-1; i >= 1; --i)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )
#define MAXN 10000
#define LINF 0x3F3F3F3FFFFFFFFFLL
#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) __typeof((X).begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) int((V).size())
#define pb push_back
#define mk make_pair

struct tri{
	int used;
	double valor;
	tri ( int used = 0, double valor = 0.) : used(used), valor(valor) { }
};

struct par{
	int de, para;
	par(int de = 0, int para = 0) : de(de), para(para) { }
};

int n, m;
typedef vector < int > vi;
typedef vector < vi > vii;
typedef vector < tri > vtri;
typedef vector < vtri > vvtri;
typedef long long int64;
typedef unsigned long long uint64;
const  double pi = acos(-1.0);
const  double EPS = 1e-15;
const  double INF = 1e50;
int x[] = {-1,-1,-1, 0, 1, 1, 1, 0 };
int y[] = {-1, 0, 1, 1, 1, 0,-1,-1 };

int cmp(double a, double b = 0.0){ if(fabs(a-b) < EPS) return 0; return a > b ? 1 : -1; }


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

vector < multiset < double > > comprado;

int vis = 1;
vector < int > compra;
vector < pair < int, double > > sup;
int visit[100001][200];
double memo[100001][200];
bool opa = false;
int qt = 0;
double solve( int li, int s ){
	double *dp = &memo[s][li];
	if( s >= m ){
		return *dp = (( li >= n ) ? (0.) : ( 9999999.9 ));
	}
	if( li >= n ) return *dp = 0.;
	double ans = 9999999.;
	if( visit[s][li] == vis ) return *dp ;
	visit[s][li] = vis;
	if( sup[s].first == compra[li] ){
		ans = min(solve(li+1, s+1 ) + sup[s].second, solve(li, s+1 ));
	}
	else ans = solve(li,s+1);
	return *dp = ans;
}



int main(){
	ios::sync_with_stdio(false);
	int v;
	double p;
	multiset < double > :: iterator it;
	while( true ){
		readInt(n);
		readInt(m);
		if( !(n + m) ) break;
		int maiorId = 0;
		qt = 0;
		REP(i,n){
			readInt(v);
			compra.pb(v);
			maiorId = max(maiorId, v);
		}
		double ans = 0.;
		REP(i,m){
			readInt(v);
			readDouble(p);
			sup.pb(make_pair(v,p));
		}
		ans = solve(0,0);
		if (!(ans < 9999999.) ) puts("Impossible");
		else printf("%.2lf\n",ans);
		compra.clear();
		sup.clear();
		vis++;
		opa = false;
	}
	return 0;
}
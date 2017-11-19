#include <tr1/unordered_map>
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
using namespace tr1;

#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define RFOR(i, b, a) for(int i = b; i >= a; --i)
#define REP(i, N) for(int i = 0; i < N; ++i)
#define RREP(i, N) for(int i = N-1; i >= 0; --i)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )
#define MAXN 30000
#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFFLL
#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) __typeof((X).begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) int((V).size())
#define pb push_back
#define mp make_pair

const double EPS = 1e-9;

struct tri{
	double de, para;
	double dist;
	tri ( int de = 0, int para = 0, double dist = 0.) : de(de), para(para), dist(dist) { }
	bool operator < ( const tri &a ) const {
		return dist < a.dist;
	}
};


int n, m;
typedef vector < int > vi;
typedef vector < vi > vii;
typedef vector < tri > vtri;
typedef vector < vtri > vvtri;
typedef long long int64;
typedef unsigned long long uint64;
#define px second
#define py first
typedef pair< double, double > pt;


int x[] = {-1,-1,-1, 0, 1, 1, 1, 0 };
int y[] = {-1, 0, 1, 1, 1, 0,-1,-1 };

pt cord [MAXN];

int pa[MAXN], rk[MAXN], tCnt[MAXN];
//pai, rank, numero de nos na subarvore(se este no e o raiz)

void init(int n){
    REP(i, n){
		pa[i] = i;
		rk[i] = 0;
		tCnt[i] = 1;
    }
}

int find(int x){
    int a = x;
    while(pa[a] != a) a = pa[a];
    int b = x, c;
    while(pa[b] != a){
		c = pa[b];
		pa[b] = a;
		b = c;
    }    
    return a;
}

void uf(int x, int y){
    int ax = find(x);
    int ay = find(y);
    if(ax == ay) return;
    if(rk[ay] > rk[ax]) swap(ax, ay);
    if(rk[ax] == rk[ay]) rk[ax]++;
    pa[ay] = ax;
    tCnt[ax] += tCnt[ay];
}

double calcDist( pt a, pt b ){
	return sqrt((a.first - b.first)*(a.first - b.first) + (a.second - b.second)*(a.second - b.second)); 
}


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

int main(){
	int t, qt = 0;
	ios::sync_with_stdio(false);
	vector < tri > points;
	double dist;
	readInt(t);
	char str[1000];
	while( t ){
		REP(i,t) readDouble(cord[i].first), readDouble(cord[i].second); 
		points.clear();
		qt = 0;
		REP(i,t){
			FOR(j,i+1,t-1){
				dist = calcDist(cord[i],cord[j]);
				points.pb(tri(i,j,dist));
				points.pb(tri(j,i,dist));
				pa[i] = qt++;
				rk[i] = 0;
				tCnt[i] = 1;
			}
		}
		init(points.size());
		sort(ALL(points)); 
		double ans = 0.;
		FORIT(i,points){
			if( find(i->de) != find(i->para)){ 
				uf(i->de, i->para); 
				ans = max(ans,i->dist);
			}
		}
		printf("%.4lf\n",ans);
		readInt(t);
	}
	return 0;
}
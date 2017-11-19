#include <set>
#include <map>
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
#include <bitset>
 
using namespace std; 
 
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define RFOR(i, b, a) for(int i = b; i >= a; --i)
#define REP(i, N) for(int i = 0; i < N; ++i)
#define RREP(i, N) for(int i = N-1; i >= 0; --i)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )
#define MAXN 10000
#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFFLL
#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) __typeof((X).begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) int((V).size())
#define pb push_back
#define mp make_pair
 
struct tri{
    int ant, novo;
    tri ( int ant = 0, int novo = 0) : ant(ant), novo(novo) { }
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

inline void read( uint64 &n ) {
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

pair<uint64,int> t[4*MAXN];
uint64 valor; 
uint64 vet[4*MAXN];
int ans = 0;

pair<int64,int> combine (pair<int64,int> a, pair<int64,int> b) {
	if (a.first > b.first)
		return a;
	if (b.first > a.first)
		return b;
	return make_pair (a.first, a.second + b.second);
}
 
void build (int v, int tl, int tr) {
	if (tl == tr) t[v] = make_pair (vet[tl], 1);
	else {
		int tm = (tl + tr) >> 1;
		int v1 = v << 1;
		int v2 = v1 + 1;
		build (v1, tl, tm);
		build (v2, tm+1, tr);
		t[v] = combine (t[v1], t[v2]);
	}
}
 
pair<int64,int> get_max (int v, int tl, int tr, int l, int r) {
	if (l > r) return make_pair (-LINF, 0);
	if (l == tl && r == tr) return t[v];
	int tm = (tl + tr) >> 1;
	int v1 = v << 1;
	int v2 = v1 + 1;
	return combine (
		get_max (v1, tl, tm, l, min(r,tm)),
		get_max (v2, tm+1, tr, max(l,tm+1), r)
	);
}
 
void update (int v, int tl, int tr, int pos, uint64 new_val) {
	if (tl == tr) t[v] = make_pair (new_val, 1);
	else {
		int tm = (tl + tr) >> 1;
		int v1 = v << 1;
		int v2 = v1 + 1;
		if (pos <= tm) update (v1, tl, tm, pos, new_val);
		else update (v2, tm+1, tr, pos, new_val);
		t[v] = combine (t[v1], t[v2]);
	}
}


 int main(){
	uint64 n, m, u, a, b, c, d;
	read(n);
	read(m);
	read(u);
	REP(i,n) read(vet[i]);
	valor = LINF;
	build(1,0,n-1);
	REP(i,m){
		read(a); read(b); read(c); read(d);
		valor = c;
		get_max(1,0,(int)n-1,(int)a-1,(int)b-1);
		update(1,0,(int)n-1,(int)d-1,(u*ans)/(b-a+1));
		ans = 0;
	}
	valor = LINF;
	REP(i,n) printf("%lld\n",get_max(1,0,n-1,i,i).first);
	return 0;
 }
 
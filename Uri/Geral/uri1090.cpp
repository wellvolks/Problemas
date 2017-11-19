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
#include <map> 
using namespace std;
 
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
    int c1, c2, c3, q1, q2, q3, t1, t2, t3;
	tri( int c1 = 0, int c2 = 0, int c3 = 0, int q1 = 0, int q2 = 0, int q3 = 0, int t1 = 0, int t2 = 0, int t3 = 0 ) :
	c1(c1), c2(c2), c3(c3), q1(q1), q2(q2), q3(q3), t1(t1), t2(t2), t3(t3) { } 
	bool operator < ( const tri &a ) const {
		if( c1 != c2 ) return c1 < c2;
		if( c2 != c3 ) return c2 < c3;
		if( c3 != q1 ) return c3 < q1;
		if( q1 != q2 ) return q1 < q2;
		if( q2 != q3 ) return q2 < q3;
		if( t1 != t2 ) return t1 < t2;
		return t2 < t3;
	}
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

inline bool read( int &n ) {
    n = 0LL;
    register bool neg = false;
    register char c = getchar_unlocked();
	while( c == '\n' ) c = getchar_unlocked();
    if( c == EOF) { n = -1; return false; }
    while (!('0' <= c && c <= '9')) {
        if( c == '-' ) neg = true;
        c = getchar_unlocked();
    }
    while ('0' <= c && c <= '9') {
        n = n * 10 + c - '0';
        c = getchar_unlocked();
    }
    n = (neg ? (-n) : (n));
	return true;
}
int affs = 0;
set < vector < int > > eita;

int solve( tri at ){
	int t;
	vector < int > ans (15,0);
	if( eita.count(at) ) return 0;
	//eita[at]++;
	t = min(at.t1,min(at.q2,at.c3));
	if( t > 0 ) ans[0] = solve(tri(at.c1,at.c2,at.c3-t,at.q1,at.q2-t,at.q3,at.t1,at.t2,at.t3-t) ) + t;
	t = min(at.t1,min(at.c2,at.q3));
	if( t > 0 ) ans[1] = solve(tri(at.c1,at.c2-t,at.c3,at.q1,at.q2,at.q3-t,at.t1-t,at.t2,at.t3) ) + t;
	t = min(at.q1,min(at.c2,at.t3));
	if( t > 0 ) ans[2] = solve(tri(at.c1,at.c2-t,at.c3,at.q1-t,at.q2,at.q3,at.t1,at.t2,at.t3-t) ) + t;
	t = min(at.q1,min(at.t2,at.c3));
	if( t > 0 ) ans[3] = solve(tri(at.c1,at.c2,at.c3-t,at.q1-t,at.q2,at.q3,at.t1,at.t2-t,at.t3) ) + t;
	t = min(at.c1,min(at.t2,at.q3));
	if( t > 0 ) ans[4] = solve(tri(at.c1-t,at.c2,at.c3,at.q1,at.q2,at.q3-t,at.t1,at.t2-t,at.t3) ) + t;
	t = min(at.c1,min(at.q2,at.t3));
	if( t > 0 ) ans[5] = solve(tri(at.c1-t,at.c2,at.c3,at.q1,at.q2-t,at.q3,at.t1,at.t2,at.t3-t) ) + t;
	///cout << t << " " << at.c1 << " " << at.c1/3 << endl;
	t = at.c1/3;
	if( t > 0 ) ans[6] = solve(tri(at.c1-(t*3),at.c2,at.c3,at.q1,at.q2,at.q3,at.t1,at.t2,at.t3) ) + t;
	t = at.c2/3;
	if( t > 0 ) ans[7] = solve(tri(at.c1,at.c2-(t*3),at.c3,at.q1,at.q2,at.q3,at.t1,at.t2,at.t3) ) + t;
	t = at.c3/3;
	if( t > 0 ) ans[8] = solve(tri(at.c1,at.c2,at.c3-(t*3),at.q1,at.q2,at.q3,at.t1,at.t2,at.t3) ) + t;
	t = at.q1/3;
	if( t > 0 ) ans[9] = solve(tri(at.c1,at.c2,at.c3,at.q1-(t*3),at.q2,at.q3,at.t1,at.t2,at.t3) ) + t;
	t = at.q2/3;
	if( t > 0 ) ans[10] = solve(tri(at.c1,at.c2,at.c3,at.q1,at.q2-(t*3),at.q3,at.t1,at.t2,at.t3) ) + t;
	t = at.q3/3;
	if( t > 0 ) ans[11] = solve(tri(at.c1,at.c2,at.c3,at.q1,at.q2,at.q3-(t*3),at.t1,at.t2,at.t3) ) + t;
	t = at.t1/3;
	if( t > 0 ) ans[12] = solve(tri(at.c1,at.c2,at.c3,at.q1,at.q2,at.q3,at.t1-(t*3),at.t2,at.t3) ) + t;
	t = at.t2/3;
	if( t > 0 ) ans[13] = solve(tri(at.c1,at.c2,at.c3,at.q1,at.q2,at.q3,at.t1,at.t2-(t*3),at.t3) ) + t;
	t = at.t3/3;
	if( t > 0 ) ans[14] = solve(tri(at.c1,at.c2,at.c3,at.q1,at.q2,at.q3,at.t1,at.t2,at.t3-(t*3)) ) + t;
	sort(ALL(ans));
	//cout << ans[14] << endl;
	return ans[14];
}

int quad( tri &at );
int triang( tri &at );

int circ( tri &at ){
	int t = min(at.c1,min(at.c2,at.c3));
	at.c1 -= t; at.c2 -= t; at.c3 -= t;
	tri cp = at;
	int a = 0, b = 0;
	if( t >  0 ) a = quad(at) + solve(at);
	if( t > 0 )  b = triang(cp) + solve(cp);
	return max( t + a, t + b );
}

int quad( tri &at ){
	int t = min(at.q1,min(at.q2,at.q3));
	at.q1 -= t; at.q2 -= t; at.q3 -= t;
	tri cp = at;
	int a = 0, b = 0;
	if( t > 0 ) a = circ( at ) + solve( at );
	if( t > 0) b = triang(cp) + solve( cp );
	return max( t + a, t + b );
}

int triang( tri &at ){
	int t = min(at.t1,min(at.t2,at.t3));
	at.t1 -= t; at.t2 -= t; at.t3 -= t;
	tri cp = at;
	int a = 0, b = 0;
	if( t > 0 ) a = circ( at ) + solve( at );
	if( t > 0) b = quad( cp ) + solve( cp );
	return max( t + a, t + b );
}

int main(){
	ios::sync_with_stdio(false);
	int n;
	string str = "";
	while( cin >> n && n ){
		tri at ;
		cin.ignore();
		REP(i,n){
			getline(cin,str);
			if( str == "um circulo" ) at.c1++;
			else if( str == "dois circulos" ) at.c2++;
			else if( str == "tres circulos" ) at.c3++;
			else if( str == "um triangulo" ) at.t1++;
			else if( str == "dois triangulos" ) at.t2++;
			else if( str == "tres triangulos" ) at.t3++;
			else if( str == "um quadrado" ) at.q1++;
			else if( str == "dois quadrado") at.q2++;
			else at.q3++;
		}
		tri a, b, c, d, e ; a = b = c = d = e = at;
		//int ans = (max(circ(a)+quad(a)+triang(a),max(circ(b)+triang(b)+quad(b),max(triang(c)+quad(c)+circ(c),max(triang(d)+circ(d)+quad(d),quad(e)+circ(e)+triang(e))))));
		int ans = max(ans, solve(at));
		cout << ans << "\n";
		affs = 0;
		eita.clear();
	}
	return 0;
}
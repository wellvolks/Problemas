
#include <map>
#include <set>
#include <list>
#include <bitset>
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
#define MAX 1000010
#define INF 0x3f3f3f3f
#define LINF 0x3F3F3F3FFFFFFFFFLL
#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) __typeof((X).begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) int((V).size())
#define pb push_back
#define mp make_pair

typedef long long uint64;

#ifdef _WIN32
    #define getchar_unlocked getchar
#endif

struct pt{
	int x, y;
	pt( int x = 0, int y = 0 ) : x(x), y(y) { }
	bool operator == ( const pt &a ) const{
		return ( a.x == x && a.y == y );
	}
};

vector < string > aux;

struct tri{
	pt a, b, c;
	int d;
	tri(int d = 0, pt a = (0,0), pt b = (0,0), pt c = (0,0)) : d(d), a(a), b(b), c ( c ) { };
	bool operator < ( const tri &w ) const {
		return !( w.a == a && w.b == b && w.c == c );
	}
};
  

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

int n;
pt endA, endB, endC;

vector < string > grid;

int x[] = {-1,0,1,0};
int y[] = {0,1,0,-1};

int used[11][11][11][11][11][11], vis = 1;

bool check( pt a ){
	if( a.x >= 0 && a.x < n && a.y >= 0 && a.y < n && grid[a.x][a.y] != '#') return false;
	return true;
}

bool checkEnd( pt a, pt b, pt c ){
	if( (a == endA || a == endB || a == endC ) && 
		(b == endA || b == endB || b == endC ) &&
		(c == endA || c == endB || c == endC ) ){
		return true;
	}
	return false;
}

int bfs( pt a, pt b, pt c ){
	queue < tri > fila;
	vis++;
	fila.push(tri(0,a,b,c));
	tri at;
	while( !fila.empty() ){
		at = fila.front();
		fila.pop();
		//cout << at.a.x << " " << at.a.y << " " << at.b.x << " " << at.b.y << " " << at.c.x << " " << at.c.y << "\n";
		if( checkEnd(at.a,at.b,at.c) ) return at.d;
		if( used[at.a.x][at.a.y][at.b.x][at.b.y][at.c.x][at.c.y] == vis ) continue;
		used[at.a.x][at.a.y][at.b.x][at.b.y][at.c.x][at.c.y] = vis;
		REP(i,4){
			a = pt(at.a.x + x[i], at.a.y + y[i]);
			b = pt(at.b.x + x[i], at.b.y + y[i]);
			c = pt(at.c.x + x[i], at.c.y + y[i]);
			if( check(a) ) a = at.a;
			if( check(b) ) b = at.b;
			if( check(c) ) c = at.c;
			//if( a == b && b == c ) continue;
			REP(j,3){
				if( a == b ){
					pt bkp = a;
					a = at.a;
					if( a == bkp ){
						b = at.b;
						if( b == c ) c = at.c;
					}
					else if( a == c ){
						c = at.c;
						if( c == b ) b = at.b;
					}
				}
				if( b == c ){
					pt bkp = b;
					b = at.b;
					if( bkp == b ){
						c = at.c;
						if( c == a ) a = at.a;
					}
				}
				if ( a == c ){
					pt bkp = a;
					a = at.a;
					if( a == bkp ){
						c = at.c;
						if( c == b ) b = at.b;
					}
				}
			}
			fila.push( tri(at.d + 1, a, b, c) );
		}
	}
	return -1;
}

int main(){
	ios::sync_with_stdio(false);
	int t, k = 0, ak = -1,  w = 1;
	char c;
	cin >> t;
	while( t-- ){
		cin >> n;
		k = 0;
		grid.resize(n);
		pt startA, startB, startC;
		REP(i,n){
			grid[i] = "";
			REP(j,n){
				cin >> c;
				grid[i] += c;
				ak = k;
				k += ( c == 'X' ) ? ( 1 ) : ( 0 );
				if( k == 1 && ak < k ) endA = pt(i,j); 
				else if( k == 2 && ak < k ) endB = pt(i,j);
				else if( k == 3 && ak < k) endC = pt(i,j);
				if( c == 'A' ) startA = pt(i,j);
				else if( c == 'B' ) startB = pt(i,j);
				else if( c == 'C' ) startC = pt(i,j);
			}
			//cout << grid[i] << "\n";
		}
		//cout << endA.x << " " << endA.y << " " << endB.x << " " << endB.y << " " << endC.x << " " << endC.y << "\n";
		int ans = bfs( startA, startB, startC );
		cout << "Case " << w++ << ": ";
		if( ans < 0 ) cout << "trapped\n";
		else cout << ans << "\n";
		grid.clear();
	}
	return 0;
}
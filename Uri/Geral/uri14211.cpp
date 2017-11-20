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
    int x, y, b, dire;
    tri ( int x = 0, int y = 0, int b = 0, int dire = 0) : x(x), y(y), b(b), dire(dire) { }
};
 
int n, m;
typedef vector < int > vi;
typedef vector < vi > vii;
typedef vector < tri > vtri;
typedef vector < vtri > vvtri;
typedef long long int64;
typedef unsigned long long uint64;

#ifdef _WIN32 
    #define getchar_unlocked getchar
#endif

int xx[] = {-1,-1,-1, 0, 1, 1, 1, 0 };
int yy[] = {-1, 0, 1, 1, 1, 0,-1,-1 };

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

int mat[40][40][40];
int tam[1000][33][33], c = 0;
int at = 0;

int solve(int x, int y ){
	register int ans = 0, t = tam[c][x][y];
	REP(i,n){
		if( tam[c][x][i] >= t && mat[x][i][t-1] == at ) ans++;
		else break;
	}
	if( ans == n ) return at;
	ans = 0;
	REP(i,n){
		if( tam[c][i][y] >= t && mat[i][y][t-1] == at ) ans++;
		else break;
	}
	if( ans == n ) return at;
	ans = 0;
	if( x == y ){
		REP(i,n){
			if( tam[c][i][i] >= t && mat[i][i][t-1] == at ) ans++;
			else break;
		}
	}
	else if(  !(abs(x-(n-1)) - abs(y)) ){
		REP(i,n){
			if( tam[c][i][(n-1)-i] >= t && mat[i][(n-1)-i][t-1] == at ) ans++;
			else break;
		}
	}
	return (( ans == n ) ? at : -1);
}

int main(){
	read(n);
	register int x, y, caso = 1;
	while( n ){
		register int qt = n*n*n;
		register int ans = -1;
		c = caso-1;
		REP(w,qt){
			read(x); read(y);
			x--; y--;
			mat[x][y][tam[c][x][y]] = at;
			tam[c][x][y]++;
			register int ret = -1;
			if( ans == -1 ){ 
				ret = solve(x,y);
				if( ret != -1 ) ans = ret;
			}
			at = !at;
		}
		printf("Instancia %d\n",caso++);
		(ans == -1 ) ? puts("Empate\n") : (( ans == 0 ) ? puts("Azul ganhou\n") : puts("Branco ganhou\n")); 
		read(n);
	}
	return 0;
}

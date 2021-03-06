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

char str[100];
bool verifica(int valor){
	register int ans = 0;
	while( valor ){
		ans = valor;
		valor /= 10;
		if( ans - (valor*10) == 7 ) return true;
	}
	return false;
}
 
int solve(int n, int m, int k){
	register int ans = 0, w = m;
	register bool v = true;
	while( true ){
		if( (!(w % 7) || verifica(w)) ) ans++;
		if( ans == k ) return w;
		if( v && m == n ) w += (m<<1)-2; 
		else if( v || m == 1 ) w += ( (n - m)*2 );
		else w += (m<<1)-2; 
		//cout << w << " " << n << " " << m << "\n";
		v = !v;
	}
	return -1;
} 

 int main(){
	register int n, m, k;
	read(n); read(m); read(k);
	while((n+m+k)){
		if( n != 1 )
		fprintf(stdout,"%d\n",solve(n,m,k));
		read(n); read(m); read(k);
	}
	return 0;
 }
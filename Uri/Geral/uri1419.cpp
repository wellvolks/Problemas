#include <tr1/unordered_map>
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
using namespace tr1;
 
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
    int atual, tipo;
    tri ( int atual = 0, int tipo = 0) : atual(atual), tipo(tipo) { }
};
 
int n, m;
typedef vector < int > vi;
typedef vector < vi > vii;
typedef vector < tri > vtri;
typedef vector < vtri > vvtri;
typedef long long int64;
typedef unsigned long long uint64;

int veA, veB;

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
	register int t, v;
	vector < int > a, b;
	read(t);
	while( t ){
		a.clear();
		b.clear();
		REP(i,t){
			read(v);
			a.pb(v);
		}
		REP(i,t){
			read(v);
			b.pb(v);
		}
		bool ok = false;
		int aa=0, bb=0, antA, antB;
		veA = veB = 1;
		REP(i,t){
			aa += a[i];
			bb += b[i];
			if( !i ){ antA = a[i]; antB = b[i]; }
			else{
				if( antA == a[i] ) veA++;
				else veA = 1;
				if( antB == b[i] ) veB++;
				else veB = 1;
			}
			if( !ok ){
				if( veA == 3 && veB == 3 ){
					ok = true;
					veA = veB = 1;
				}
				else if( veA == 3 ){
					aa +=  30;
					ok = true;
				}
				else if( veB == 3 ){
					bb += 30;
					ok = true;
				}
			}
			antA = a[i]; 
			antB = b[i];
		}
		if( aa > bb ) puts("M");
		else if( bb > aa ) puts("L");
		else puts("T");
		read(t);
	}
	return 0;
}
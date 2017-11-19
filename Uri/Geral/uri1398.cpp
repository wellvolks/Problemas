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
 
struct estado{
	int id, apa;
	estado( int id = 0, int apa = 0 ) : id(id) , apa(apa) { }
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
char str[100000];
char number[] = "11111111111111111";

bool solve(int tam){ 
	string aux = "";
	REP(i,tam){
		int p = -1;
		bool ok = true;
		REP(j,17){
			str[i+j] = (( str[i+j] != number[j]) ? '1' : '0');
			if( str[i+j] == '1' && ok){ ok = false; p = i+j; }
		}
		//cout << str << "\n";
		if( p == -1 ){ for ( int k = i; k < tam; k++ ) if( str[k] == '1' ){ p = k; break; } }
		if( p == -1 ) return true;
		if( p == tam ) return true;
		if( p + 16 > tam ) return false;
		i = p - 1;
	}
	return false;
}

int main(){
	char c;
	while( gets(str) != NULL ){
		int tam = strlen(str);
		if( tam <= 2 ) puts("YES");
		else{
			if( tam < 17 ) puts("NO");
			else if( solve(tam-1) ) puts("YES");
			else puts("NO");
		}
	}
	return 0;
}
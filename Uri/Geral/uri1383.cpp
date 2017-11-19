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
uint64 linha[10], coluna[10], sub[4][4], pot[100];

void calcPot(){
	pot[0] = 1;
	pot[1] = 2;
	FOR(i,2,11) pot[i] = (pot[i-1] << 1);
}

int mat[10][10];

bool solve(){
	if( (sub[0][0] + sub[0][1] + sub[0][2] + sub[1][0] + sub[1][1] + sub[1][2] + sub[2][0] + sub[2][1] + sub[2][2]) != 4599 ) return false;
	return ((linha[0] + linha[1] + linha[2] + linha[3] + linha[4] + linha[5] + linha[6] + linha[7] + linha[8] +
	        coluna[0] + coluna[1] + coluna[2] + coluna[3] + coluna[4] + coluna[5] + coluna[6] + coluna[7] + coluna[8] ) == 9198 );
}

int main(){
	read(n);
	calcPot();
	register int caso = 1;
	while( n-- ){
		REP(i,10){ linha[i] = coluna[i] = 0; }
		register int w = 0, k = 0;
		memset(sub,0,sizeof(sub));
		bool opa = false;
		REP(i,9){
			k = 0;
			if( i == 3 || i == 6 ) w++; 
			REP(j,9){
				if( j == 3 || j == 6 ) k++;
				read(mat[i][j]);
				linha[i] ^= pot[mat[i][j]-1];
				coluna[j] ^= pot[mat[i][j]-1];
				sub[w][k] ^= pot[mat[i][j]-1];
				if( linha[i] > 511 || coluna[j] > 511 ) opa = true;
			}
		}
		printf("Instancia %d\n",caso++);
		(!opa && solve()) ? puts("SIM\n") : puts("NAO\n");
	}
	return 0;
}

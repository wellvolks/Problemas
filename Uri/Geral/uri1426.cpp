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
#define MAXN 100010 
#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFFLL
#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) __typeof((X).begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) int((V).size())
#define pb push_back
#define mp make_pair
 
#ifdef _WIN32 
    #define getchar_unlocked getchar
#endif
 
struct aresta{
    int atual, valor;
    aresta ( int atual = 0, int valor = 0) : atual(atual), valor(valor) { }
};
 
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
	register int t, v, k, w;
	register int mat[9][9];
	read(t);
	while( t-- ){
		k = w = 0;
		REP(i,5){
			w = 0;
			FOR(j,0,i){
				read(mat[k][w]);
				w+=2;
			}
			k+=2;
		}
		printf("%d\n",mat[0][0]);
		mat[2][1] = (mat[0][0] - (mat[2][0] + mat[2][2])) >> 1;
		mat[1][0] = (mat[2][0] + mat[2][1]);
		mat[1][1] = (mat[2][1] + mat[2][2]);
		mat[4][1] = (mat[2][0] - (mat[4][0] + mat[4][2])) >> 1;
		mat[4][3] = (mat[2][2] - (mat[4][2] + mat[4][4])) >> 1;
		mat[3][0] = (mat[4][0] + mat[4][1]);
		mat[3][1] = (mat[4][1] + mat[4][2]);
		mat[3][2] = (mat[4][2] + mat[4][3]);
		mat[3][3] = (mat[4][3] + mat[4][4]);
		mat[6][1] = (mat[4][0] - (mat[6][0] + mat[6][2])) >> 1;
		mat[6][3] = (mat[4][2] - (mat[6][2] + mat[6][4])) >> 1;
		mat[6][5] = (mat[4][4] - (mat[6][4] + mat[6][6])) >> 1;
		mat[5][0] = (mat[6][0] + mat[6][1]);
		mat[5][1] = (mat[6][1] + mat[6][2]);
		mat[5][2] = (mat[6][2] + mat[6][3]);
		mat[5][3] = (mat[6][3] + mat[6][4]);
		mat[5][4] = (mat[6][4] + mat[6][5]);
		mat[5][5] = (mat[6][5] + mat[6][6]);
		mat[8][1] = (mat[6][0] - (mat[8][0] + mat[8][2])) >> 1;
		mat[8][3] = (mat[6][2] - (mat[8][2] + mat[8][4])) >> 1;
		mat[8][5] = (mat[6][4] - (mat[8][4] + mat[8][6])) >> 1;
		mat[8][7] = (mat[6][6] - (mat[8][6] + mat[8][8])) >> 1;
		mat[7][0] = (mat[8][0] + mat[8][1]);
		mat[7][1] = (mat[8][1] + mat[8][2]);
		mat[7][2] = (mat[8][2] + mat[8][3]);
		mat[7][3] = (mat[8][3] + mat[8][4]);
		mat[7][4] = (mat[8][4] + mat[8][5]);
		mat[7][5] = (mat[8][5] + mat[8][6]);
		mat[7][6] = (mat[8][6] + mat[8][7]);
		mat[7][7] = (mat[8][7] + mat[8][8]);
		FOR(i,1,8){
			FOR(j,0,i){ if( j ) printf(" "); printf("%d",mat[i][j]); }
			puts("");
		}
	}
	return 0;
}
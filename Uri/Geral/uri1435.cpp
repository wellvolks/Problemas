#include <set>
//#include <tr1/unordered_map>
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

using namespace std;
//using namespace tr1;

#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define RFOR(i, b, a) for(int i = b; i >= a; --i)
#define REP(i, N) for(int i = 0; i < N; ++i)
#define RREP(i, N) for(int i = N-1; i >= 0; --i)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )
#define MAXN 10000
#define INF 0x3f3f3f3f
#define LINF 0x3F3F3F3FFFFFFFFFLL
#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) __typeof((X).begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) int((V).size())
#define pb push_back
#define mp make_pair

struct tri{
	int atual, custo, b;
	int filhos[3];
	tri ( int atual = 0, int custo = 0, int b = 0, int *f = NULL) : atual(atual), custo(custo), b(b) {
		filhos[0] = f[0]; filhos[1] = f[1]; filhos[2] = f[2];
	}
	bool operator < (const tri &a) const{
		return a.custo > custo;
	}
};

struct cord{
	int x, y, direcao;
	cord (int x = 0, int y = 0, int direcao = 0) : x(x), y(y), direcao(direcao) { }
};

int x[] = {-1,-1,-1, 0, 1, 1, 1, 0 };
int y[] = {-1, 0, 1, 1, 1, 0,-1,-1 };

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

int n;
int mat[1000][1000];

void solveA(int a, int k){
	register int b = a;
	while( a >= 0 && mat[b][a] == 0 ){  mat[b][a] = k; a--; }
	a = b - 1;
	while( a >= 0 && mat[a][b] == 0 ){  mat[a][b] = k; a--; }
}

void solveB(int a, int k){
	register int b = a;
	while( a < n && mat[b][a] == 0 ){  mat[b][a] = k; a++; }
	a = b + 1;
	while( a < n && mat[a][b] == 0 ){  mat[a][b] = k; a++; }
}

int main(){
	readInt(n);
	while( n ){
		REP(i,n) FOR(j, i, n-1) mat[i][j] = mat[j][i] = 0;
		for( register int i = 0, j = n-1; i <= j; i++, j-- ){
			solveB(i,i+1);
			solveA(j,i+1);
		}
		REP(i,n){
			REP(j,n){
				if( !j ) fprintf(stdout,"% 3d",mat[i][j]);
				else fprintf(stdout,"% 4d",mat[i][j]);
			}
			puts("");
		}
		readInt(n);
		puts("");
	}
	return 0;
}
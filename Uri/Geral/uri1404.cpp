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
#include <ctype.h>
#include <sys/timeb.h>
using namespace std;
struct timeb ini, fim;
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define RFOR(i, b, a) for(int i = b; i >= a; --i)
#define REP(i, N) for(int i = 0; i < N; ++i)
#define RREP(i, N) for(int i = N-1; i >= 1; --i)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )
#define MAXN 10000
#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFFLL
#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) __typeof((X).begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) int((V).size())

#define pb push_back
#define mk make_pair

struct tri{
	int atual, custo;
	tri ( int atual = 0, int custo = 0) : atual(atual), custo(custo) { }
};

struct cord{
	int x, y;
	cord(int x = 0, int y = 0) : x(x), y(y) { }
};

struct estado{
	cord pos, sizee;
	int comida;
	int mat[21][21];
	estado(cord pos = (0,0), cord sizee = 0) : pos(pos), sizee(sizee) { memset(mat,0,sizeof(mat)); }
};

int n, m;
typedef vector < int > vi;
typedef vector < vi > vii;
typedef vector < tri > vtri;
typedef vector < vtri > vvtri;
typedef long long int64;
typedef unsigned long long uint64;

int x[] = { -1,-1, 1, 1 };
int y[] = { -1, 1, 1,-1 };

int start[30][30], copia[30][30], visitado[21][21][21][21], viss = 1, ans = 0;
cord jogadas[400];

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


int solve(cord at, cord ant, int qt){
	cord c, d, e;
	ans = max(ans,qt);
	if(qt){
		if(visitado[ant.x][ant.y][at.x][at.y] >= ans) return 0;
		visitado[ant.x][ant.y][at.x][at.y] = qt;
	}
	REP(i,4){
		c.x = at.x + 2*x[i];
		c.y = at.y + 2*y[i];
		d.x = at.x + x[i];
		d.y = at.y + y[i];
		if(c.x >= 0 && c.x < n && c.y >= 0 && c.y < m && d.x >= 0 && d.x < n && d.y >= 0 && d.y < m){
			if(start[d.x][d.y] == 2 && start[c.x][c.y] == 0 && !(ant.x == c.x && ant.y == c.y)){
				start[d.x][d.y] = 0;
				solve(c, d, qt+1);
				start[d.x][d.y] = 2;
			}
		}
	}
}


int main(){
	//ftime(&ini);
	register int tam, peca, pos;
	register bool casa = true, flag;
	read(n); 
	read(m);
	while((n+m)){
		tam = ((n*m) >> 1) + 2;
		casa = true; flag = false;
		pos = 0;
		//REP(i,n) REP(j,m) start[i][j] = 0;
		REP(i,n){
			flag = !flag;
			casa = flag;
			REP(j,m){
				if(casa){ 
					read(start[i][j]);
					if(start[i][j] == 1){ jogadas[pos].x = i, jogadas[pos++].y = j;}
				}
				else start[i][j] = -1;
				casa = !casa; 
				copia[i][j] = start[i][j];
			}
		}
		cord st;
		st.x = -1; st.y = -1;
		REP(i,pos){ 
			start[jogadas[i].x][jogadas[i].y] = 0;
			solve(jogadas[i],jogadas[i],0);
			start[jogadas[i].x][jogadas[i].y] = 1;
			//REP(i,n) REP(j,m) start[i][j] = copia[i][j];
			FILL(visitado,0);
		}
		fprintf(stdout,"%d\n",ans);
		ans = 0;
		read(n); read(m);
	}
	 //ftime(&fim);
	//cout << "Tempo : "<< ((double) fim.time + ((double) fim.millitm * 0.001)) - ((double) ini.time + ((double) ini.millitm * 0.001)) << "\n";
	
	return 0;
}


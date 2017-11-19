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
#define MAXN 1006003
#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFFLL
#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) __typeof((X).begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) int((V).size())
#define pb push_back
#define mp make_pair
  
  
struct tri{
    int atual, custo;
    tri ( int atual = 0, int custo = 0) : atual(atual), custo(custo) { }
};
  
struct pt{
    int x, y;
    pt ( int x = 0, int y = 0 ) : x(x), y(y) { }
};
 
typedef vector < int > vi;
typedef vector < vi > vii;
typedef vector < tri > vtri;
typedef vector < vtri > vvtri;
typedef long long int64;
 #ifdef _WIN32 
    #define getchar_unlocked getchar
#endif
  
//int x[] = {-1,-1,-1, 0, 1, 1, 1, 0 };
//int y[] = {-1, 0, 1, 1, 1, 0,-1,-1 };
  
int bit[1010][1010];
int visit[1010][1010], vis = 1; 
int n, m;

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

int sum (int x, int y){
    register int result = 0;
    for (register int i = x; i >= 0; i = (i & (i+1)) - 1)
        for (register int j = y; j >= 0; j = (j & (j+1)) - 1){
			if( visit[i][j] != vis ) bit[i][j] = 0LL;
			visit[i][j] = vis;
			result += bit[i][j];
		}
    return result;
}

void update (int x, int y, int delta){
    for (int i = x; i <= n; i = (i | (i+1)))
        for (int j = y; j <= m; j = (j | (j+1))){
			if( visit[i][j] != vis ) bit[i][j] = 0LL;
			visit[i][j] = vis;
			bit[i][j] += delta;
		}
}
 
int cordCorrect( pt a, pt b ){
    register int x, y, w, z;
	x = max(a.x,b.x);
	y = max(a.y,b.y);
	w = min(a.x,b.x);
	z = min(a.y,b.y);
	return (sum(x,y) - ((sum(w-1,y) + sum(x,z-1)) - sum(w-1,z-1)));
}
 
 int main(){
    register int  q, p, x, y, c, z, w;
    register bool ok = false;
    while( true ){
		read(n); read(m); read(p);
		if( !(n + m + p) ) break;
        read(q);
		register char cc;
        while( q-- ){
			cc = getchar_unlocked();
			while( !( cc >= 'A' && cc <= 'Z' ) ) cc = getchar_unlocked();
            if( cc == 'A' ){
                read(c); read(x); read(y);
				if( p ) update(x+1,y+1,c);
            }
			else if( !p ) fprintf(stdout,"0\n");
            else{
                read(x); read(y); read(z); read(w);
				fprintf(stdout,"%d\n",cordCorrect(pt(x+1,y+1), pt(z+1,w+1) ) * p );
            }
        }
		fprintf(stdout,"\n");
		vis++;
    }
    return 0;
 }
#include <set>
#include <tr1/unordered_map>
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
#define MAXN 5000603
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
 
struct aresta{
    int atual;
    string str;
    aresta( int atual = 0, string str = "" ) : atual(atual) , str(str) { }
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
	while( c == '\n' ) c = getchar_unlocked();
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

int nr, nl, mate[110];
int visited[110], vis = 1;
int g[110][110], vv = 1;

int dfs(int i) {
	register int j; if (visited[i] == vis) return 0; visited[i] = vis;
	for (j=0; j < nr; j++) {
		if (g[i][j] == vv && (mate[j] == -1 || dfs(mate[j]))) {mate[j] = i; return 1;}
	}
	return 0;
}
int match() {
	register int i, ans = 0;
	REP(i,nr+1) mate[i] = -1;
	for (i=0; i < nl; i++) vis++, ans += dfs(i);
	return ans;
}

int getId( string str ){
	if( str == "XXL" ) return 0;
	if( str == "XL" ) return nr/6;
	if( str == "L" ) return (nr/6)*2;
	if( str == "M" ) return (nr/6)*3;
	if( str == "S" ) return (nr/6)*4;
	if( str == "XS" ) return (nr/6)*5;
}

int main(){
	ios::sync_with_stdio(false);
	register int t;
	read(t);
	while( t-- ){
		register int k;
		read(nr); read(nl);
		string de, para;
		REP(i,nl){
			de = ""; para = "";
			register char c = getchar_unlocked();
			while( isalpha(c) ){ de += c; c = getchar_unlocked(); }
			while( !isalpha(c) ) c = getchar_unlocked();
			while( isalpha(c) ){ para += c; c = getchar_unlocked(); }
			REP(j,nr/6){
				g[i][getId(de)+j] = vv;
				g[i][getId(para)+j] = vv;
			}
		}
		puts(((match() == nl) ? ("YES") : ("NO")));
		vv++;
	}
	return 0;
}
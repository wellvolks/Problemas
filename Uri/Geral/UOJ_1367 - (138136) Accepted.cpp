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

char str[10000];
int problema[30], visit[30], vis = 1;
int main(){
	register int t;
	while( true ){
		read(t);
		if( !t ) break;
		register char c, cc;
		register int ans = 0, qtd = 0,d = 0;
		memset(problema,0,sizeof(problema));
		while(t--){
			c = getchar_unlocked();
			read(d);
			cc = getchar_unlocked();
			while( !isalpha(cc) ) cc = getchar_unlocked();
			register int k = 0;
			while( isalpha(cc) ){
				str[k++] = cc;
				cc = getchar_unlocked();
			}
			str[k] = '\0';
			c -= 'A';
			if( visit[c] == vis ) continue;
			if( str[0] == 'c' ){
				ans += (problema[c]*20) + d;
				visit[c] = vis;
				qtd++;
			}
			else problema[c]++;
		}
		fprintf(stdout,"%d %d\n",qtd,ans);
		vis++;
	}
	return 0;

}
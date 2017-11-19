#include <set>
#include <tr1/unordered_map>
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
using namespace tr1;

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

char a[1000], b[1000], str[1000];

int main(){
//	ios::sync_with_stdio(false);
	int t, i = 0, cc = 1;
	scanf("%d",&t);
	char c;
	getchar();
	while( t-- ){
		gets(str);
		gets(a);
		gets(b);
		int win = -1;
		int ca = 0, cb = 0, pri = 0;
		while( str[i] != '\0' ){
			if( str[i] == a[i] ) ca++;
			if( str[i] == b[i] ) cb++;
			if( win == -1 ){
				if( str[i] != a[i] && str[i] == b[i] ) win = 2;
				else if( str[i] != b[i] && str[i] == a[i]) win = 1;
			}
			i++;
		}
		printf("Instancia %d\n",cc++);
		if( ca > cb ) puts("time 1");
		else if( ca < cb ) puts("time 2");
		else if( win != -1 ) printf("time %d\n",win);
		else puts("empate");
		puts("");
		i = 0;
	}
	return 0;
}
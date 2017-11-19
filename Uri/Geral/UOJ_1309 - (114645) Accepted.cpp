
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
	int ant, novo;
	tri ( int ant = 0, int novo = 0) : ant(ant), novo(novo) { }
};

int n, k;
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
 
char din[1000], cent[1000], ans[1000];

int main(){
	char cc;
	while( true ){
		cc = getchar_unlocked();
		if( cc == EOF || cc == -1) break;
		while( !(cc >= '0' && cc <= '9') ) cc = getchar_unlocked();
		int d = 0, c = 0;
		while( (cc >= '0' && cc <= '9') ){
			din[d++] = cc;
			cc = getchar_unlocked();
		}
		while( !(cc >= '0' && cc <= '9') ) cc = getchar_unlocked();
		while( (cc >= '0' && cc <= '9') ){
			cent[c++] = cc;
			cc = getchar_unlocked();
		}
		int k = 1, div = (d % 3);
		ans[0] = '$';
		if( !div ) div = 3;
		REP(i,d){
			if( !div ){ ans[k++] = ','; div = 3; }
			div--;
			ans[k++] = din[i];
		}
		ans[k] = '.';
		if( c == 1 ){ ans[k+1] = '0'; ans[k+2] = cent[0];  ans[k+3] = '\0'; }
		else{ ans[k+1] = cent[0]; ans[k+2] = cent[1];  ans[k+3] = '\0'; }
		puts(ans);
	}
	return 0;
}

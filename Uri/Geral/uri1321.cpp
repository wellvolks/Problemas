#include <map>
#include <set>
#include <deque>
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
#define RREP(i, N) for(int i = N-1; i >= 1; --i)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )
#define MAXN 10000
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

struct par{
	int de, para;
	par(int de = 0, int para = 0) : de(de), para(para) { }
};

int n, m;
typedef vector < int > vi;
typedef vector < vi > vii;
typedef vector < tri > vtri;
typedef vector < vtri > vvtri;
typedef long long int64;
typedef unsigned long long uint64;
const  double pi = acos(-1.0);
const  double EPS = 1e-15;
const  double INF = 1e50;
int x[] = {-1,-1,-1, 0, 1, 1, 1, 0 };
int y[] = {-1, 0, 1, 1, 1, 0,-1,-1 };

int cmp(double a, double b = 0.0){ if(fabs(a-b) < EPS) return 0; return a > b ? 1 : -1; }


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

vector < string > op;
int a[100], b[100], visit[100], vis = 1;

int check( int i, int j, int k ){
	b[2] = i;
	int ok = 0;
	ok += (b[op[j][0]-'0'] > a[op[k][0]-'0']);
	ok += (b[op[j][1]-'0'] > a[op[k][1]-'0']);
	ok += (b[op[j][2]-'0'] > a[op[k][2]-'0']);
	return ( ok >= 2 ) ? ( 1 ) : ( 0 ) ;
}

vector < int > poss;

int main(){
	ios::sync_with_stdio(false);
	string str = "012";
	do{
		op.pb(str);
	}while( next_permutation(ALL(str)) );
	while( true ){
		poss.clear();
		read(a[0]);
		read(a[1]);
		read(a[2]);
		read(b[0]);
		read(b[1]);
		if( !(a[0] + a[1] + a[2] + b[0] + b[1] ) ) break;
		visit[a[0]] = visit[a[1]] = visit[a[2]] = vis;
		visit[b[0]] = visit[b[1]] = vis;
		FOR(i,1,52) if( visit[i] != vis ) poss.pb(i);
		int ans = -1;
		int ok = 0;
		int lo = 0, hi = poss.size(), mid;
		while ( lo < hi ){
			mid = ( lo + hi ) >> 1;
			ok = 0;
			REP(j,6) REP(k,6) ok += check(poss[mid],j,k);
			if( ok == 36 ) hi = mid;
			else lo = mid+1;
		}
		vis++;
		if( lo >= poss.size() ) printf("-1\n");
		else printf("%d\n",poss[lo]);
	}
	return 0;
}
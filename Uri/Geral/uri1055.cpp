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

vector < int > vet;
int pos[10000], visit[10000], vis = 1;

int solve(int at, int qt){
	int p1, dif1 = -1;
	if( qt == n ) return 0;
	REP(i,n){
		if( visit[i] == vis || i == at) continue;
		if( abs(vet[at] - vet[i]) > dif1 ){
			dif1 = abs(vet[at] - vet[i]);
			p1 = i;
		}
	}
	int p2, dif2 = -1;
	if( dif1 != -1 ) visit[p1] = vis;
	REP(i,n){
		if( visit[i] == vis || i == at) continue;
		if( abs(vet[at] - vet[i]) > dif2 ){
			dif2 = abs(vet[at] - vet[i]);
			p1 = i;
		}
	}
	if( dif1 == -1 && dif2 == -1 ) return 0;
	if( dif1 == -1 && dif2 == -1 ){ 
		visit[p1] = vis;
		int a = (dif1 + solve(p1,qt+1));
		visit[p1] = 0;
		int b = (dif2 + solve(p2,qt+1));
		visit[p2] = vis;
		if( a > b ) visit[p2] = 0;
		else if( a <= b ) visit[p1] = 0;
		return max(a,b);
	}
	else if( dif1 != -1 ){
		visit[p1] = vis;
		return (dif1 + solve(p1,qt+1));
	}
	visit[p2] = vis;
	return (dif2 + solve(p2,qt+1));
}

int main(){
	int q, v;
	read(q);
	while( q-- ){
		read(n);
		REP(i,n){
			read(v);
			vet.pb(v);
		}
		//sort(ALL(vet));
		int ans = 0;
		REP(i,n){
			visit[i] = vis;
			ans = max(ans,solve(i,0));
			vis++;
		}
		printf("%d\n",ans);
		vet.clear();
		vis++;
	}
	return 0;
}
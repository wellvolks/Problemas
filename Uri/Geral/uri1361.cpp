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
	int used;
	double valor;
	tri ( int used = 0, double valor = 0.) : used(used), valor(valor) { }
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
#define INF 99999999
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

vector < int > cA, cB;

bool comp( const int &a, const int &b){
	return a > b;
}

int getPosA( int i, int tam, int val ){
	if( i < 0 ) return -1;
	int k = -1;
	for( ; i < tam; i++ ) if(  cA[i] < val ) return i;
	return k;
}

int getPosB( int i, int tam, int val ){
	if( i < 0 ) return -1;
	int k = -1;
	for( ; i < tam; i++ ) if( cB[i] < val ) return i;
	return k;
}

int main(){
	ios::sync_with_stdio(false);
	int t, andar, tamAndar;
	read(t);
	while( t-- ){
		read(n);
		REP(i,n){
			read(andar);
			if( andar >= 0 ) cA.pb(andar);
			else cB.pb(-andar);
		}
		sort(ALL(cB),comp);
		sort(ALL(cA),comp);
		int a = 0, b = 0;
		andar = 0;
		if( !cA.size() || !cB.size() ) puts((!cA.size() && !cB.size()) ? "0" : "1");
		else{
			int ans = 1;
			if( cA[0] > cB[0] ){
				andar = 1;
				a++;
				if( b >= cA.size() ) a = -1;
				tamAndar = cA[0];
			}
			else{
				andar = 0;
				b++;
				if( b >= cB.size() ) b = -1;
				tamAndar = cB[0];
			}
			while( a != -1 && b != -1 ){
				if( andar ){
					b = getPosB(b,cB.size(),tamAndar);
					if( b != -1 ){
						tamAndar = cB[b];
						ans++;
						b++;
						if( b >= cB.size() ) b = -1;
					}
					else a = -1;
				}
				else{
					a = getPosA(a,cA.size(),tamAndar);
					if( a != -1 ){
						tamAndar = cA[a];
						ans++;
						a++;
						if( a >= cA.size() ) a = -1;
					}
					else b = -1;
				}
				andar = !andar;
			}
			if( andar ){
				b = getPosB(b,cB.size(),tamAndar);
				if( b != -1 ){
					tamAndar = cB[b];
					ans++;
					b++;
				}
			}
			else{
				a = getPosA(a,cA.size(),tamAndar);
				if( a != -1 ){
					tamAndar = cA[a];
					ans++;
					a++;
				}
			}
			printf("%d\n",ans);
		}
		cA.clear();
		cB.clear();
	}
	return 0;
}

#include <tr1/unordered_map>
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
using namespace tr1;
  
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
    int atual, tipo;
    tri ( int atual = 0, int tipo = 0) : atual(atual), tipo(tipo) { }
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
 
int64 digit_count(int digit, int64 number){
	if( number <= 0) return 0;
	if( number == 1 ) return 1; 
	int64 ans = 0;
	char str[150];
	int64 count = 0;
	ans += number/2 + ((number % 2) >= digit ? 1 : 0);
	if(digit == 0) ans--;
	ans += digit_count(digit, number/2 - 1) * 2;
	for( int i = 0; i <= 63; i++ ) count += ( (number>>1LL) & (1LL << i) ) ? (1) : (0);
	ans += (1 + number%2) * count;
	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	uint64 vA, vB;
	while( cin >> vA >> vB ){
		cout << (digit_count(1, vB) - digit_count(1, vA-1)) << "\n";
	}
	return 0;
}

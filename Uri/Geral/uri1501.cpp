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
  
unsigned long long digit_count(long long digit, long long number){
    if( number <= 1 && digit == 0 || number <= 0) return 0; 
    unsigned long long ans = 0;
    char str[15];
    register long long count = 0;
    ans += number/2 + ((number % 2) >= digit ? 1 : 0);
    if(digit == 0) ans--;
    ans += digit_count(digit, number/2 - 1) * 2;
    sprintf(str, "%lld", number/2);
    for( int i = 0; str[i] != '\0'; i++ ) count += ( str[i] == digit + '0' ) ? (1) : (0);
    ans += (1 + number%2) * count;
    return ans;
}
 
int main(){
    register int vA, vB;
    read(vA);
    read(vB);
    while( vA + vB ){
        REP(i,10){ if( i ) printf(" "); printf("%lld",digit_count(i, vB) - digit_count(i, vA-1)); }
        printf("\n");
        read(vA);
        read(vB);
    }
    return 0;
}
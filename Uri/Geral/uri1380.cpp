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
#define RREP(i, N) for(int i = N-1; i >= 1; --i)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )
#define MAXN 10000
#define INF 0x3F3F3F3F
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
 
int k;
typedef vector < int > vi;
typedef vector < vi > vii;
typedef vector < tri > vtri;
typedef vector < vtri > vvtri;
typedef long long int64;
typedef unsigned long long uint64;
 
int x[] = {-1,-1,-1, 0, 1, 1, 1, 0 };
int y[] = {-1, 0, 1, 1, 1, 0,-1,-1 };
char str[1000010];
uint64 fibo[2000];
 
void fibonacci(){
    uint64 f, f1, f2;
    fibo[0] = 0;
    fibo[1] = fibo[2] = 1;
    f1 = f2 = 1;
    FOR(i,3,1600){
        if( f1 + f2 >= 1000 ) f = (f1 + f2) % 1000;
		else f = (f1+f2);
        fibo[i] = f; f1 = f2; f2 = f;
    }
}

#ifdef _WIN32 
    #define getchar_unlocked getchar
#endif
 
inline void read( uint64 &n ) {
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

int main(){
    register uint64 t, tamanho, ans;
    read(t);
    fibonacci();
    while(t--){
        gets(str);
		tamanho = strlen(str);
        ans = 0;
        if ( tamanho == 1 ) ans = str[0]-48;
        for ( register int i = tamanho-1, j = 0; i >= 1; --i, ++j ){
            if ( i == tamanho-1 ) ans = (str[j]-48)*10 + (str[j+1]-48);
            else{
				ans = ((ans)*10);
				if( ans >= 1500 ) ans %= 1500;
				ans += (str[j+1]-48);
			}
        }
        ans = fibo[ans];
        printf("%03lld\n",ans);
    }
    return 0;
}
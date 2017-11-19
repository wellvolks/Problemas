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
#define REP(i, N) for(register int i = 0; i < N; ++i)
#define RREP(i, N) for(int i = N-1; i >= 1; --i)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )
#define MAXN 10000
#define INF 0x3F3F3F3
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
           
inline void read(  int &n ) {
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
           
struct tri{
    int atual;
    int custo;
    tri ( int atual = 0, int custo = 0LL) : atual(atual), custo(custo) { }
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
     
     
int vet[1001110], vis = 1;
     
vector < int > sz;
     
int bfs( int szCubo ){
    queue< pair<int,pair < int, int > > >cubo;
    REP(i,(int)sz.size()) cubo.push(mp(0,mp(sz[i],i) ));  
    int k = 0, ans = 2e9;
    while(!cubo.empty()){
        register int atual = cubo.front().second.first;
        register int aux = cubo.front().second.first;
        register int b = cubo.front().first;
        register int c = cubo.front().second.second;
        cubo.pop();
        if(atual == szCubo ) return b+1;
        FOR(i,c,n-1) {
            atual = sz[i] + aux;
            if((atual <= szCubo) && (vet[atual] != vis)   ){
                vet[atual] = vis;
                if(atual == szCubo) return b+2; 
                cubo.push(mp( (b + 1), mp(atual,i)));
            }
        }
    }
    return ans;
}

int dp[1000100];
 int szCubo;
int solve(){ 
    REP(i,szCubo+1) dp[i] = 2e9;
    dp[0]=0;
    for( int i=0;i <= szCubo;i++){
        for( int j=0;j<n;j++){
            if(i>=sz[j]){
                if(dp[i-sz[j]]+1<dp[i]) dp[i] = dp[i-sz[j]]+1;
            }
        }
    }
    return dp[szCubo];
 }
 
int main(){
    int t;
    read( t );
         
    while( t-- ){
        int m = 0;
        read(n);
        read(szCubo);
        int re = 0;
        for(int i = 0; i < n; i++ ){
            read(m);
            if( vet[m] == vis ) continue;
            sz.pb(m);
            vet[m] = vis;
        }
		n = sz.size();
        sort(ALL(sz),greater<int>());
        int at =  sz[0] * 250, r = 0;
		if( at < szCubo ){
			r = szCubo/at;
			r *= 250;
			szCubo %= at; 
		}
		//printf("%d\n",bfs(szCubo)+r);
        printf("%d\n",solve()+r);
		vis++;
        sz.clear();
    }
    return 0;
}
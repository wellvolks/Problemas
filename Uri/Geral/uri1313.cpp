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
#define getchar_unlocked getchar
typedef vector < int > vi;
typedef vector < vi > vii;
typedef vector < tri > vtri;
typedef vector < vtri > vvtri;
typedef long long int64;
typedef unsigned long long uint64;
  
int x[] = {-1,-1,-1, 0, 1, 1, 1, 0 };
int y[] = {-1, 0, 1, 1, 1, 0,-1,-1 };
  
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
  
int trie[MAXN][26], folha[MAXN], vis = 1, vp = 3, used[MAXN][26], vis2 = 1;
 
void update( int v, const char *s ){
   
    for(int i = 0; s[i] != '\0'; i++){
        //cout << s[i];
        int &p = trie[v][s[i] - 'a'];
        if( used[v][s[i]-'a'] != vis ) (p = vp++);
        used[v][s[i] - 'a'] = vis2;
        v = p;
    }
    //cout << "\n";
}
  
long long qtd[3][300];
int k = 0;
uint64 dfs(int u, int flag, int tr){
    uint64 ans = 0LL;
    //cout << k++ << " " << u << endl;
    REP(i,26){
        if( used[u][i] == vis2 ){
            if( flag ) qtd[tr][i]++;
            ans += dfs(trie[u][i], true, tr) + 1;
        }
    }
    return ans;
}
  
char palavra[MAXN];
  
int main(){
    ios::sync_with_stdio(false);
    int t, q, n;
    int trie1 = 1, trie2 = 2;
    while( scanf("%d %d",&n,&q) && n ){    
        int j = 0;
        vp = 3;
        k = 0;
        REP(i,3) REP(j,300) qtd[i][j] = 0;
        getchar();
        char cc;
        REP(i,n){   
            gets(palavra);
           // puts(palavra);
            update(trie1, palavra);
        }
         
        REP(i,q){   
            gets(palavra);
            reverse(palavra, palavra+strlen(palavra));
            //puts(palavra);
            update(trie2, palavra);
        }
         
        uint64 ans = dfs(trie1, false, trie1 ) * dfs(trie2, false, trie2 );
         
        REP(i,26) ans -= (qtd[1][i] * qtd[2][i]);
         
        printf("%lld\n",ans);
       
        vis++; vis2++;
    }
    return 0;
}
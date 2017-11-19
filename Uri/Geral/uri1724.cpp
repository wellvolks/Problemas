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
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )
#define MAXN 1200001
#define LINF 0x3F3F3F3FFFFFFFFFLL
#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) __typeof((X).begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) int((V).size())

#define pb push_back
#define mk make_pair
const double pi = acos(-1.0);
const double EPS = 1e-9;

typedef long long int64;
typedef unsigned long long uint64;

struct tri{
    int a, b, c, q, l;
    tri( int a = 0, int b = 0, int c = 0, int q = 0, int l = 0 ) :
    a(a), b(b), c(c), q(q), l(l) { }
};

char grafo[51][51];
int used[51][51][51][27], n, vis2 = 1;

int bfs( int a, int b, int c ){
    queue < tri > fila;
    fila.push(tri(a,b,c,0,26));
    while( !fila.empty() ){
        tri at = fila.front();
        fila.pop();
        if( at.a == at.b && at.b == at.c ) return at.q;
        used[at.a][at.b][at.c][at.l] = vis2;
        a = grafo[at.b][at.c];
        REP(i,n){
            if( grafo[at.a][i] == grafo[at.b][at.c] && used[i][at.b][at.c][grafo[at.a][i]] != vis2 ) 
                fila.push(tri(i,at.b,at.c,at.q+1,grafo[at.a][i]));
            if( grafo[at.b][i] == grafo[at.a][at.c] && used[at.a][i][at.c][grafo[at.b][i]] != vis2 ) 
                fila.push(tri(at.a,i,at.c,at.q+1,grafo[at.b][i]));
            if( grafo[at.c][i] == grafo[at.b][at.a] && used[at.a][at.b][i][grafo[at.c][i]] != vis2 ) 
                fila.push(tri(at.a,at.b,i,at.q+1,grafo[at.c][i]));
        }
    }
  return -1;
}

int main(){
    ios::sync_with_stdio(false);
    int a, b, c;
    char val;
    while( cin >> n && n ){
        cin >> a >> b >> c;
        a--; b--; c--;
        REP(i,n){
            REP(j,n){
                cin >> val;
                grafo[i][j] = val-'a';
                grafo[j][i] = val-'a';
            }
       }
       int ans = bfs(a,b,c);
       if( ans != -1 ) cout << ans << "\n";
       else cout << "impossible\n";
       vis2++;
    }
    return 0;
}
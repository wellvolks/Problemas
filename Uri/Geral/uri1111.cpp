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
#define MAXN 1010
#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFFLL
#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) __typeof((X).begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) int((V).size())
#define pb push_back
#define mk make_pair
  
struct tri{
    int x, y, b;
    tri (int x = 0, int y = 0, int b = 0) : x(x), y(y), b(b) { }
    bool operator == (const tri &a) const{
        return (a.x == x && a.y == y);
    }
};
  
typedef vector < int > vi;
typedef vector < vi > vii;
typedef vector < tri > vtri;
typedef vector < vtri > vvtri;
typedef long long int64;
typedef unsigned long long uint64;
int t;
int x[] = { 1,-1,0 ,0 };
int y[] = { 0 ,0,-1,1 };
  
int mat[101][101], grid[101][11], visited[101], vis1 = 1, vis2 = 1;
char str[10000];
  
void processa( int n ){
    int p = 0;
    REP(i,n) REP(j,n) grid[i][j] = p++;
}
vii grafo;
  
int bfs(int de, int para){
    queue < pair < int, int > > fila;
    pair < int, int > at;
    fila.push(mk(de,0));
    while(!fila.empty()){
        at = fila.front();
        fila.pop();
        if(at.first == para) return at.second;
        if(visited[at.first] == vis2) continue;
        visited[at.first] = vis2;
        REP(i,SIZE(grafo[at.first])){
            fila.push(mk(grafo[at.first][i],at.second+1));
        }
    }
    return -1;
}
  
int main(){
    while(scanf("%d",&t) && t ){
        grafo.resize(111);
        processa(t);
        getchar();
        for(int i = t-1; i >= 0; i--){
            gets(str);
            register int p = 0;
            REP(j,t){
                REP(k,4){
                    register  int a = x[k] + i;
                    register  int b = y[k] + j;
                    if(a >= 0 && a < t && b >= 0 && b < t && str[p] == '1') grafo[grid[i][j]].pb(grid[a][b]);
                    p += 2;
                }
            }
        }
        register  int qt;
        tri de, para;
        scanf("%d",&qt);
        getchar();
        while(qt--){
            gets(str);
            de.y = str[0] - '0';
            de.x = str[2] - '0';
            para.y = str[4] - '0';
            para.x = str[6] - '0';
            register  int ret = bfs(grid[de.x][de.y],grid[para.x][para.y]);
            if(ret == -1) printf("Impossible\n");
            else printf("%d\n",ret);
            vis2++;
        }
        vis1++;
        printf("\n");
        grafo.clear();
    }
    return 0;
}
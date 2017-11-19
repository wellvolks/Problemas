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
 
#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFFLL
#define MAXN 20
#define Atype char
#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) __typeof((X).begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) int((V).size())
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define RFOR(i, b, a) for(int i = b; i >= a; --i)
#define REP(i, N) for(int i = 0; i < N; ++i)
#define RREP(i, N) for(int i = N-1; i >= 0; --i)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )
 
#define PB push_back
#define MP make_pair
 
typedef long long int64;
typedef unsigned long long uint64;
 
using namespace std;
struct pos{
    int x, y;
    pos(int x = 0, int y = 0) : x(x), y(y) { }
};
 
int cax[] = { 2, 1, -1, -2, -2, -1,  1,  2 };
int cay[] = { 1, 2,  2,  1, -1, -2, -2, -1 };
int pey[] = {-1, 1};
int pex[] = {-1,-1};
 
int mat[10][10], vis = 1;
 
char mover[5];
pos cavalo;
 
int solve(){
    int ans = 0;
    pos c;
    REP(i,8){
        c.x = cax[i] + cavalo.x;
        c.y = cay[i] + cavalo.y;
        if(c.x >= 0 && c.x <  8 && c.y >= 0 && c.y < 8 && mat[c.x][c.y] != vis) ans++;
    }
    return ans;
}
 
int cord[400];
 
int main(){
    cord['a'] = 0; cord['b'] = 1; cord['c'] = 2; cord['d'] = 3; 
    cord['e'] = 4; cord['f'] = 5; cord['g'] = 6; cord['h'] = 7;
    pos peao;
    int caso = 1;
    while(gets(mover) && mover[0] != '0'){
        cavalo.x = mover[0] - '0' - 1;
        cavalo.y = cord[mover[1]];
        pos c;
        REP(i,8){
            gets(mover);
            peao.x = mover[0] - '0' - 1;
            peao.y = cord[mover[1]];
            REP(j,2){
                c.x = pex[j] + peao.x;
                c.y = pey[j] + peao.y;
                if(c.x >= 0 && c.x <  8 && c.y >= 0 && c.y < 8) mat[c.x][c.y] = vis;                
            }
        }
        printf("Caso de Teste #%d: %d movimento(s).\n",caso++, solve());
        vis++;
    }
    return 0;
}
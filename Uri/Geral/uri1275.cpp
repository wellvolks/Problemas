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
#define MAXN 1000000
#define LINF 0x3F3F3F3FFFFFFFFFLL
#define INF 0x3F3F3F3
#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) __typeof((X).begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) int((V).size())
#define pb push_back
#define mk make_pair
  
struct tri{
    int x, y;
    int at;
    tri ( int x = 0, int y = 0, int at = 0) : x(x), y(y), at(at) { }
};
  
struct par{
    int x, y, d;
    par(int x = 0, int y = 0, int d = 0) : x(x), y(y), d(d) { }
};
  
typedef long long int64;
typedef unsigned long long uint64;
const  double pi = acos(-1.0);
const  double EPS = 1e-15;

int x[] = {-1,1,0,0,-1,1, -1, 1};
int y[] = {0,0,-1,1,-1,1, 1, -1};
  
int cmp(double a, double b = 0.0){ if(fabs(a-b) < EPS) return 0; return a > b ? 1 : -1; }
  
  
#ifdef _WIN32 
    #define getchar_unlocked getchar
#endif
   
bool read( int &n ) {
    n = 0;
    register bool neg = false;
    register char c = getchar_unlocked();
    if( c == EOF) { n = -1; return false; }
    while (!('0' <= c && c <= '9')) {
        if( c == '-' ) neg = true;
        c = getchar_unlocked();
    }
    while ('0' <= c && c <= '9') {
        n = n * 10 + c - '0';
        c = getchar_unlocked();
    }
    n = (neg ? (-n) : (n));
    return true;
}

int n, m, b, lo, hi, k, t2;

int barreira[10][10], tem[10][10], ans, vis = 1;
par lim[10][10][4];
int mat[10][10], light[10][10], vis2 = 1;
vector < par > pos, bar;
int qtd = 0;
int tam = 0;

bool checkDire(int xx, int yy, int w){
    while( xx >= 0 && xx < n && yy >= 0 && yy < m ){
        if( light[xx][yy] == vis2 ) return false;
        if( tem[xx][yy] == vis ) return true;
        xx += x[w];
        yy += y[w];
    }
    return true;
}
 
bool checkPossible( par at ){
    REP(i,4) 
        if( !checkDire(at.x,at.y,i) ) 
            return false;
    return true;
}

bool checkAns(){
    REP(i,n){
        REP(j,m){
            if( tem[i][j] == vis && barreira[i][j] != -1){
                int adj = 0;
                REP(w,4){
                    int xx = i + x[w];
                    int yy = j + y[w];
                    if( xx < 0 || xx >= n || yy < 0 || yy >= m || tem[xx][yy] == vis ) continue;
                    adj += (( light[xx][yy] == vis2 ) ? (1) : (0));
                }
                if( adj != barreira[i][j] ) return false;
            }
            else if( !mat[i][j] && tem[i][j] != vis ) return false;
        }
    }
    return true;
}

void lightUp(par at, int sum){
    light[at.x][at.y] = ((sum > 0) ? ( vis2 ) : ( 0 ));
    mat[at.x][at.y] += sum;
    qtd += sum;
    REP(i,4){
        int xx = at.x + x[i];
        int yy = at.y + y[i];
        while( xx >= 0 && xx < n && yy >= 0 && yy < m ){
            mat[xx][yy] += sum;
            if(tem[xx][yy] == vis) break;
            if(sum > 0 && mat[xx][yy] == 1) qtd++;
            else if( sum < 0 && mat[xx][yy] == 0 ) qtd--;
            xx += x[i];
            yy += y[i];
        }
    }
}


void solve(int p, int qt){
    if( qt >= ans ) return ;
    if(p >= tam && checkAns()){  ans = min(ans,qt); tam = 0; return; }
    if( p >= tam ) return ;
    solve(p+1,qt);
    if( mat[pos[p].x][pos[p].y] || light[pos[p].x][pos[p].y] == vis2 || tem[pos[p].x][pos[p].y] == vis || !checkPossible(pos[p]) ) return ;
    lightUp(pos[p],1);
    light[pos[p].x][pos[p].y] = vis2;
    solve(p+1,qt+1);
    light[pos[p].x][pos[p].y] = 0;
    lightUp(pos[p],-1);
}

int main(){
    ios::sync_with_stdio(false);
    srand(time(NULL));
    while( true ){
        read(n);
        read(m);
        if( !(n+m) ) break;
        read(b);
        REP(i,b){
            read(lo); read(hi); read(k);
            lo--; hi--;
            tem[lo][hi] = vis;
            barreira[lo][hi] = k;
        }
        REP(i,n) REP(j,m){ 
            mat[i][j] = mat[i+1][j+1] = 0;
            if( tem[i][j] != vis ) pos.pb(par(i,j)); 
            else if( barreira[i][j] != -1 ) bar.pb(par(i,j));
        }
        tam = pos.size(); t2 = bar.size();
        ans = INF;
        if( tam ) solve(0,0);
        else ans = 0;
        if(ans < INF) cout << ans << "\n";
        else cout << "No solution\n";
        pos.clear();
        bar.clear();
        vis++; vis2++;
        qtd = 0;
    }
    return 0;
}
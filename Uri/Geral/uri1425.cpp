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
    int atual, custo;
    tri ( int atual = 0, int custo = 0) : atual(atual), custo(custo) { }
};
 
struct par{
    int de, para;
    par(int de = 0, int para = 0) : de(de), para(para) { }
};
 
typedef vector < int > vi;
typedef vector < vi > vii;
typedef vector < tri > vtri;
typedef vector < vtri > vvtri;
typedef long long int64;
typedef unsigned long long uint64;
const  double pi = acos(-1.0);
const  double EPS = 1e-15;
const  double INF = 1e50;
int x[] = {-1,-1,-1, 0, 1, 1, 1, 0 };
int y[] = {-1, 0, 1, 1, 1, 0,-1,-1 };
 
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

int n, m;

void solve(){
    queue < pair <int, int> >  fila;
    fila.push(mk(2,1));
    pair < int, int > at;
    if( n > 55 ){ puts("Let me try!"); return; }
    while( !fila.empty() ){
        at = fila.front();
        fila.pop(); 
        if( at.second < 1 || at.second > n ) continue;
        if( at.second == m){ puts("Let me try!"); return; }
        int k = ((at.first)<<1)-1;
        k = at.second + k;
        fila.push(make_pair(at.first + 1, k));
        k = ((at.first)<<1)-1;
        k = at.second - k;
        fila.push(make_pair(at.first + 1, k));
    }
    puts("Don't make fun of me!");
}

int main(){
    ios::sync_with_stdio(false);
    while( read(n) && read(m) && ( n + m )) solve();
    return 0;
}
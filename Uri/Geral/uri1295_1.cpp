#include <tr1/unordered_map>
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
    int atual, custo;
    tri ( int atual = 0, int custo = 0) : atual(atual), custo(custo) { }
};
 
 
int n, m;
typedef vector < int > vi;
typedef vector < vi > vii;
typedef vector < tri > vtri;
typedef vector < vtri > vvtri;
typedef long long int64;
typedef unsigned long long uint64;
#define px second
#define py first
typedef pair< double, double > pt;
 
 
int x[] = {-1,-1,-1, 0, 1, 1, 1, 0 };
int y[] = {-1, 0, 1, 1, 1, 0,-1,-1 };
/*
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
*/
 
pt cord [100000];
set< pt > box;
set< pt > :: iterator it;
 
int compx(pt a, pt b) { return a.px < b.px; }
 
int main () {
    double ans;
    while( scanf("%d", &n) && n ){
        REP(i,n) scanf("%lf %lf", &cord[i].px, &cord[i].py);
        sort(cord, cord + n, compx);
        ans = LINF; 
        box.insert(cord[0]);
        int left = 0;
        FOR(i,1,n-1){
            while (left<i && cord[i].px-cord[left].px > ans) box.erase(cord[left++]);
            for( it = box.lower_bound(make_pair(cord[i].py-ans, cord[i].px-ans)); it != box.end() && cord[i].py+ans>=it->py; it++)
                ans = min(ans, sqrt(pow(cord[i].py - it->py, 2.0)+pow(cord[i].px - it->px, 2.0)));
            box.insert(cord[i]);
        }
        (ans > 10000.) ? printf("INFINITY\n") : printf("%.4lf\n", ans);
        box.clear();
    }
    return 0;
}

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
 
int n, p;
vector < stack < int > > pilhas;
pair < int, int > one;
 
int solveLeft(){
    int ans = 0;
    if( p == 1 ) return (pilhas[one.first].size()-one.second) - 1;
    RFOR(j,one.first-1,0){
        if( pilhas[j].size() <= one.second ) break;
        while( !pilhas[j].empty() && pilhas[j].size() > one.second ){
            ans++;
            pilhas[j].pop();
        }
    }
    return ans + (pilhas[one.first].size()-one.second) - 1;
}
 
int solveRight(){
    int ans = 0;
    if( p == 1 ) return (pilhas[one.first].size()-one.second) - 1;
    FOR(j,one.first+1,p-1){
        if( pilhas[j].size() <= one.second ) break;
        while( !pilhas[j].empty() && pilhas[j].size() > one.second ){
            ans++;
            pilhas[j].pop();
        }
    }
    return ans + (pilhas[one.first].size()-one.second) - 1;
}
 
int main(){
    ios::sync_with_stdio(false);
    int q, v;
    while( read(n) && read(p) && ( n + p ) ){
        pilhas.resize(p);
        REP(i,p){
            read(q);
            REP(j,q){
                read(v);
                if( v == 1 ) one = mk(i,j);
                pilhas[i].push(v);
            }
        }
        cout << min(solveLeft(),solveRight()) << "\n";
        pilhas.clear();
    }
    return 0;
}
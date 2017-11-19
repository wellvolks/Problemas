//#include <tr1/unordered_map>
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
//using namespace tr1;
   
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define RFOR(i, b, a) for(int i = b; i >= a; --i)
#define REP(i, N) for(int i = 0; i < N; ++i)
#define RREP(i, N) for(int i = N-1; i >= 0; --i)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )
#define MAXN 10000
#define INF 0x3F3F3F3
#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) __typeof((X).begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) int((V).size())
#define pb push_back
#define mp make_pair
 
 
typedef long long int64;
typedef unsigned long long uint64;
 
const double EPS = 1e-9;
double k, n, m;
double r;
vector < double > aux;
 
int main(){
    ios::sync_with_stdio(false);
    while(cin >> k >> r && (k+r) > EPS){
        REP(i,k){
            cin >> n >> m;
            aux.pb(n);
        }
        sort(ALL(aux));
        int lo = 0, ans = 1;
        REP(i,k){
            double div = r * aux[lo];
            if( aux[i] > div ){
                ans++; 
                lo = i;
            }
        }
        cout << ans << "\n";
        aux.clear();
    }
    return 0;
}
#include <map>
#include <tr1/unordered_set>
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
using namespace tr1;
  
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define RFOR(i, b, a) for(int i = b; i >= a; --i)
#define REP(i, N) for(int i = 0; i < N; ++i)
#define RREP(i, N) for(int i = N-1; i >= 1; --i)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )
#define MAXN 10000
#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFFLL
#define FILL(X, V, T, P) memset( X, V, T * sizeof(P) )
#define TI(X) __typeof((X).begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) int((V).size())
#define mp make_pair
#define pb push_back
 
const double pi = acos(-1.0);
const double EPS = 1e-9;
  
int cmp(double a, double b){
    if(fabs(a-b) < EPS) return 0;
    return a > b ? 1 : -1;
}
 
char str[100010];
 #ifdef _WIN32 
    #define getchar_unlocked getchar
#endif
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
 
struct tri{
    int x, y, z;
    int mask;
    tri(int x = 0, int y = 0, int z = 0, int mask = 0 ) : x(x), y(y), z(z), mask(mask) { }
    bool operator < ( const tri &a ) const {
        if( a.z != z ) return true;
		if( a.x != x ) return true;
        if( a.y != y ) return true;
        
        return false;
    }
};
 
struct apt{
	int v;
	short u;
};
int n;
 
vector < vector < tri > > dim;
vector < vector < int > > pos;
int pot[16];
apt memo[32769][16][5];
int vis = 1;
bool opa = false;
 
int solve(int mask, int p, int k){
	apt &res = memo[mask][p][k];
    if( __builtin_popcount(mask) >= n ){
		res.u = vis;
        return  res.v = 0;
    }
    int ans = 0;
    if(  res.u == vis   ) return res.v;
	res.u = vis;
	REP(j,n){
        if( (mask & pot[j]) ) continue;
		int tam = dim[j].size();
        REP(i,tam){
            if( !mask || (dim[j][i].x <= dim[p][k].x && dim[j][i].z <= dim[p][k].z) ){
                ans = max(ans,solve(mask | pot[j], j, i ) + dim[j][i].y);
            }
        }
    }
    return res.v = ans;
}
 
int vet[4];

int main(){
    int t;
    ios::sync_with_stdio(false);
    cin >> t;
    pos.resize(7);
    string rot = "012";
    int k = 0;
    REP(i,16) pot[i] = (1 << i);
	
    set < tri > pt;
	
    while( t-- ){
        cin >> n;
        dim.resize(n);
        REP(i,n){
            cin >> vet[0] >> vet[1] >> vet[2];
         
			sort(vet,vet+3);
 
			pt.insert(tri(vet[0],vet[1],vet[2]));
			pt.insert(tri(vet[1],vet[0],vet[2]));
			pt.insert(tri(vet[0],vet[2],vet[1]));
			pt.insert(tri(vet[2],vet[0],vet[1]));
						
            FORIT(j,pt){
               dim[i].pb(*j);
            }
            pt.clear();
        }
		printf("%d\n",solve(0, 0, 0));
        dim.clear();
        vis++;
        opa = false;
    }
    return 0;   
}

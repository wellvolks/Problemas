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
	char pilha[9][9];
	int ans;
	tri( int ans = 0, char pp[9][9] = new char[9][9] ) :  ans(ans) { 
		REP(i,9) REP(j,9) pilha[i][j] = pp[i][j];
	}
};
  
int cmp(long double a, long double b = 0.0){
	if(fabs(a-b) < EPS) return 0;
	return a > b ? 1 : -1;
}

int ans = 0;
int mat[12][12];
int memo[12][12][2], vis = 1;
int n, m;

/*
void solve(int x, int y ){
	if( y >= m ){ x++; y = 0; }
	if( x >= n && !y ){
		REP(i,n){
			REP(j,m){
				if( !mat[i][j] ) return;
			}
		}
		ans++;
		return;
	}
	if( mat[x][y] ){ solve(x,y+1); return; }
	if( y+1 < m && !(mat[x][y+1]) && memo[x][y][0] != vis ){
		mat[x][y] = mat[x][y+1] = 1; 
		memo[x][y][0] = vis;
		solve(x,y+2);
		mat[x][y] = mat[x][y+1] = 0; 
		memo[x][y][0] = 0;
	} 
	if( x+1 < n && !(mat[x+1][y]) && memo[x][y][1] != vis ){
		memo[x][y][1] = vis;
		mat[x][y] = mat[x+1][y] = 1; 
		solve(x,y+1);
		mat[x][y] = mat[x+1][y] = 0; 
		memo[x][y][1] = 0;
	}
	//solve(x,y+1);
}
*/
long double solve( long double n, long double m ){
	long double ans = 1.;
	for( long double i = 1; cmp(i,ceil(n/2.)) <= 0; i++ ){
		long double sum = 1.;
		for( long double j = 1; cmp(j,ceil(m/2.)) <= 0; j++ ){
			sum *= (4.*(cos((pi*i)/(n+1))*cos((pi*i)/(n+1)))) + (4.*(cos((pi*j)/(m+1))*cos((pi*j)/(m+1))));
		}
		ans *= sum;
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	while( cin >> n >> m && (n+m) ){
		cout << uint64(solve(n,m)) << "\n";
	}
    return 0;
}

#include <list>
#include <set>
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
#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFFLL
#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) __typeof((X).begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) int((V).size())
#define pb push_back
#define mp make_pair
 
typedef  long long int64;

int mat[110][110];

int main(){
	ios::sync_with_stdio(false);
	int n;
	while( cin >> n && n ){
		REP(i,n){
			int k = 1;
			FOR(j,i,n-1) mat[i][j] = k++;
			k = 1;
			FOR(w,i,n-1) mat[w][i] = k++;
		}
		REP(i,n){
			printf("%*d",3,mat[i][0]);
			FOR(j,1,n-1){
				printf(" %*d",3,mat[i][j]);
			}
			puts("");
		}
		puts("");
	}
	return 0;
}
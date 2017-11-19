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
#define MAXN 1006003
#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFFLL
#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) __typeof((X).begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) int((V).size())
#define pb push_back
#define mp make_pair
  
  
struct tri{
    int qtd, pts, id, insc, sofrido;
	tri( int qtd = 0, int pts = 0, int id = 0, int insc = 0, int sofrido = 0) : qtd(qtd) , pts(pts), id(id), insc(insc), sofrido(sofrido) { }
};
 
typedef vector < int > vi;
typedef vector < vi > vii;
typedef vector < tri > vtri;
typedef vector < vtri > vvtri;
typedef long long int64;
typedef unsigned long long uint64;


int main(){
	register double h, g = 9.80665, PI = 3.14159, a, v,vv, ans, r, dr;
	register double compY, compX;
	register int t, p1, p2;
	while ( scanf("%lf",&h) != EOF ){
		scanf("%d %d",&p1,&p2);
		scanf("%d",&t);
		while( t-- ){
			scanf("%lf %lf",&a,&v);
			r = ((a*PI)/180.);
			dr = sin(r);
			vv = v*v;
			ans = ((vv) * (dr + sqrt((dr*dr) + ((2*g*h)/vv))) * cos(r))/g;
			printf("%.5lf%s",ans,((ans < (double)p1 || ans > (double)p2 ) ? " -> NUCK\n" : " -> DUCK\n"));
		}
	}
	return 0;
}
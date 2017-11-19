#include <set>
//#include <tr1/unordered_map>
#include <map>
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
const double EPS = 1e-9;
const double INF = 1e50;

struct pt{
	double x, y;
	
	pt(double x = 0.0, double y = 0.0) : x(x), y(y) {}
	
	double length() { return sqrt(x*x + y*y); }
	double length2() { return x*x + y*y; }
	
	pt normalize(){ return (*this)/length(); }
	
	pt operator - (pt p){ return pt(x - p.x, y - p.y); }
	pt operator + (pt p){ return pt(x + p.x, y + p.y); }
	pt operator * (double k){ return pt(x * k, y * k); }
	pt operator / (double k){ return pt(x / k, y / k); }
	bool operator < (const pt& p) const{
		if(fabs( x - p.x ) >= EPS) return x < p.x;
		return y < p.y;
	}
	bool operator == (const pt p){
		return ( fabs(x - p.x) < EPS && fabs(y - p.y) < EPS );
	}
};

int cmp(double a, double b = 0.0){ if(fabs(a-b) < EPS) return 0; return a > b ? 1 : -1; }
double dist(pt a, pt b){ return (a - b).length(); }
double dot(pt a, pt b){ return a.x*b.x + a.y*b.y; }
double cross(pt a, pt b){ return a.x*b.y - a.y*b.x; }
double signed_area(pt a, pt b, pt c){ return cross((a-c),(b-c))*0.5; }
bool colinear(pt a, pt b, pt c){ return !cmp(signed_area(a, b, c)); }

bool intersect(pt a, pt b, pt c, pt d, pt& inter){
	double det = cross(b-a, d-c);
	if(fabs(det) < EPS){
		if( fabs(signed_area(a, b, c) ) < EPS){
			inter = pt(INF, INF); 
			return true; //retas coincidentes
		}
		return false; //retas paralelas
	}
	//retas concorrentes
	double ua = ( cross(d-c, a-c) )/det; //parametros (pode ser importante)
//  double ub = ( cross(b-a, a-c) )/det;
	inter = a + (b-a)*ua;
	return true;
}

double triangle_area(pt a, pt b, pt c){
	return fabs(signed_area(a, b, c));
}

pt ccenter(pt a, pt b, pt c){
	//if( !cmp(triangle_area(a, b, c)) ) return false; 
	pt r1 = (b + c)*0.5;
	pt r2 = (a + c)*0.5;
	pt s1(r1.x - (c.y - b.y), r1.y + (c.x - b.x));
	pt s2(r2.x - (c.y - a.y), r2.y + (c.x - a.x));
	pt cc;
	
	intersect(r1, s1, r2, s2, cc);
	return cc;
}

pt cord[150];

pt centros[150];
int cp = 0;

int main(){
	register int t, ans;
	while(scanf("%d",&t) && t){
		ans = 2;
		REP(i,t) scanf("%lf %lf",&cord[i].x,&cord[i].y);
		REP(i,t){
			FOR(j,i+1,t-1){
				cp = 0;
				FOR(k,j+1,t-1) if(!colinear(cord[i],cord[j],cord[k])) centros[cp++] = ccenter(cord[i],cord[j],cord[k]);
				sort(centros,centros + cp);
				register int  qt;
				REP(w,cp){
					qt = 0;
					while( (qt + w) < cp && centros[qt + w] == centros[w]) ++qt;
					ans = max(ans, qt + 2);
					w += qt-1;
				}
			}
		}
		fprintf(stdout,"%d\n",ans);
		cp = 0;
	}
	return 0;
}


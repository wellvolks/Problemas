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
#define MAXN 10000
#define LINF 0x3F3F3F3FFFFFFFFFLL
#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) __typeof((X).begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) int((V).size())
#define pb push_back
#define mp make_pair
#define pair < int, int > pii;

struct tri{
	int atual, custo;
	tri ( int atual = 0, int custo = 0) : atual(atual), custo(custo) { }
};

struct player{
	int pos, id;
	player(int pos = 0, int id = 0) : pos(pos), id(id) { }
};

typedef vector < int > vi;
typedef vector < vi > vii;
typedef vector < tri > vtri;
typedef vector < vtri > vvtri;
typedef long long int64;
typedef unsigned long long uint64;

int x[] = {-1,-1,-1, 0, 1, 1, 1, 0 };
int y[] = {-1, 0, 1, 1, 1, 0,-1,-1 };

const double pi = acos(-1.0);
const double EPS = 1e-9;
const double INF = 1e50;

int cmpD(double a, double b = 0.0) { return a+EPS < b ? -1 : a-EPS > b; }

struct Point {
	double x, y, z;
	Point(double a=0.0,double b=0.0,double c=0.0){x=a,y=b,z=c;}
	Point operator+(const Point &P) const {return Point(x+P.x,y+P.y,z+P.z);}
	Point operator-(const Point &P) const {return Point(x-P.x,y-P.y,z-P.z);}
	Point operator*(double c) const {return Point(x*c,y*c,z*c);}
	Point operator/(double c) const {return Point(x/c,y/c,z/c);}
	double operator!() const {return sqrt(x*x+y*y+z*z);}
};
double dot(Point A, Point B) { return A.x*B.x + A.y*B.y + A.z*B.z; }
	Point cross(Point A, Point B) {
	return Point(A.y*B.z-A.z*B.y, A.z*B.x-A.x*B.z, A.x*B.y-A.y*B.x);
}

Point project(Point W, Point V) { return V * dot(W,V) / dot(V,V); }
	// do the segments A-B and C-D intersect? (assumes coplanar)
	bool seg_intersect(Point A, Point B, Point C, Point D) {
	return cmpD(dot(cross(A-B,C-B),cross(A-B,D-B))) <= 0 &&
	cmpD(dot(cross(C-D,A-D),cross(C-D,B-D))) <= 0;
}

double dist_Point_seg(Point P, Point A, Point B) {
	Point PP = A + project(P-A,B-A);
	if (cmpD(!(A-PP)+!(PP-B),!(A-B)) == 0) return !(P-PP);//distance Point-line!
	return min(!(P-A),!(P-B));
}

double dist_seg_seg(Point A, Point B, Point C, Point D) {
	Point E = project(A-D,cross(B-A,D-C)); // distance between lines!
	if (seg_intersect(A,B,C+E,D+E)) return !E;
	return min( min( dist_Point_seg(A,C,D), dist_Point_seg(B,C,D) ),
	min( dist_Point_seg(C,A,B), dist_Point_seg(D,A,B) ) );
}

double dist_Point_tri(Point P, Point A, Point B, Point C) {
	Point N = cross(A-C,B-C);
	Point PP = P + project(C-P,N);
	Point V1 = cross(PP-A,B-A);
	Point V2 = cross(PP-B,C-B);
	Point V3 = cross(PP-C,A-C);
	if (cmpD(dot(V1,V2)) >= 0 && cmpD(dot(V1,V3)) >= 0 && cmpD(dot(V2,V3)) >= 0)
	return !(PP-P); // distance Point-plane!
	return min(dist_Point_seg(P,A,B),min(dist_Point_seg(P,A,C),dist_Point_seg(P,B,C)));
}

double dist_tet_tet(Point T1[4], Point T2[4]) {
	double ans = INF;
	for (int i=0; i < 4; i++) // arestas -> arestas
		for (int j=i+1; j < 4; j++)
			for (int ii=0; ii < 4; ii++)
				for (int jj=ii+1; jj < 4; jj++)
					ans = min( ans, dist_seg_seg(T1[i],T1[j],T2[ii],T2[jj]) );
	// pontos -> planos
	for (int i=0; i < 4; i++)
		for (int j=i+1; j < 4; j++)
			for (int k=j+1; k < 4; k++)
				for (int x=0; x < 4; x++)
					ans = min( ans, dist_Point_tri(T1[x],T2[i],T2[j],T2[k]) ),
					ans = min( ans, dist_Point_tri(T2[x],T1[i],T1[j],T1[k]) );
	return ans;
}

int main(){
	//ios::sync_with_stdio(false);
	int t;
	Point tetra1[5], tetra2[5];
	scanf("%d",&t);//cin >> t;
	while(t--){
		REP(i,4) scanf("%lf %lf %lf", &tetra1[i].x, &tetra1[i].y, &tetra1[i].z);//cin >> tetra1[i].x >> tetra1[i].y >> tetra1[i].z;
		REP(i,4) scanf("%lf %lf %lf", &tetra2[i].x, &tetra2[i].y, &tetra2[i].z);//cin >> tetra2[i].x >> tetra2[i].y >> tetra2[i].z;
		printf("%.2lf\n",dist_tet_tet(tetra1,tetra2));
	}
	return 0;
}

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
const double terra = 6378.0;

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

map < string, pair < double, double > > mapa;

double getRadians( double teta ){
	return teta*pi/180.;
}

double getGraus( double rad ){
	return fmod((rad*180./pi)+360., 360.);
}

double haversine(double lat1, double long1, double lat2, double long2){
	double p1 = getRadians((lat2-lat1));
	double p2 = getRadians((long2-long1));
	lat1 = getRadians(lat1);
	lat2 = getRadians(lat2);
	long1 = getRadians(long1);
	long2 = getRadians(long2);
	double a = sin(p1/2.) * sin(p1/2.) + cos(lat1) * cos(lat2) * sin(p2/2.) * sin(p2/2.);
	double c = 2. * atan2(sqrt(a), sqrt(1.-a));
	return (terra * c);
}

double bearing(double lat1, double long1, double lat2, double long2){
	double p2 = getRadians((long2-long1));
	lat1 = getRadians(lat1);
	lat2 = getRadians(lat2);
	long1 = getRadians(long1);
	long2 = getRadians(long2);
	double x = sin(p2) * cos(lat2);
	double y = cos(lat1) * sin(lat2) - sin(lat1) * cos(lat2) * cos(p2);
	return fmod(atan2(y,x),2*pi);
}

int main(){
	ios::sync_with_stdio(false);
	string str = "", de, para, por;
	double lg, lat;
	while( cin >> str && str != "#" ){
		cin >> lg >> lat;
		mapa[str] = make_pair(lat,lg);
	}
	while( cin >> de && de != "#" ){
		cin >> para >> por;
		double a, b, c, d, e, f;
		if( !mapa.count(de) || !mapa.count(para) || !mapa.count(por) )
			cout << por << " is ? km off " << de << "/" << para << " equidistance.\n";
		else{
			a = mapa[de].first;
			b = mapa[de].second;
			c = mapa[para].first;
			d = mapa[para].second;
			e = mapa[por].first;
			f = mapa[por].second;
			/*a = (-94.127592);
			b = (41.81762);
			c = (-94.087257);
			d = (41.848202);
			e = (-94.046875);
			f = (41.791057);*/
			double h = haversine(a, b, e, f);
			double b1 = bearing(a,b,c,d);
			double b2 = bearing(a,b,e,f);
			double dist = asin(sin((h/terra))*sin(((b2-b1))))*terra;
			cout << por << " is " << dist << " km off " << de << "/" << para << " equidistance.\n";
		}

	}
    return 0;
}

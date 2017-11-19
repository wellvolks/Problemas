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
#define INF 0x3F3F3F3
#define LINF 0x3F3F3F3FFFFFFFFFLL
#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) __typeof((X).begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) int((V).size())
#define pb push_back
#define mp make_pair
      
#ifdef _WIN32
    #define getchar_unlocked getchar
#endif
      
inline void read(  int &n ) {
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

int n, qtd;

struct pt{ double x, y; pt( double x = 0., double y = 0. ) : x(x), y(y) { }};

vector < vector < int > > grafo;
pt invMapa[110];

double dist[110][110];
int used[110][110], vis = 1;
int points[110], vis3 = 1;
double sqr( double a ){ return a*a; }

void flody(){

	REP(k,n){
		REP(i,n){
			REP(j,n){
				if( used[i][k] != vis || used[k][j] != vis ) continue;
				double d1 = sqrt(sqr(invMapa[i].x-invMapa[k].x) + sqr(invMapa[i].y-invMapa[k].y));
				double d2 = sqrt(sqr(invMapa[k].x-invMapa[j].x) + sqr(invMapa[k].y-invMapa[j].y));
				if( dist[i][j] > d1 + d2 ){
					dist[i][j] = d1 + d2;
				}
			}
		}
	}
	
}

list < int  > cyc;

int visit[110], vis2 = 1;

void EulerTour( list < int > :: iterator i, int u ){
	REP(j,grafo[u].size()){
		int v = grafo[u][j];
		if( visit[v] != vis2 ){
			visit[v] = vis2;
			REP(k, grafo[v].size()){
				int uu = grafo[v][k];
				if( uu == u && visit[uu] != vis2 ){
					visit[uu] = vis2;
					break;
				}
			}
			EulerTour( cyc.insert( i, u ), v );
		}
	}
}

double getTourCust(){
	double ans = 0., q = 0;
	int ant = -1;
	cout << *cyc.begin() << "\n";
	map < int, int > mapa;
	for( list< int > :: iterator it = cyc.begin(); it != cyc.end(); it++ ){
		mapa[*it]++;
		if( ant != -1 ) ans += dist[ant][*it];
		ant = *it;
		cout << *it << "\n";
	}
	cout << " ~ \n";
	if( mapa.size() != q ) return 2e9;
	return ans;
}

double solve(){
	double ans = 2e9;
	REP(i,n){
		if( points[i] != vis3 ) continue;
		cyc.clear();
		EulerTour(cyc.begin(), i);
		ans = min(ans, getTourCust());
		vis2++;
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	int mapa[110][110], k = 0;
	
	for(int i = 0; i < 5; i++ ){
		for( int j = 0; j < 5; j++ ){
			mapa[i][j] = k;
			invMapa[k] = pt((double)i,(double)j);
			k++;
		}
	}
	REP(i, 5){ REP(j,5){ cout << mapa[i][j] << " "; } cout << "\n"; }
	int t;
	string de, para;
	cin >> t;
	while( t-- ){
		cin >> qtd;
		grafo.resize( 110 );
		n = 26;
		REP(i,qtd){
			cin >> de >> para;
			int d = mapa[de[0]-'A'][de[1]-'1'];
			int p = mapa[para[0]-'A'][para[1]-'1'];
			if( de[0] == para[0] ){
				int x = min(d,p);
				for( int j = min(d,p)+1; j <= max(d,p); j++ ){
					int y = j;
					grafo[x].pb( y );
					grafo[y].pb( x );
					cout << x << " = " << y << "\n";
					used[x][y] = used[y][x] = vis;
					points[x] = points[y] = vis3;
					x = y;
				}
			}
			else if( de[1] == para[1] ){
				int x = d;
				for( int j = min(invMapa[d].x,invMapa[p].x)+1; j <= max(invMapa[d].x,invMapa[p].x); j++ ){
					int y = mapa[j][para[1]-'1'];
					grafo[x].pb( y );
					grafo[y].pb( x );
					cout << x << " [] " << y << "\n";
					used[x][y] = used[y][x] = vis;
					points[x] = points[y] = vis3;
					x = y;
				}
			}
			else{
				grafo[d].pb( p );
				grafo[p].pb( d );
				cout << d << " ~ " << p << "\n";
				used[d][p] = used[p][d] = vis;
				points[d] = points[p] = vis3;
			}
		}
		
		flody();
		
		cout << solve() << "\n"; 
		vis++; vis2++; vis3++;
		grafo.clear();
	}
	return 0;
}
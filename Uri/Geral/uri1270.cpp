#include <set>
#include <tr1/unordered_map>
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
#define RREP(i, N) for(int i = N-1; i >= 0; --i)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )
#define MAXN 5000603
#define INF 0x3F3F3F3F
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
 
struct aresta{
    int atual;
    string str;
    aresta( int atual = 0, string str = "" ) : atual(atual) , str(str) { }
};
 
typedef vector < int > vi;
typedef vector < vi > vii;
typedef vector < tri > vtri;
typedef vector < vtri > vvtri;
typedef long long int64;
typedef unsigned long long uint64;
 
int x[] = {-1,-1,-1, 0, 1, 1, 1, 0 };
int y[] = {-1, 0, 1, 1, 1, 0,-1,-1 };
 
#ifdef _WIN32 
    #define getchar_unlocked getchar
#endif

inline void read( int &n ) {
    n = 0;
    register bool neg = false;
    register char c = getchar_unlocked();
	while( c == '\n' ) c = getchar_unlocked();
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

int qtdN[10000]; 
int n;
double ans = 2e9;
vector < pair < int, int > > liga;
vector < vector < pair < double, double > > > gr;

double dist(pair<double,double> &a, pair<double,double> &b){
	return sqrt(((a.first -b.first)*(a.first -b.first)) + ((a.second -b.second)*(a.second -b.second)));
}

double memo[1100][110][51], visit[1100][51][51], vis = 1;
vector < int > posId(1000);
set < vector < int > > eita;

double solve( int u, int de, int k){
	if( u >= n ){
		double sum = 0.;
		int tam = liga.size();
		REP(i,tam) sum += dist(gr[liga[i].first][posId[liga[i].first]], gr[liga[i].second][posId[liga[i].second]]);
		ans = min(ans,sum);
		return sum;
	}
	double at = 2e9;
	int idx = 0;
	if( eita.count(posId) ) return 0;
	eita.insert(posId);
	REP(i,qtdN[u]){
		posId[u] = i;
		solve( u+1, i, k);
	}
	visit[u][de][k] = vis;
	return 0;
}

int main(){
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(1);
	while( cin >> n && n ){
		int qt, x, y;
		unordered_map < string, int > mapa;
		string name;
		gr.resize( n );
		REP(i,n){
			posId[i] = 0;
			cin >> name >> qt;
			qtdN[i] = qt;
			mapa[name] = i;
			REP(j,qt){
				cin >> x >> y;
				gr[i].pb(mp(x,y));
			}
		}
		string de, para;
		REP(i,n-1){
			cin >> de >> para;
			liga.pb(mp(mapa[de],mapa[para]));
		}
		ans = 2e9;
		solve(0, 0, 0);
		cout << ans << "\n"; 
		gr.clear();
		liga.clear();
		eita.clear();
		vis++;
	}
	return 0;
}
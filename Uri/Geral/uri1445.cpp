#include <tr1/unordered_map>
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
using namespace tr1;

#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define RFOR(i, b, a) for(int i = b; i >= a; --i)
#define REP(i, N) for(int i = 0; i < N; ++i)
#define RREP(i, N) for(int i = N-1; i >= 0; --i)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )
#define MAXN 10000
#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFFLL
#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) __typeof((X).begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) int((V).size())
#define pb push_back
#define mp make_pair

struct tri{
	int ant, novo;
	tri ( int ant = 0, int novo = 0) : ant(ant), novo(novo) { }
};

int n, k;
typedef vector < int > vi;
typedef vector < vi > vii;
typedef vector < tri > vtri;
typedef vector < vtri > vvtri;
typedef long long int64;
typedef unsigned long long uint64;

int x[] = {-1,-1,-1, 0, 1, 1, 1, 0 };
int y[] = {-1, 0, 1, 1, 1, 0,-1,-1 };

vector < vector < int > > grafo;
int visitado[10000], vis = 1;

#ifdef _WIN32 
    #define getchar_unlocked getchar
#endif
 
inline void readInt( int &n ) {
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


int bfs(){
	queue < int > fila;
	fila.push(0);
	int ans = 0;
	visitado[0] = vis;
	while( !fila.empty() ){
		int v = fila.front();
		fila.pop();
		ans++;
		REP(i,SIZE(grafo[v])){
			int at = grafo[v][i];
			if( visitado[at] != vis ){
				visitado[at] = vis;
				fila.push(at);
			}
		}
	}
	return ans;
}


int main(){
	ios::sync_with_stdio(false);
	int t, de, para;
	string line = "";
	readInt(t);
	char c;
	while( t ){
		grafo.resize(1000+1);
		line = "";
		c = getchar_unlocked();
		while( c != '\n' ){ line += c; c = getchar_unlocked(); }
		REP(i,line.size()){
			if( line[i] == '(' || line[i] == ')' || line[i] == ',' ) line[i] = ' ';
		}
		istringstream in (line);
		REP(i,t){
			in >> de >> para;
			grafo[de-1].pb(para-1);
			grafo[para-1].pb(de-1);
		}
		printf("%d\n",bfs());
		vis++;
		grafo.clear();
		readInt(t);
	}
	return 0;
}

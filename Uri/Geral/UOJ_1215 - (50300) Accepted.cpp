#include <tr1/unordered_map>
#include <map>
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
	int atual, tipo;
	tri ( int atual = 0, int tipo = 0) : atual(atual), tipo(tipo) { }
};

int n, m;
typedef vector < int > vi;
typedef vector < vi > vii;
typedef vector < tri > vtri;
typedef vector < vtri > vvtri;
typedef long long int64;
typedef unsigned long long uint64;
const double pi = acos(-1.0);
const double EPS = 1e-9;

int cmp(double a, double b = 0.0){
	if(fabs(a-b) < EPS) return 0;
	return a > b ? 1 : -1;
}
int x[] = {-1,-1,-1, 0, 1, 1, 1, 0 };
int y[] = {-1, 0, 1, 1, 1, 0,-1,-1 };
char str[100000], aux[100000];
vector < string > ans;

bool compare( const string a, const string b ){
	return ( a.compare(b) <= 0 );
}

int main(){
	unordered_map < string , int > mapa;
	unordered_map < string , int > :: iterator it;
	register int pos = 0, p = 0;
	register char c = getchar();
	while(c != EOF){
		c = tolower(c);
		if(isalpha(c)) aux[p++] = c;
		else{
			aux[p] = '\0';
			if(p) mapa[aux]++;
			p = 0;
		}
		c = getchar();
	}
	for(it = mapa.begin(); it != mapa.end(); it++) ans.pb(it->first);
	sort(ALL(ans), compare);
	REP(i,ans.size()) fprintf(stdout,"%s\n",ans[i].c_str());
	return 0;
}

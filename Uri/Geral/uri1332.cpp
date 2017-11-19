
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


typedef vector < int > vi;
typedef vector < vi > vii;
typedef vector < tri > vtri;
typedef vector < vtri > vvtri;
typedef long long int64;
typedef unsigned long long uint64;

int x[] = {-1,-1,-1, 0, 1, 1, 1, 0 };
int y[] = {-1, 0, 1, 1, 1, 0,-1,-1 };
int p[400], vis = 1;

int main(){
	int t;
	char str[100];
	
	scanf("%d",&t);
	getchar();
	while( t-- ){
		gets(str);
		int tam = strlen(str);
		if( tam > 3 ) puts("3");
		else{
			p[str[0]] = vis;
			p[str[1]] = vis;
			p[str[2]] = vis;
			if( (p['n'] == vis && p['e'] == vis ) || (p['n'] == vis && p['o'] == vis ) || (p['o'] == vis && p['e'] == vis )) puts("1");
			else puts("2");
		}
		vis++;
	}
	return 0;
}
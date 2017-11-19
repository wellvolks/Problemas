//#include <tr1/unordered_map>
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
//using namespace tr1;

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

int x[] = {-1,-1,-1, 0, 1, 1, 1, 0 };
int y[] = {-1, 0, 1, 1, 1, 0,-1,-1 };
char str[400], pp[40];
int sum[400];

int main(){
	int p = 0, i, ans, r, w;
	sum['R'] = 1; sum['W'] = 0;
	while(gets(str) != NULL){
		gets(pp);
		if(pp[1] != '\0') p = ((pp[0] - '0') * 10) + (pp[1] - '0');
		else  p = (pp[0] - '0');
		r = w = ans = i = 0;
		while(str[i] != '\0'){
			r += sum[str[i]];
			if(str[i] == 'W'){
				ans++;
				ans += (r > 0);
				r = 0;
			}
			if(r >= p){
				ans++;
				r = 0;
			}
			i++;
		}
		ans += (r > 0);
		printf("%d\n",ans);
	}
	return 0;
}

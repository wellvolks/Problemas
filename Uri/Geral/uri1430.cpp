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
#include <ctype.h>
#include <sys/timeb.h>
using namespace std;
struct timeb ini, fim;
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define RFOR(i, b, a) for(int i = b; i >= a; --i)
#define REP(i, N) for(int i = 0; i < N; ++i)
#define RREP(i, N) for(int i = N-1; i >= 1; --i)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )
#define MAXN 10000
#define LINF 0x3F3F3F3FFFFFFFFFLL
#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) __typeof((X).begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) int((V).size())
const double INF = 1e50;
#define pb push_back
#define mk make_pair

const double EPS = 1e-9;

int x[] = {-1,-1,-1, 0, 1, 1, 1, 0, 0};
int y[] = {-1, 0, 1, 1, 1, 0,-1,-1, 0};

int cmp(double a, double b){
	if(fabs(a-b) < EPS) return 0;
	return ((a > b) ? 1 : -1);
}

char str[100000], *p;
double mapa[1000];

int main(){
	//ios::sync_with_stdio(false);
	mapa['W'] = 1; mapa['H'] = 1./2.; mapa['Q'] = 1./4.; mapa['E'] = 1./8.;
	mapa['S'] = 1./16.; mapa['T'] = 1./32.; mapa['X'] = 1./64.;
	register int tam, resp = 0;
	register double ans;
	//while(cin >> str && str[0] != '*'){
	while(gets(str) && str[0] != '*'){
		p = strtok(str,"/");
		resp = 0;
		while(p != NULL){
			ans = 0.0;
			for( register int i = 0; p[i] != '\0'; i++) ans += mapa[p[i]];
			if(!cmp(ans,1.)) resp++;
			p = strtok(NULL,"/");
		}
		//cout << resp << "\n";
		fprintf(stdout,"%d\n",resp);
	}
	return 0;
}


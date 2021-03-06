//#include <tr1/unordered_map>
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
const double pi = acos(-1.0);
const double EPS = 1e-9;

int cmp(double a, double b = 0.0){
	if(fabs(a-b) < EPS) return 0;
	return a > b ? 1 : -1;
}
int x[] = {-1,-1,-1, 0, 1, 1, 1, 0 };
int y[] = {-1, 0, 1, 1, 1, 0,-1,-1 };

char str[400];

struct estado{
	char st[100];
	float valor;
};

estado vet[10000];
int qt;

float search(){
	REP(i,qt) if(!strcmp(str, vet[i].st)) return vet[i].valor;
	return 0.;
}

int main(){
	int t, c;
	float valor;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&qt);
		REP(i,qt) scanf("%s%f",&vet[i].st,&vet[i].valor);
		double ans = 0.;
		int q = 0;
		scanf("%d",&q);
		REP(i,q){ scanf("%s%d",&str,&c); ans += (search() * c); }
		printf("R$ %.2f\n",ans);
	}
	return 0;
}

#include <set>
#include <map>
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
	int atual, custo;
	tri ( int atual = 0, int custo = 0) : atual(atual), custo(custo) { }
};

struct pos{
	int x, y;
	char tipo;
	pos (int x = 0, int y = 0, char tipo = 0) : x(x), y(y), tipo(tipo) { }
};

struct estado{
	pos p;
	int x, y;
	estado(pos p = (0,0), int x = 0, int y = 0) : p(p), x(x), y(y) { }
};

typedef vector < int > vi;
typedef vector < vi > vii;
typedef vector < tri > vtri;
typedef vector < vtri > vvtri;
typedef long long int64;
typedef unsigned long long uint64;

char num[10000], salto[10000];

int main(){
	int t, p1, p2;
	char aux[400];
	scanf("%d",&t);
	getchar();
	while(t--){
		gets(aux);
		gets(num);
		gets(salto);
		int ans = 0, tam = strlen(num);
		p1 = p2 = 0;
		while(p1 < tam){
			if(num[p1] <= '2' && salto[p2] == 'S') ans++;
			else if(num[p1] > '2' && salto[p2] == 'J') ans++;
			p1 += 2;
			p2++;
		}
		printf("%d\n",ans);
	}
	return 0;
}

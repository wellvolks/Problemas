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
#include <stdint.h>
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
#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFFLL
#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) __typeof((X).begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) int((V).size())

#define pb push_back
#define mk make_pair

struct tri{
int atual, custo;
tri ( int atual = 0, int custo = 0) : atual(atual), custo(custo) { }
};

int k;
typedef vector < int > vi;
typedef vector < vi > vii;
typedef vector < tri > vtri;
typedef vector < vtri > vvtri;
typedef long long int64;
typedef unsigned long long uint64;

int x[] = {-1,-1,-1, 0, 1, 1, 1, 0 };
int y[] = {-1, 0, 1, 1, 1, 0,-1,-1 };

int sum[50000], visited[10], vis = 1;

void processa(){
	char str[100];
	int j = 0, ans = 0;
	bool ok = false;
	for(int i = 1; i <= 5000; i++){
		sprintf(str, "%d", i);
		j = 0; ok = false;
		while(str[j] != '\0'){
			if(visited[str[j] - '0'] == vis){ ok = true; break; }
			visited[str[j]-'0'] = vis;
			j++;
		}
		vis++;
		if( !ok ) sum[i] = 1;
		sum[i] += sum[i-1]; 
	}
}

int main(){
	processa();
	int de, para;
	while(scanf("%d%d", &de,&para) != EOF) printf("%d\n", sum[para] - sum[de-1]);
	return 0;
}

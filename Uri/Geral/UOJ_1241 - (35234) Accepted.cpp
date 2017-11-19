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

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFFLL
#define MAXN 20
#define Atype char
#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) __typeof((X).begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) int((V).size())

#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define RFOR(i, b, a) for(int i = b; i >= a; --i)
#define REP(i, N) for(int i = 0; i < N; ++i)
#define RREP(i, N) for(int i = N-1; i >= 0; --i)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )

#define PB push_back
#define MP make_pair

typedef long long int64;
typedef unsigned long long uint64;

using namespace std;

char str[10000], *str1, *str2;

bool solve(int t1, int t2){
	RFOR(i,t2,0) if(str1[t1--] != str2[i]) return false;
	return true;
}

int main(){
	int t;
	scanf("%d",&t);
	getchar();
	while(t--){
		gets(str);
		str1 = strtok(str, " ");
		str2 = strtok(NULL," ");
		int t1 = strlen(str1), t2 = strlen(str2);
		if(t2 > t1){ printf("nao encaixa\n"); continue; }
		printf("%s\n", (solve(t1-1,t2-1) ? "encaixa" : "nao encaixa"));
	}
	return 0;
}

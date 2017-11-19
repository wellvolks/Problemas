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

char str[1000], ans[1000];

int main(){
	while(gets(str) != NULL){
		bool at1 = true, at2 = true;
		int tam = strlen(str), p = 0;
		REP(i,tam){
			if(str[i] == '_'){
				if(at1){
					ans[p++] = '<';
					ans[p++] = 'i';
					ans[p++] = '>';
				}
				else{
					ans[p++] = '<';
					ans[p++] = '/';
					ans[p++] = 'i';
					ans[p++] = '>';
				}
				at1 = !at1;
			}
			else if(str[i] == '*'){
				if(at2){
					ans[p++] = '<';
					ans[p++] = 'b';
					ans[p++] = '>';
				}
				else{
					ans[p++] = '<';
					ans[p++] = '/';
					ans[p++] = 'b';
					ans[p++] = '>';
				}
				at2 = !at2;
			}
			else ans[p++] = str[i];
		}
		ans[p] = '\0';
		printf("%s\n",ans);
	}
	return 0;
}

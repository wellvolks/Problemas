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


vector < string > mat;

vi str, pp, b;
char strs[30000];
char str1[30000], str2[30000], cam[30000];
 
int LIS(){
	pp.clear();
	pp.resize(str.size());
	int u, v;
	if (str.empty()) return 0;
	b.push_back(0);
	for (size_t i = 1; i < str.size(); i++){
		if (str[b.back()] < str[i]){
			pp[i] = b.back();
			b.push_back(i);
			continue;
		}
		for (u = 0, v = b.size()-1; u < v;) {
			int c = (u + v) >> 1;
			if (str[b[c]] < str[i]) u=c+1; 
			else v=c;
		}
		if (str[i] < str[b[u]]) {
			if (u > 0) pp[i] = b[u-1];
			b[u] = i;
		}	
	}
	return (int)b.size();
}

vector < vector < int > > ri;


int main(){
	int t, n, m, caso = 1;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&n,&m);
		getchar();
		ri.resize(700);
		REP(i,n){
			gets(strs);
			mat.pb(strs);
		}
		int a, bb, x, y, k;
		scanf("%d %d %d",&a,&x,&y);
		x--; y--;
		k = 0;
        str1[k++] = mat[x][y];
		ri[mat[x][y]].pb(0);
		if( a ){
			getchar();
			gets(cam); 
			REP(i,a){
				switch (cam[i]){
					case 'N': x--;
					break;
					case 'E': y++;
					break;
					case 'W': y--;
					break;
					case 'S': x++;
					break;
				}
				ri[mat[x][y]].pb(k);
				str1[k++] = mat[x][y];
			}
		}
		str1[k] = '\0';
		k = 0;
		scanf("%d %d %d",&bb,&x,&y);
		x--; y--;
        str2[k++] = mat[x][y];
		if( !ri[mat[x][y]].empty() ){
			int tam = ri[mat[x][y]].size();
			RFOR(i,tam-1,0) str.pb(ri[mat[x][y]][i]);
		}
		if( bb ){
			getchar();
			gets(cam); 			
			REP(i,bb){
				switch (cam[i]){
					case 'N': x--;
					break;
					case 'E': y++;
					break;
					case 'W': y--;
					break;
					case 'S': x++;
					break;
				}
				str2[k++] = mat[x][y];
				if( !ri[mat[x][y]].empty() ){
					int tam = ri[mat[x][y]].size();
					RFOR(j,tam-1,0) str.pb(ri[mat[x][y]][j]);
				}
			}
		}
		str2[k] = '\0';
		int ans = LIS();
		fprintf(stdout,"Case %d: %d %d\n",caso++, strlen(str1) - ans, strlen(str2) - ans);
		mat.clear();
		cam[0] = str1[0] = str2[0] = strs[0] = '\0';
		str.clear();
		b.clear();
		ri.clear();
	}
	return 0;
}

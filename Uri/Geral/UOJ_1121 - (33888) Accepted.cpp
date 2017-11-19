#include <tr1/unordered_map>
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
#define pair < int, int > pii;

struct tri{
	int atual, custo;
	tri ( int atual = 0, int custo = 0) : atual(atual), custo(custo) { }
};

int n, m;
typedef vector < int > vi;
typedef vector < vi > vii;
typedef vector < tri > vtri;
typedef vector < vtri > vvtri;
typedef long long int64;
typedef unsigned long long uint64;

char grafo[110][110], mover[60000];
int x, y;
const int cord[][2] = {{-1,0} , {0,1} , {1,0} , {0,-1}};
int direcao[90], lin, col;;

int girar(int pos, int d){
	if(pos + d < 0) return 3;
	return (d + pos) % 4;
}

int andar(int d){
	lin = x + cord[d][0];
	col = y + cord[d][1];
	if(lin >= 0 && lin < n && col >= 0 && col < m && grafo[lin][col] != '#'){
		x = lin, y = col;
		if(grafo[x][y] == '*'){ grafo[x][y] = '.'; return 1; }
	}
	return 0;
}

int main(){
	register int d, ans, flag, i, j;
	int s;
	ios::sync_with_stdio(false);
	direcao['N'] = 0, direcao['L'] = 1, direcao['S'] = 2, direcao['O'] = 3;
	while(cin >> n >> m >> s && (n+m+s)){
		ans = flag = 0;
		for(i = 0; i < n; i++){
			cin >> grafo[i];
			if(!flag){
				for(j = 0; j < m; j++) 
					if(grafo[i][j] == 'N' || grafo[i][j] == 'S' || grafo[i][j] == 'L' || grafo[i][j] == 'O'){ 
						x = i, y = j ; 
						d = direcao[grafo[i][j]];
						flag = 1; 
						grafo[i][j] = '.';
						break;
					}
			}
		}
		cin >> mover;
		for(i = 0; i < s; i++){
			if(mover[i] == 'D') d = girar(1,d);
			else if( mover[i] == 'E') d = girar(-1,d);
			else ans += andar(d);
		}
		cout << ans << "\n";
	}
	return 0;
}

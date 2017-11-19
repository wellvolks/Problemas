#include <map>
#include <set>
#include <deque>
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
#define RREP(i, N) for(int i = N-1; i >= 1; --i)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )
#define MAXN 10000
#define LINF 0x3F3F3F3FFFFFFFFFLL
#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) __typeof((X).begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) int((V).size())
#define pb push_back
#define mk make_pair
#define check(v) (v >= 0 && v <= 7)

int xx[] = {-2,-1,1,2,2,1,-1,-2};
int yy[] = {1,2,2,1,-1,-2,-2,-1};

int memo[66][66], mat[9][9], visit[66][66], vis = 1;

struct pt{
	int x, y, b;
	pt( int x = 0, int y = 0, int b = 0 ) : x(x), y(y), b(b) { }
};

int bfs( pt o, pt d ){
	queue < pt > fila;
	fila.push(o);
	pt at;
	while( !fila.empty() ){
		at = fila.front();
		fila.pop();
		memo[mat[o.x][o.y]][mat[at.x][at.y]] = memo[mat[at.x][at.y]][mat[o.x][o.y]] = at.b;
		if( visit[at.x][at.y] == vis ) continue;
		visit[at.x][at.y] = vis;
		if( at.x == d.x && at.y == d.y ) return at.b;
		REP(i,8){
			int x = at.x + xx[i];
			int y = at.y + yy[i];
			if(check(x) && check(y)) fila.push(pt(x,y,at.b + 1));
		}
	}
	return 0;
}

int main(){
	ios::sync_with_stdio(false);
	int k = 0, dx, dy, ox, oy;
	REP(i,8) REP(j,8) mat[i][j] = k++;
	string a, b;
	memset(memo,-1,sizeof(memo));
	int pos[] = {7,6,5,4,3,2,1,0};
	while( cin >> a >> b ){
		ox = a[0] - 'a';
		oy = pos[a[1] - '0' - 1];
		dx = b[0] - 'a';
		dy = pos[b[1] - '0' - 1];
		if( memo[mat[ox][oy]][mat[dx][dy]] != -1 ) printf("To get from %s to %s takes %d knight moves.\n",a.c_str(), b.c_str(),  memo[mat[ox][oy]][mat[dx][dy]]);
		else{
			memo[mat[ox][oy]][mat[dx][dy]] = memo[mat[dx][dy]][mat[ox][oy]] = bfs(pt(ox,oy),pt(dx,dy));
			printf("To get from %s to %s takes %d knight moves.\n",a.c_str(), b.c_str(),  memo[mat[ox][oy]][mat[dx][dy]]);
		}
		vis++;
	}
	return 0;
}
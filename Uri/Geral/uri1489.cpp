#include <set>
//#include <tr1/unordered_map>
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
//using namespace tr1;

#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define RFOR(i, b, a) for(int i = b; i >= a; --i)
#define REP(i, N) for(int i = 0; i < N; ++i)
#define RREP(i, N) for(int i = N-1; i >= 0; --i)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )
#define MAXN 101
#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFFLL
#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) __typeof((X).begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) int((V).size())
#define pb push_back
#define mp make_pair

 #ifdef _WIN32
    #define getchar_unlocked getchar
#endif

inline void read( int &n ) {
    n = 0;
    bool neg = false;
    char c = getchar_unlocked();
    if( c == EOF){ n = -400; return; }
    while (!('0' <= c && c <= '9')) {
        if( c == '-' ) neg = true;
        c = getchar_unlocked();
    }
    while ('0' <= c && c <= '9') {
        n = n * 10 + c - '0';
        c = getchar_unlocked();
    }
    n = (neg ? (-n) : (n));
}


int n, start, finish, new_base, match[MAXN], father[MAXN], base[MAXN], vis = 1;
int graph[MAXN][MAXN], in_queue[MAXN], in_path[MAXN], in_blossom[MAXN];
queue< int > q;

int find_common_ancestor(int u, int v) {
	memset(in_path, 0, sizeof(in_path));
	while(1) {u=base[u]; in_path[u]=1; if (u==start) break; u=father[match[u]];}
	while(1) {v=base[v]; if (in_path[v]) break; v = father[match[v]]; }
	return v;
}

void reset_trace(int u) {
	while (base[u] != new_base) {
		int v = match[u]; 
		in_blossom[base[u]] = 1; 
		in_blossom[base[v]] = 1;
		u = father[v];
		if (base[u] != new_base) father[u] = v;
	}
}

void contract(int u, int v) {
	new_base = find_common_ancestor(u, v);
	memset(in_blossom, 0, sizeof(in_blossom));
	reset_trace(u); reset_trace(v);
	if (base[u] != new_base) father[u] = v;
	if (base[v] != new_base) father[v] = u;
	for(int i = 1; i < n; i++){ 
		if (in_blossom[base[i]]) {
			base[i] = new_base; if (!in_queue[i]) q.push(i);
		}
	}
}

void find_augmenting_path() {
	memset(in_queue, 0, sizeof(in_queue));
	memset(father, 0, sizeof(father));
	for(int i = 1; i < n; i++) base[i] = i;
	finish = 0;
	while( !q.empty() ) q.pop(); q.push(start); in_queue[start] = 1;
	while ( !q.empty() ) {
	int u = q.front(); q.pop();
	for(int v = 1; v < n; v++) 
		if ((graph[u][v] == vis) && (base[u] != base[v]) && (match[u] != v)){
			if ((v==start)||((match[v]>0)&&(father[match[v]]>0))) 
				contract(u,v);
			else if (father[v] == 0) {
				father[v] = u;
				if (match[v] > 0) q.push(match[v]);
				else { finish = v; return; }
			}
		}
	}
}

void augment_path() {
	int u = finish, v, w;
	while (u > 0){v=father[u]; w = match[v]; match[v] = u; match[u] = v; u = w;}
}

int edmonds() {
	memset(match,0,sizeof(match));
	for(int i = 1; i < n; i++) if (match[i] == 0) {
		start = i; 
		find_augmenting_path();
		if (finish > 0) augment_path();
	}
	int r = 0;
	for(int i = 1; i < n; i++) if ( match[i] > 0 ) r++;
	return r / 2;
}

int inst = 1;

int print() { 
	int ans = 0;
	for(int i = 1; i < n; i++) 
		if ( i < match[i] ) 
			ans += 2;
	if(ans >= n-1) return 1;
	else return 0;
}

int main(){
	int t, qt, at;
	ios::sync_with_stdio(false);
	read(t);
	char resp[2][60] = {"extreme programming\n","pair programming\n"};
	while(t--){
		read(n);
		n++;
		REP(i,n-1){
			read(qt);
			REP(j,qt){
				read(at);
				graph[i+1][at] = graph[at][i+1] = vis;
			}
		}
		printf("Instancia %d\n",inst++ );
		edmonds();
		puts(resp[print()]);
		vis++;
	}
	return 0;
}


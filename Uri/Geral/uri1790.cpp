#include <bits/stdc++.h>
#define MAXN 111

using namespace std;

typedef long long int64;
typedef unsigned long long uint64;

vector< vector < int > > grafo;
int low[MAXN], lbl[MAXN], parent[MAXN];
int dfsnum;
vector< pair<int,int> > brid;

void dfs( int u ){
	lbl[u] = low[u] = dfsnum++;
	for( size_t i = 0, sz = grafo[u].size(); i < sz; i++ ){
		int v = grafo[u][i];
		if( lbl[v] == -1 ){
			parent[v] = u;
			dfs( v );
			if( low[v] > lbl[u] )
				brid.push_back( make_pair(u, v) );
			low[u] = min( low[u], low[v] );
			
		}
		else if( v != parent[u] ){
			low[u] = min( low[u], lbl[v] );
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	int c, p, a, b;
	while( cin >> c >> p ){
		grafo.resize(c+10);
		for( int i = 0; i < p; i++ ){
			cin >> a >> b; a--; b--;
			grafo[a].push_back(b);
			grafo[b].push_back(a);
		}
		brid.clear();
		dfsnum = 0;
		memset(lbl, -1, sizeof(lbl));
		for( int i = 0; i < c; i++ ){
			if( lbl[i] == -1 ){
				dfs(i);
			}
		}
		cout << brid.size() << '\n';
		grafo.clear();
	}
	return 0;
}
#include <bits/stdc++.h>
#define MAXN 100005

using namespace std;

typedef long long int64;
typedef unsigned long long uint64;

#ifdef _WIN32 
    #define getchar_unlocked getchar
#endif
 
inline void read( int &n ) {
    n = 0;
    register bool neg = false;
    register char c = getchar_unlocked();
    if( c == EOF) { n = -1; return; }
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

int vertice_id[MAXN], dfs_num[MAXN];
int dfs_low[MAXN], visited[MAXN], vis = 1;
int grau[MAXN];
int dfs_count = 0, scc_count = 0;

vector < int > s;
vector < int > grafo[MAXN];
vector < int > novoGrafo[MAXN];
vector < pair < int, int > > arestas;
set < pair < int, int > > temAresta;

void tarjanSCC( int u ){
	dfs_low[u] = dfs_num[u] = dfs_count++;
	s.push_back(u);
	visited[u] = vis;

	for( int j = 0, sz = grafo[u].size(); j < sz; j++ ){
		int v = grafo[u][j];
		if( dfs_num[v] == -1 ) tarjanSCC(v);
		if( visited[v] == vis ) dfs_low[u] = min(dfs_low[u],dfs_low[v]);
	}

	if( dfs_low[u] == dfs_num[u] ){
		scc_count++;
		while( true ){
			int v = s.back();
			s.pop_back();
			visited[v] = 0;
			vertice_id[v] = scc_count-1;
			if( u == v ) break;
		}
	}
}

bool topSort() {
	vector < int > ans; 
	queue < int > fila;

	for( int i = 0; i < scc_count; i++ ) if ( grau[i] == 0 ) fila.push(i);

	while ( !fila.empty() ) {
		int at = fila.front();
		fila.pop();
		ans.push_back(at);
		for( int i = 0, sz = novoGrafo[at].size(); i < sz; i++ ){
			grau[novoGrafo[at][i]]--;
			if( grau[novoGrafo[at][i]] == 0 ) fila.push(novoGrafo[at][i]);
		}
	}

	for( int i = 0, sz = ans.size(); i < sz-1; i++ ){
		if( !temAresta.count(make_pair(ans[i], ans[i+1]))) return false;
	}

	return true;
}


int main(){
	ios::sync_with_stdio(false);
	int n, m, de, para;
	read(n); read(m);

	for( int i = 0; i < m; i++ ){
		read(de); read(para);
		de--; para--;
		grafo[de].push_back(para);
		arestas.push_back(make_pair(de,para));
	}

	for( int i = 0; i <= n; i++ ) dfs_num[i] = -1;
	
	dfs_count = 0;
	scc_count = -1;

	for( int i = 0; i < n; i++ ){
		if( dfs_num[i] == -1 ) tarjanSCC(i);
	}

	for( int i = 0; i < m; i++ ){
		int u = vertice_id[arestas[i].first];
		int v = vertice_id[arestas[i].second];

		if( u != v ){
			novoGrafo[u].push_back(v);
			grau[v]++;
			temAresta.insert(make_pair(u,v));
		}
	}

	if( !topSort() ) puts("Nao Bolada");
	else puts("Bolada");
	
	return 0;
}
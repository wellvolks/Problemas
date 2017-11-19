#include <bits/stdc++.h>

using namespace std;

vector < vector < int > > grafo;
unordered_map<string, int > mapa;
vector < string > ans;
int used[10000], vis = 1;
string str[10000];

void bfs(int de, int g){
	queue < pair< int, int > > fila;
	fila.push(make_pair(de,0));
	used[de] = vis;
	while( !fila.empty() ){
		pair < int, int > at = fila.front();
		fila.pop();
		if( at.second <= g ){
			if( str[at.first] != "Rerisson" ) ans.push_back(str[at.first]);
		}
		if( at.second >= g ) continue;
		for(int i = 0; i < grafo[at.first].size(); i++){
			int u = grafo[at.first][i];
			if( used[u] != vis ){
				used[u] = vis;
				fila.push(make_pair(u,at.second+1));
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	int n, g, k = 0, a, b;
	string de, para;
	cin >> n >> g;
	grafo.resize(n+10);
	for( int i = 0; i < n; i++ ){
		cin >> de >> para;
		if(mapa.count(de)) a = mapa[de];
		else{mapa[de] = k; a = k++;}
		if(mapa.count(para)) b = mapa[para];
		else{mapa[para] = k; b = k++;}
		str[a] = de;
		str[b] = para;
		grafo[a].push_back(b);
		grafo[b].push_back(a);	
	}
	bfs(mapa["Rerisson"],g);
	sort(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for(int i = 0, sz = ans.size(); i < sz; i++){
		cout << ans[i] << '\n';
	}
	return 0;
}
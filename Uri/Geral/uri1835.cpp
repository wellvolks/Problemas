#include <bits/stdc++.h>

using namespace std;

int pai[1000], rk[1000];

void init(int n){
	for(int i = 0; i <= n; i++){
		pai[i] = i;
		rk[i] = 0;
	}
}

int find(int u){
	int a = u;
	while( a != pai[a] ) a = pai[a];
	int b = u;
	while(b != a){
		int c = pai[b];
		pai[b] = a;
		b = c;
	}
	return a;
}

void merge(int u, int v){
	int a = find(u);
	int b = find(v);
	if( a == b ) return ;
	if(rk[b] > rk[a]) swap(a,b);
	if(rk[a] == rk[b]) rk[a]++;
	pai[b] = a;
}

int main(){
	ios::sync_with_stdio(false);
	int t, n, m, de, para, k = 1;
	cin >> t;
	while(t--){
		cin >> n >> m;
		init(n+10);
		for(int i = 0; i < m; i++){
			cin >> de >> para; de--; para--;
			merge(de,para);
		}
		int used[110];
		memset(used, 0, sizeof(used));
		for(int i = 0; i < n; i++) used[find(i)] = 1;
		int ans = 0;
		for(int i = 0; i < n; i++) ans += (used[i] == 1);
		cout << "Caso #" << k++ << ": ";
		if( ans == 1 ) cout << "a promessa foi cumprida\n";
		else cout << "ainda falta(m) " << ans-1 << " estrada(s)\n"; 
	}
	return 0;
}
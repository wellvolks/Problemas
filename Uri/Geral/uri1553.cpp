#include <bits/stdc++.h>

using namespace std;

int freq[110];

int main(){
	ios::sync_with_stdio(false);
	int n, k, v;
	while( cin >> n >> k && ( n + k ) ){
		memset(freq,0,sizeof(freq));
		int m = 0;
		for( int i = 0; i < n; i++ ){
			cin >> v;
			freq[v]++;
			m = max(m,v);
		}
		int ans = 0;
		for( int i = 0; i <= m; i++ ) if( freq[i] >= k ) ans++;
		cout << ans << "\n";
	}
	return 0;
}
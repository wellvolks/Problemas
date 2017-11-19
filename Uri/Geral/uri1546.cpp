#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	string ans[] = {"Rolien","Naej","Elehcim","Odranoel"};
	int t, val, n;
	cin >> t;
	while( t-- ){
		cin >> n;
		for( int i = 0; i < n; i++ ){
			cin >> val;
			cout << ans[val-1] << "\n";
		}
	}
	return 0;
}
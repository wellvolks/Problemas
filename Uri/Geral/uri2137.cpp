#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int n;
	while( cin >> n ){
		vector < string > v(n);
		for(int i = 0; i < n; i++){
			cin >> v[i];
		}
		sort(v.begin(), v.end());
		for(int i = 0; i < n; i++){
			cout << v[i] << '\n';
		}
	}
	return 0;
}
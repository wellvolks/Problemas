#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int t, a, ans = 0;
	cin >> t;
	for(int i = 0; i < 5; i++){
		cin >> a;
		if( a == t ) ans++;
	}
	cout << ans << '\n';
	return 0;
}
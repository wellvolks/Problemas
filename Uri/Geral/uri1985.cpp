#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	double ans = 0, b = 0.;
	int id;
	while( t-- ){
		cin >> id >> b;
		ans += (double(id-1000)+0.5)*b;
	}
	cout << fixed << setprecision(2) << ans << "\n";
	return 0;
}
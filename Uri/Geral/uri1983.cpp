#include <bits/stdc++.h>

using namespace std;


int main(){
	ios::sync_with_stdio(false);
	int n, a, res = -1;
	double b, ans = -1e9;
	cin >> n;
	while( n-- ){
		cin >> a >> b;
		if( !(b < 8.0) ){
			if( b > ans ){
				ans = b;
				res = a;
			}
		}
	}
	if( res == -1 ) cout << "Minimum note not reached\n";
	else cout << res << '\n';
	return 0;
}
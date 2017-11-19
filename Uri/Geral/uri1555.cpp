#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	string ans[] = {"Rafael", "Beto", "Carlos"};
	int t, x, y;
	cin >> t;
	while( t-- ){
		cin >> x >> y;
		int a = ((3*x)*(3*x))+(y*y);
		int b = 2*(x*x) + (5*y)*(5*y);
		int c = -100*x + (y*y*y);
		if( a > b && a > c ) cout << ans[0];
		else if( b > a && b > c ) cout << ans[1];
		else cout << ans[2];
		cout << " ganhou\n";
	}
	return 0;
}
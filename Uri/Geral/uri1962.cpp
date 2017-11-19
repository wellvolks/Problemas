#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int t, a;
	cin >> t;
	while( t-- ){
		cin >> a;
		if( a < 2015 ) cout << 2015-a << " D.C.\n";
		else cout << (a-2015)+1 << " A.C.\n";
	}
	return 0;
}
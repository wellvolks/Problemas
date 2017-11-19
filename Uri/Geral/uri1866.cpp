#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef unsigned long long uint64;

int main(){
	ios::sync_with_stdio(false);
	int t, val;
	cin >> t;
	while( t-- ){
		cin >> val;
		if( val & 1 ) cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
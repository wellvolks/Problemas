#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef unsigned long long uint64;

int main(){
	ios::sync_with_stdio(false);
	int t, val;
	string str;
	cin >> t;
	while( t-- ){
		cin >> str >> val;
		cout << ((str == "Thor") ? ('Y') : ('N')) << '\n';
	}
	return 0;
}
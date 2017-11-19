#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef unsigned long long uint64;

int main(){
	ios::sync_with_stdio(false);
	int t, val;
	cin >> t;
	vector < pair < int, int > > vet;
	for( int i = 0; i < t; i++ ){
		cin >> val;
		vet.push_back(make_pair(val, i+1));
	}
	sort(vet.begin(), vet.end());
	cout << vet[0].second << '\n';
	return 0;
}
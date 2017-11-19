#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	string nomeA, nomeB, escolhaA, escolhaB;
	unsigned long long va, vb;
	while( t-- ){
		cin >> nomeA >> escolhaA >> nomeB >> escolhaB;
		cin >> va >> vb;
		if( (va+vb) & 1LL ) cout << ((escolhaA == "IMPAR") ? (nomeA) : (nomeB)) << "\n";
		else cout << ((escolhaA == "PAR") ? (nomeA) : (nomeB)) << "\n";
	}
	return 0;
}
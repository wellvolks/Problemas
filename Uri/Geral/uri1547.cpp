#include <bits/stdc++.h>

using namespace std;

int vet[100];

int main(){
	ios::sync_with_stdio(false);
	int t, s, qt;
	cin >> t;
	while( t-- ){
		cin >> qt >> s;
		int p = -1;
		for( int i = 0; i < qt; i++ ){
			cin >> vet[i];
			if( vet[i] == s && p == -1) p = i;
		}
		if( p != -1 ) cout << p+1 << "\n";
		else{
			int df = 1e9;
			for( int i = 0; i < qt; i++ ){
				if( abs(s - vet[i]) < df ){ df = abs(s - vet[i]); p = i; }
			}
			cout << p+1 << '\n';
		}
	}
	return 0;
}
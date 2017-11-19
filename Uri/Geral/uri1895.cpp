#include <bits/stdc++.h>

using namespace std;

int vet[100];

int main(){
	ios::sync_with_stdio(false);
	int n, t, l;
	cin >> n >> t >> l;
	for( int i = 0; i < n-1; i++ ){
		cin >> vet[i];
	}
	int ans[] = {0,0};
	for( int j = 0, i = 0; i < n-1; i++ ){
		if( abs(vet[i]-t) <= l ){
			ans[j] += abs(vet[i]-t);
			t = vet[i];
		}
		j = 1 - j;
	}
	cout << ans[0] << " " << ans[1] << '\n';
	return 0;
}
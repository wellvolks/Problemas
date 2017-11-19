#include <bits/stdc++.h>

using namespace std;

int vet[10000000];
int used[10000000];

int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	long long sum = 0;
	for(int i = 0; i < n; i++){
		cin >> vet[i];
		sum += vet[i];
	}

	int ans = 0;
	int at = 0;
	while(at >= 0 && at < n && vet[at]){
		if( !used[at] ) ans++;
		used[at] = 1;
		vet[at]--;
		sum--;
		if( (vet[at]+1) & 1LL ) at++;
		else at--; 
		
	}

	cout << ans << " " << sum << '\n';

	return 0;
}
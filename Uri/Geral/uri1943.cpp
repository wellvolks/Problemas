#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int vet[] = {1, 3, 5, 10, 25, 50, 100};
	cout << "Top " << vet[lower_bound(vet, vet+7, n)-vet] << '\n';

	return 0;
}
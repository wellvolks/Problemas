#include <bits/stdc++.h>

using namespace std;

int mat[300][300];
int used[100000];

int main(){
	ios::sync_with_stdio(false);
	int n, x, y;
	cin >> n;
	for( int i = 0; i < n; i++ ){
		for( int j = 0; j < n; j++ ){
			cin >> mat[i][j];
		}
	}
	n <<= 1;
	int ans = 0;
	for( int i = 0; i < n; i++ ){
		cin >> x >> y; x--; y--;
		if( used[mat[x][y]] ) continue;
		used[mat[x][y]] = 1;
		ans++;
	}
	cout << ans << '\n';
	return 0;
}
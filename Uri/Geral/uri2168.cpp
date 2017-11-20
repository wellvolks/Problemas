#include <bits/stdc++.h>

using namespace std;

int mat[110][110];

bool check(int a, int b){
	if( (mat[a][b] + mat[a][b+1] + mat[a+1][b] + mat[a+1][b+1]) >= 2) return true;
	return false;
}

int main(){
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	for(int i = 0; i <= t; i++){
		for(int j = 0; j <= t; j++){
			cin >> mat[i][j];
		}
	}
	for(int i = 0; i < t; i++){
		string str = "";
		for(int j = 0; j < t; j++){
			if( check(i, j) ) str += 'S';
			else str += 'U';
		}
		cout << str << '\n';
	}
	return 0;
}
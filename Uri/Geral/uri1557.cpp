#include <bits/stdc++.h>

using namespace std;
unsigned int mat[16][16];

int main(){
	ios::sync_with_stdio(false);
	int n;
	while( cin >> n && n ){
		for( int i = 0; i < n; i++ ){
			unsigned int k = pow(2,i);
			for( int j = 0; j < n; j++ ){
				mat[i][j] = k;
				k <<= 1;
			}
		}
		int x = 0, aux = mat[n-1][n-1];
		while( aux ){
			x++;
			aux /= 10;
		}
		for( int i = 0; i < n; i++ ){
			cout.fill(' ');
			cout.width(x);
			for( int j = 0; j < n; j++ ){
				cout << mat[i][j];
				if(j+1 < n){
					cout.fill(' ');
					cout.width(x+1);
				}
			}
			cout << "\n";
		}
		cout << "\n";
	}
	return 0;
}
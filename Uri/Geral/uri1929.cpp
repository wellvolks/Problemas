#include <bits/stdc++.h>

using namespace std;


int main(){
	ios::sync_with_stdio(false);
	int v[10];
	cin >> v[0] >> v[1] >> v[2] >> v[3];
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			for(int k = 0; k < 4; k++){
				if( i == j || i == k || j == k ) continue;
				if( (v[i]+v[j] > v[k] )&& (v[i]+v[k] > v[j]) && (v[j]+v[k] > v[i]) ){
					cout << 'S' << '\n';
					return 0;
				}
			}
		}
	}
	cout << "N\n";
	return 0;
}
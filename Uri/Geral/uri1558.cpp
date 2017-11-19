#include <bits/stdc++.h>

using namespace std;

vector < int > val;
int ans[10010];

int main(){
	ios::sync_with_stdio(false);
	for( int i = 0; i*i <= 10000; i++ ) val.push_back(i*i);
	int t = val.size(), q;
	for( int i = 0; i < t; i++ ){
		for( int j = i; j < t; j++ ){
			if( val[i]+val[j] <= 10000 ) ans[val[i]+val[j]] = 1;
		}
	}
	string resp[] = {"NO","YES"};
	while( cin >> q ){ 
		if( q < 0 ) cout << "NO\n";
		else cout << resp[ans[q]] << "\n";
	}
	return 0;
}
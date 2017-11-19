#include <bits/stdc++.h>
#define INF 0x3F3F3F3F 
#define LINF 0x3F3F3F3FFFFFFFFFLL 

using namespace std;

typedef long long int64; 
typedef unsigned long long uint64; 

int main(){
	ios::sync_with_stdio(false);
	int t;
	long long val, ans = 0, m = 1e9;
	cin >> t;
	for( int i = 0; i < t; i++ ){
		cin >> val;
		if( val < m ) m = val;
		else{
			ans = max(ans, val - m);
		}
	}
	cout << ans << '\n';
	return 0;
}
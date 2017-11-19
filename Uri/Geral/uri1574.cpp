#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int t, n;
	cin >> t;
	vector < int > move;
	while( t-- ){
		cin >> n;
		move.clear();
		string str;
		int ans = 0, val;
		while( n-- ){
			cin >> str;
			if( str[0] == 'L' ){
				move.push_back(-1);
				ans--;
			}
			else if( str[0] == 'R' ){
				move.push_back(1);
				ans++;
			}
			else{
				cin >> str >> val;
				ans += move[val-1];
				move.push_back(move[val-1]);
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
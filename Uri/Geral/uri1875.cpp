#include <bits/stdc++.h>

using namespace std;

int idx[500];
string id[] = {"red", "green", "blue"};
int win[500][500];

int main(){
	ios::sync_with_stdio(false);
	int t, n;
	char a, b;
	cin >> t;
	win['R']['G'] = 2;
	win['R']['B'] = 1;
	win['G']['B'] = 2;
	win['G']['R'] = 1;
	win['B']['R'] = 2;
	win['B']['G'] = 1;
	idx['R'] = 0;
	idx['G'] = 1;
	idx['B'] = 2;
	while( t-- ){
		cin >> n;
		vector < pair < int, int > > ans;
		for( int i = 0; i < 3; i++ ) ans.push_back(make_pair(0,i));
		for( int i = 0; i < n; i++ ){
			cin >> a >> b;
			a = toupper(a);
			b = toupper(b);
			ans[idx[a]].first += win[a][b];
		}
		sort(ans.begin(),ans.end());
		if( ans[0].first == ans[1].first && ans[0].first == ans[2].first ) cout << "trempate\n";
		else if( ans[1].first == ans[2].first ) cout << "empate\n";
		else cout << id[ans[2].second] << "\n";
	}
	return 0;
}
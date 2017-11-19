#include <bits/stdc++.h>
#define MAXN 100005

using namespace std;

typedef long long int64;
typedef unsigned long long uint64;

struct tri{
	int64 a, b, c, d;
};

map < string, int > ans;

int main(){
	ios::sync_with_stdio(false);
	int m, n;
	cin >> m >> n;
	vector < tri > planos;
	int64 x, y, z;
	tri at;
	for( int i = 0; i < m; i++ ){
		cin >> at.a >> at.b >> at.c >> at.d;
		planos.push_back(at);
	}
	for( int i = 0; i < n; i++ ){
		cin >> x >> y >> z;
		string pt = "";
		for( int j = 0; j < m; j++ ){
			int64 r = planos[j].a * x + planos[j].b * y + planos[j].c * z;
			if( r > planos[j].d ) pt += "+";
			else pt += "-";
		}
		ans[pt]++;
	}
	map < string, int > :: iterator it = ans.begin();
	int resp = 0;
	while( it != ans.end() ){
		resp = max(resp,it->second);
		it++;
	}
	cout << resp << '\n';
	return 0;
}
#include <bits/stdc++.h>
#define MAXN 111

using namespace std;

typedef long long int64;
typedef unsigned long long uint64;

int main(){
	ios::sync_with_stdio(false);
	int n, val, k = 1;
	while( cin >> n && n ){
		string alfa = "", ans = "";
		for( char i = 'A'; i <= 'Z'; i++ ) alfa += i;
		for( int i = 0; i < n; i++ ){
			cin >> val;
			char at = alfa[val-1];
			ans += at;
			alfa.erase(alfa.begin()+val-1);
			alfa.insert(alfa.begin(),at);
		}
		cout << "Instancia " << k++ << '\n';
		cout << ans << "\n\n";
	}
	return 0;
}
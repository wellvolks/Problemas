#include <bits/stdc++.h>

using namespace std;

char mapa[500];

int main(){
	ios::sync_with_stdio(false);
	int j = 10;
	
	for(char i = 'A'; i <= 'V'; i++ ) mapa[j++] = i;
	j = 0;
	for( char i = '0'; i <= '9'; i++ ) mapa[j++] = i; 

	unsigned long long val;
	while( cin >> val && val ){
		string ans = "";
		while(val){
			int mod = val % 32LL;
			ans += mapa[mod];
			val /= 32LL;
		}
		reverse(ans.begin(), ans.end());
		cout << ans << '\n';
	}
	cout << "0\n";
	return 0;
}
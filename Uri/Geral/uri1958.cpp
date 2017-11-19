#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	double str;
	cin >> str;
	string ans = "";
	stringstream ss;
	ss << setprecision(4) << scientific << str;
	ss >> ans;
	for(int i = 0; i < ans.size(); i++){
		if( ans[i] == 'e' ) ans[i] = 'E';
	}
	string aff = "";
	for(int i = ans.size()-1; i>= 0; i--){
		if( ans[i] == '+' || ans[i] == '-' ) break;
		aff += ans[i];
	}
	reverse(aff.begin(), aff.end());
	if( aff.size() == 3 && aff < "100" ) ans.erase(ans.begin()+ans.size()-3);
	if( ans[0] != '-' ) cout << '+';
	cout << ans << '\n';
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	long long n;
	cin >> n;
	stringstream ss;
	ss << hex << n;
	string str;
	ss >> str;
	for(int i = 0; i < str.size(); i++){
		if( str[i] >= 'a' && str[i] <= 'z' ) str[i] = toupper(str[i]);
	}
	cout << str << '\n';
	return 0;
}
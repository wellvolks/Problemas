#include <bits/stdc++.h>

using namespace std;


int main(){
	ios::sync_with_stdio(false);
	int n, s = 0;
	string str;
	while ( cin >> n >> str ){
		s = 0;
		for(int i = 0; i < n; i++){
			s += str[i]-'0';
		}
		cout << s << " " << ((s%3 == 0) ? ("sim\n") : ("nao\n"));
	}
	return 0;
}
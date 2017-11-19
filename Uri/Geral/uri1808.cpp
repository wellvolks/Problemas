#include <bits/stdc++.h>
#define MAXN 111

using namespace std;

typedef long long int64;
typedef unsigned long long uint64;

int main(){
	ios::sync_with_stdio(false);
	string str;
	cin >> str;
	double ans = 0, tot = 0;
	for( int i = 0, sz = str.size(); i < sz; i++ ){
		if( str[i] == '1' && i+1 < sz && str[i+1] == '0'){
			tot++;
			ans += 10.;
			i++;
		}
		else{
			tot++;
			ans += str[i]-'0';
		}
	}
	cout << fixed << setprecision(2) << (ans/tot) << '\n';
	return 0;
}
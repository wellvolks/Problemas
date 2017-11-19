#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int a, b, c;
	char str[100];
	while( cin >> a >> b >> c && ( a+b+c ) ){
		double ans = a*b*c;
		ans = pow(ans,1./3.);
		sprintf(str,"%.6f",ans);
		str[strlen(str)-7] = '\0';
		cout << str << "\n";
	}
	return 0;
}
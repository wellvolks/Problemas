#include <bits/stdc++.h>

using namespace std;

double solve(int qt){
	if( qt == 1 ) return 2;
	return 2 + 1./solve(qt-1);
}

int main(){
	ios::sync_with_stdio(false);
	int a;
	cin >> a;
	if( a == 0 ) cout << "1.0000000000\n";
	else cout << fixed << setprecision(10) << 1+1./solve(a) << '\n';
	return 0;
}
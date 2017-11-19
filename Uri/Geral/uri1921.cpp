#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	unsigned long long n;
	cin >> n;
	cout << (((n*(n-1LL)) >> 1LL)-n) << '\n';
	return 0;
}
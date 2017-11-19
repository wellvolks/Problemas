#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int n;
	string ans[] = {"vai ter copa!","vai ter duas!"};
	while( cin >> n ) cout << ans[min(n,1)] << "\n";
	return 0;
}
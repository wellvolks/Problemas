#include <bits/stdc++.h>

using namespace std;


int main(){
	ios::sync_with_stdio(false);
	int a;
	cin >> a;
	cout << fixed << setprecision(1) << (pow((1+sqrt(5))/2., a)-pow((1-sqrt(5))/2., a))/sqrt(5) << '\n';
	return 0;
}
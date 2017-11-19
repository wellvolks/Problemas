#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int a, b;
	cin >> a >> b;
	if( a > b ){
		if( b <= 96 && b >= 3 ) cout << "minguante\n";
		else if( b <= 2 ) cout << "nova\n";
		else if( b <= 96 ) cout << "crescente\n";
		else if( b <= 100 ) cout << "cheia\n";
	}
	else{
		if( b <= 2 ) cout << "nova\n";
		else if( b <= 96 ) cout << "crescente\n";
		else if( b <= 100 ) cout << "cheia\n";
	}
	return 0;
}
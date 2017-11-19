#include <bits/stdc++.h>
#define INF 0x3F3F3F3F 
#define LINF 0x3F3F3F3FFFFFFFFFLL 

using namespace std;

typedef long long int64; 
typedef unsigned long long uint64; 

int main(){
	ios::sync_with_stdio(false);
	long long x;
	int y;
	cin >> x >> y;
	for(int i = 0; i < y; i++ ){
		if( i ) cout << " ";
		cout << x;
		x *= 10LL;
	}
	cout << '\n';
	return 0;
}
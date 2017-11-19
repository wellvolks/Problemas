#include <bits/stdc++.h>
#define INF 0x3F3F3F3F 
#define LINF 0x3F3F3F3FFFFFFFFFLL 

using namespace std;

typedef long long int64; 
typedef unsigned long long uint64; 

int main(){
	ios::sync_with_stdio(false);
	long long a, b;
	cin >> a >> b;
	for( long long i = min(a,b); i <= max(a,b); i++ ) cout << i << " ";
	cout << '\n';
	return 0;
}
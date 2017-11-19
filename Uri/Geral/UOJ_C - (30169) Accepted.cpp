#include <bits/stdc++.h>
#define INF 0x3F3F3F3F 
#define LINF 0x3F3F3F3FFFFFFFFFLL 

using namespace std;

typedef long long int64; 
typedef unsigned long long uint64; 

int main(){
	ios::sync_with_stdio(false);
	double x, y, tot = 0;
	int qt = 0;
	cin >> x >> y;
	while( tot < y ){
		tot += x/2.;
		qt++;
	}
	cout << qt-1 << '\n';
	return 0;
}
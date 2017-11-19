#include <bits/stdc++.h>
#define INF 0x3F3F3F3F 
#define LINF 0x3F3F3F3FFFFFFFFFLL 

using namespace std;

typedef long long int64; 
typedef unsigned long long uint64; 

int main(){
	ios::sync_with_stdio(false);
	double x, y, tot = 0;
	int qt = 1;
	cin >> x >> y;
	while( tot < y ){
		tot -= (tot*0.10);
		tot += x;
		qt++;
	}
	cout << qt-1 << '\n';
	return 0;
}
#include <bits/stdc++.h>
#define INF 0x3F3F3F3F 
#define LINF 0x3F3F3F3FFFFFFFFFLL 

using namespace std;

typedef long long int64; 
typedef unsigned long long uint64; 

int64 mat[100][100];

int main(){
	ios::sync_with_stdio(false);
	uint64 a, b, tota, totb;
	cin >> a >> b;
	totb = (b*(b+1LL))/2LL;
	tota = ((a-1LL)*(a))/2LL;
	cout << (totb - tota) << '\n';
	return 0;
}
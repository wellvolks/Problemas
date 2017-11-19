#include <bits/stdc++.h>
#define INF 0x3F3F3F3F 
#define LINF 0x3F3F3F3FFFFFFFFFLL 

using namespace std;

typedef long long int64; 
typedef unsigned long long uint64; 

int vet[10000];

int main(){
	ios::sync_with_stdio(false);
	int t, n, val, k = 1;
	cin >> t;
	while( t-- ){
		cin >> n;
		int maior = 0;
		for( int i = 0; i < n; i++ ){
			cin >> val;
			maior = max(maior,val);
		}
		cout << "Case " << k++ << ": " << maior << "\n";
	}
	return 0;
}
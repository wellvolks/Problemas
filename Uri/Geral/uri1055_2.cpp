#include <bits/stdc++.h>
#include <tr1/unordered_map>

using namespace std;
using namespace tr1;

typedef long long int64;
typedef unsigned long long uint64;

int vet[100];
int resp[100];

int main(){
    ios::sync_with_stdio(false);
    int t, n, w = 1;
    cin >> t;
    while( t-- ){
    	cin >> n;
    	for( int i = 0; i < n; i++ ) cin >> vet[i];
    	sort(vet,vet+n);
    	int lo = 0, hi = n-1, p1 = 0, p2 = n-1;
    	int ans = 0, k = 0;
    	while( lo < hi ){
    		cout << p1 << " " << p2 << "\n";
    		if( k & 1 ){
    			resp[lo++] = vet[p1++];
    			if( lo <= hi ) resp[hi--] = vet[p1++];
    		}
    		else{
    			resp[lo++] = vet[p2--];
    			if( lo <= hi ) resp[hi--] = vet[p2--];
    		}
    		k++;
    	}
    	cout << resp[0];
    	for( int i = 1; i < n; i++ ){
    		ans += abs(resp[i]-resp[i-1]);
    		cout << " " << resp[i];
    	}
    	cout << "\n";
    	cout << "Case " << w++ << ": " << ans << "\n";
    }
    return 0;
}
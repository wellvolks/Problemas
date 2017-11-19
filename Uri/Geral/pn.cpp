#include <bits/stdc++.h>
#define INF 0x3F3F3F3F 
#define LINF 0x3F3F3F3FFFFFFFFFLL 

using namespace std;

typedef long long int64; 
typedef unsigned long long uint64; 

int64 fastexp(int64 a,int b, int64 mod){ 
    int64 x; 
    if(b==0) return 1LL; 
    if(b==1) return a; 
    if(b%2==0){ 
        x = fastexp(a,b>>1, mod) % mod; 
        return (x*x) % mod; 
    } 
    else return (a*fastexp(a,b-1, mod)) % mod; 
} 

int main(){
	ios::sync_with_stdio(false);
	int64 mod = 2147483647LL;
	int r = 0;
	cin >> r;
	if( r == 0 ) cout << "1\n";
	else cout << fastexp(3LL, r, mod) << "\n";
	return 0;
}
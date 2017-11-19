#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long int64;
typedef unsigned long long uint64;
 
 
 #ifdef _WIN32 
    #define getchar_unlocked getchar
#endif
  
inline bool read( int &n ) {
    n = 0;
    register bool neg = false;
    register char c = getchar_unlocked();
    if( c == EOF) { n = -1; return false; }
    while (!('0' <= c && c <= '9')) {
        if( c == '-' ) neg = true;
        c = getchar_unlocked();
    }
    while ('0' <= c && c <= '9') {
        n = n * 10 + c - '0';
        c = getchar_unlocked();
    }
    n = (neg ? (-n) : (n));
    return true;
}
 
int vet[100002];
 
int main(){
    ios::sync_with_stdio(false);
    int t, k = 1, n;
    read(t);
    while( t-- ){
        cout << "Caso #" << k++ << ": ";
        read(n);
        int maior = 0;
        for( int i = 0; i < n; i++ ){
        	read(vet[i]);
        	maior = max(maior,vet[i]);
        }
        int ans = 1;
        for( int i = 0; i < n; i++ ){
        	if( vet[i] == maior ){
        		int j = i;
        		while( j < n && vet[j] == maior ) j++;
        		if( i != j ) j--;
        		ans = max(ans, (j - i)+1);
        		i = j;
        	}
        }
        cout << ans << "\n";
    }
    return 0;
}
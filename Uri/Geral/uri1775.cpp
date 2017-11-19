#include <bits/stdc++.h>
  
using namespace std;
  
typedef long long int64;
typedef unsigned long long uint64;

#ifdef _WIN32
    #define getchar_unlocked getchar
    #define putchar_unlocked putchar
#endif
   
   
bool read( int &n ) {
    n = 0LL;
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
 
inline void writeInt(int n){
    register int idx = 20;
    if( n < 0 ) putchar_unlocked('-');
    n = abs(n);
    char out[21];
    out[20] = ' ';
    do{
        idx--;
        out[idx] = n % 10 + '0';
        n/= 10;
    }while(n);
    do{ putchar_unlocked(out[idx++]); } while (out[idx] != ' ');
}

int dp[1001][1001];
int used[1001][1001], vis = 1;
int vet[100001], n;

void solve( int lo, int hi ){
    if( lo == hi ){ dp[lo][hi] = 1; return; }
    if( lo > hi ){ dp[lo][hi] = 0; return; }
    int &ans = dp[lo][hi];
    int &us = used[lo][hi];
    if( us == vis ) return ;
    us = vis;
    ans = 1e9;
    if( vet[lo] == vet[hi] && lo+1 <= hi && lo+1 < n && hi-1 >= 0 && hi-1 >= lo){
    	solve(lo+1,hi-1);
    	ans = dp[lo+1][hi-1]+1;
    }
    //else{
	    if( lo+1 <= hi && lo+1 < n ){
	        solve(lo+1,hi);
	        ans = min(ans,dp[lo+1][hi]+1);
	    }
	    if( hi-1 >= 0 && hi-1 >= lo ){
	        solve(lo,hi-1);
	        ans = min(ans, dp[lo][hi-1]+1);
	    }
	//}
}

int main(){
    int t, k = 1;
    read(t);
    while( t-- ){
        read(n);
        for( int i = 0; i < n; i++ ){
            read(vet[i]);
        }
        solve(0,n-1);
        cout << "Caso #" << k++ << ": " << dp[0][n-1] << '\n';
        vis++;
    }
    return 0;
}

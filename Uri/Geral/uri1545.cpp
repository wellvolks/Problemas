#include <bits/stdc++.h>
 
using namespace std;

#include <bits/stdc++.h>

using namespace std;


#ifdef _WIN32  
    #define getchar_unlocked getchar 
    #define putchar_unlocked putchar 
#endif 
   
inline bool read( int  &n ) { 
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
   
inline void writeInt(long long n){ 
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


long long dp[20011][2];
long long vet[10001];

int main(){
	ios::sync_with_stdio(false);
	int n;
	while( cin >> n ){
		for( int i = 0; i < n; i++ ) cin >> vet[i];
        memset(dp,0,sizeof(dp));
        int cur = 1;
        for( int tam = 2; tam <= n; tam += 2 ){
            for( int i = 0, j = tam-1; j < n; i++, j++ ){
                dp[i][cur] = max(vet[i] + dp[i+1][1-cur],
                             max(vet[j] + dp[i+1][1-cur],
                             max(vet[i] + dp[i+2][1-cur],
                                 vet[j] + dp[i][1-cur])));
            }
            cur = 1-cur;
        }
		cout << dp[0][1-cur] << "\n";
	}
	return 0;
}
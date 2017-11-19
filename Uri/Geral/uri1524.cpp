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


struct tri{
	int a, b, c;
};

int n, k;
long long dp[1001][1001];
int used[1001][1001], vis = 1;
long long vet[10001];

long long solve( int at, int qt ){
	if( at >= n ) return ((qt == k) ? (0) : (1e9));
	long long &ans = dp[at][qt];
	int &us = used[at][qt];
	if( us == vis ) return ans;
	us = vis;
	ans = 1e9;
	ans = min(solve(at+1,qt)+vet[at]-vet[at-1], solve(at+1,qt+1));
	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	int val;
	while( read(n) ){
		read(k);
		vet[0] = 0;
		for( int i = 1; i < n; i++ ){ read(val); vet[i] = val; }
		writeInt(solve(1,1));
		putchar_unlocked('\n');
		vis++;
	}
	return 0;
}
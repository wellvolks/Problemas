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

vector < vector < int > > vet;

int main(){
    ios::sync_with_stdio(false);
    int n, qt, val;
    while( read(n) && n ){
    	vet.resize(n);
    	int m = 0;
    	for( int i = 0; i < n; i++ ){
    		read(qt);
    		vet[i].resize(1001,0);
    		for( int j = 0; j < qt; j++ ){
    			read(val);
    			m = max(m, val);
    			vet[i][val]++;
    		}
    		for( int j = 1; j <= 1000; j++ ) vet[i][j] = vet[i][j-1] + vet[i][j];
    	}
    	int ans = 1e9;
    	for( int i = 0; i <= m; i++ ){
    		int acm = 0;
    		for( int j = 0; j < n; j++ ){
    			int hi = vet[j][1000] - vet[j][i];
    			int lo = vet[j][i];
    			acm += abs(lo-hi);
    		}
    		ans = min(ans, acm);
    	}
    	writeInt(ans);
    	putchar_unlocked('\n');
    	vet.clear();
    }
    return 0;
}
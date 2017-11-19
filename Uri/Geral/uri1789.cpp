#include <bits/stdc++.h>
#include <tr1/unordered_map>

using namespace std;

#ifdef _WIN32  
    #define getchar_unlocked getchar 
    #define putchar_unlocked putchar 
#endif 
   
bool read( int &n ) { 
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
   
inline void writeInt(int n){ 
    register int idx = 30; 
    char out[31]; 
    out[30] = ' '; 
    do{ 
        idx--; 
        out[idx] = n % 10 + '0'; 
        n/= 10; 
    }while(n); 
    do{ putchar_unlocked(out[idx++]); } while (out[idx] != ' '); 
} 

int main(){
	ios::sync_with_stdio(false);
	int n, val, maior = 0;
	while( read(n) ){
		maior = 0;
		for( int i = 0; i < n; i++ ){
			read(val);
			maior = max(maior,val);
		}
		if( maior < 10 ) writeInt(1);
		else if( maior >= 10 && maior < 20 ) writeInt(2);
		else writeInt(3);
		putchar_unlocked('\n');
	}
	return 0;
}
#include <bits/stdc++.h>
#include <tr1/unordered_map>

using namespace std;
using namespace tr1;

typedef long long int64;
typedef unsigned long long uint64;
#ifdef _WIN32  
    #define getchar_unlocked getchar 
    #define putchar_unlocked putchar 
#endif 
   
inline void read( int &n ) { 
    n = 0; 
    register bool neg = false; 
    register char c = getchar_unlocked(); 
    if( c == EOF) { n = -1; return; } 
    while (!('0' <= c && c <= '9')) { 
        if( c == '-' ) neg = true; 
        c = getchar_unlocked(); 
    } 
    while ('0' <= c && c <= '9') { 
        n = n * 10 + c - '0'; 
        c = getchar_unlocked(); 
    } 
    n = (neg ? (-n) : (n)); 
} 
 
int main(){
	ios::sync_with_stdio(false);
	int n, q, k, m;
	string str;
	while( true ){
		read(n);
		read(q);
		if( !(n+q) ) break;
		str = "";
		char c;
		for( int i = 0; i < n; i++ ){
			c = getchar_unlocked();
			str += c;
		}
		int vet[n];
		while( q-- ){
			read(k); read(m);
			memset(vet,0,sizeof(vet));
			int p = 0, t = 0;
			char at[200];
			at['x'] = 'o';
			at['o'] = 'x';
			while( t < m && !vet[p] ){
				vet[p] = 1;
				p += k;
				p %= n;
				t++;
			}
			for( int j = 0; j < (m%t) && t < m; j++ ){
				vet[p]++;
				p += k;
				p %= n;
			}
			
			string resp = "";
			for( int i = 0; i < n; i++ ){
				if( vet[i] ){
					int tot = (m/t) + (vet[i]-1);
					if( tot & 1 ) putchar_unlocked(at[str[i]]);
					else putchar_unlocked(str[i]);
				}
				else putchar_unlocked(str[i]);
			}
			putchar_unlocked('\n');
		}
	}
	return 0;
}
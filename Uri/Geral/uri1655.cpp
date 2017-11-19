#include <bits/stdc++.h>
 
using namespace std;

 #ifdef _WIN32  
    #define getchar_unlocked getchar 
    #define putchar_unlocked putchar 
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
    if( c == EOF) { n = -1; return false; }
    while ('0' <= c && c <= '9') { 
        n = n * 10 + c - '0'; 
        c = getchar_unlocked(); 
    } 
    n = (neg ? (-n) : (n)); 
    return true;
} 

int main(){
	ios::sync_with_stdio(false);
	double mat[110][110];
	int cust;
	int de, para, n, m;
	cout << fixed << setprecision(6);
	while( read(n) && read(m) && n ){
		memset(mat,0,sizeof(mat));
		for( int i = 0; i < m; i++ ){
			read(de); read(para); read(cust);
			mat[de-1][para-1] = mat[para-1][de-1] = double(cust)/100.;
		}
		for( int k = 0; k < n; k++ ){
			for( int i = 0; i < n; i++ ){
				for( int j = 0; j < n; j++ ){
					mat[i][j] = max(mat[i][j],mat[i][k]*mat[k][j]);
				}
			}
		}
		cout << (mat[0][n-1]*100.) << " percent\n";
	}
	return 0;
}
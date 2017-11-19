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

int n;
char dp[110][110][110];
char used[110][110][110], vis = 1;
char eh[30];
tri vet[110];

char solve( int a, int b, int c ){
	if( a == 0 && b == 0 && c == 0 ) return 1;
	char &ans = dp[a][b][c];
	char &us = used[a][b][c];
	if( us == vis ) return ans;
	us = vis;
	ans = 0;
	if( a > 0 && eh[vet[a].a] ) ans = ans || solve(a-1, b, c); if( ans ) return 1;
	if( b > 0 && eh[vet[b].b] ) ans = ans || solve(a, b-1, c); if( ans ) return 1;
	if( c > 0 && eh[vet[c].c] ) ans = ans || solve(a, b, c-1); if( ans ) return 1;
	if( a > 0 && b > 0 && eh[vet[a].a+vet[b].b] ) ans = ans || solve(a-1,b-1,c); if( ans ) return 1;
	if( a > 0 && c > 0 && eh[vet[a].a+vet[c].c] ) ans = ans || solve(a-1,b,c-1); if( ans ) return 1;
	if( b > 0 && c > 0 && eh[vet[b].b+vet[c].c] ) ans = ans || solve(a,b-1,c-1); if( ans ) return 1;
	if( a > 0 && b > 0 && c > 0 && eh[vet[a].a+vet[b].b+vet[c].c] ) ans = ans || solve(a-1,b-1,c-1);
	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	for( int i = 0; i <= 9; i++ ) for( int j = 0; j <= 9; j++ ) for( int w = 0; w <= 9; w++ ) if( !((i+j+w)%3) ) eh[i+j+w] = 1;
	while( read(n) && n ){
		vet[0].a = vet[0].b = vet[0].c = 0;
		for( int i = 1; i <= n; i++ ){
			read(vet[i].a); read(vet[i].b); read(vet[i].c);
		}
		writeInt(solve(n, n, n));
		putchar_unlocked('\n');
		vis++;
	}
	return 0;
}
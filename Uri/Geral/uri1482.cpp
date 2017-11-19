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
   

void writeInt(int n){ 
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

int n;
int vet[100];
int used[22][430], vis = 1;
int opa[(1<<20)+10], vis2 = 1;
int dist[22][22];

int solve(int at, int tempo, int mask){
	if( tempo > 420 ) return -1e9;
	if(used[at][tempo] == vis) return -1e9;
	if(opa[mask] == vis2) return -1e9;
	used[at][tempo] = vis;
	opa[mask] == vis2;
	int ans = 0;
	for(int i = 0; i < n; i++){
		if( i == at || mask & (1 << i)) continue;
		ans = max(ans, solve(i,tempo+dist[at][i]+vet[i], mask|(1<<i))+1);
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	while(read(n) && n){
		for( int i = 0; i < n; i++ ) read(vet[i]);
		for( int i = 0; i < n; i++ ){
			for(int j = 0; j < n; j++ ){
				read(dist[i][j]);
			}
		}
		int ans = 0;
		for(int i = 0; i < n; i++){
			ans = max(ans, solve(i,vet[i],1<<i)+((vet[i] <= 420) ? (1): (0)));
			vis++;
			vis2++;
		}
		writeInt(ans);
		putchar_unlocked('\n');
		vis++;
	}

	return 0;
}
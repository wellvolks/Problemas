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

int mat[1001][1001];
int x[] = {0,-1,1,0,-1,1,1,-1};
int y[] = {1,0,0,-1,-1,1,-1,1};
int n, m;
	
bool check(int xx, int yy){
	for(int i = 0; i < 8; i++){
		int a = xx+x[i];
		int b = yy+y[i];
		if( a < 0 || b < 0 || a >= n || b >= m || mat[a][b] != 7 ) return false;
	}
	return true;
}

int main(){
	ios::sync_with_stdio(false);
	read(n);
	read(m);
	vector < pair < int, int > > vet;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			read(mat[i][j]);
			if( mat[i][j] == 42 && i && j && i+1 < n && j+1 < m ) vet.push_back(make_pair(i,j));
		}
	}
	for(int i = 0, sz = vet.size(); i < sz; i++){
		if(check(vet[i].first, vet[i].second)){
			writeInt(vet[i].first+1); putchar_unlocked(' ');
			writeInt(vet[i].second+1); putchar_unlocked('\n');
			return 0;
		}
	}
	writeInt(0); putchar_unlocked(' ');
	writeInt(0); putchar_unlocked('\n');
	return 0;
}
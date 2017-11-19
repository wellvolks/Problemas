#include <bits/stdc++.h>

using namespace std;

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

struct tri{
	int de, para, custo;
	tri(int de = 0, int para = 0, int custo = 0) : de(de), para(para), custo(custo) { }
	bool operator < (const tri &a) const{
		if( custo != a.custo ) return custo < a.custo;
		if( de != a.de ) return de < a.de;
		return para < a.para;
	}
};

int used[1000][1000], vis = 1;
vector < tri > grafo;
int grau[110];
int pai[1000], rk[1000];

void init(int n){
	for(int i = 0; i <= n; i++){
		pai[i] = i;
		rk[i] = 0;
	}
}

int find(int u){
	int a = pai[u];
	while( a != pai[a] ) a = pai[a];
	int b = u;
	while( b != a ){
		int c = pai[b];
		pai[b] = a;
		b = c;
	}
	return a;
}

void merge(int u, int v, int a, int b){
	if(a == b) return;
	if(rk[b] > rk[a]) swap(a,b);
	if(rk[a] == rk[b]) rk[a]++;
	pai[b] = a;	
}

int main(){
	ios::sync_with_stdio(false);
	int t, n, m, de, para;
	read(t);
	while( t-- ){
		read(n); read(m);
		for( int i = 0; i < m; i++ ){
			read(de); read(para);
			used[de][para] = vis;
			used[para][de] = vis;
		}
		if( m == 0 ){
			writeInt(0);
			putchar_unlocked('\n');
			continue;
		}
		for(int i = 0; i < n; i++){
			for( int j = i+1; j < n; j++ ){
				grafo.push_back(tri(i,j,used[i][j] == vis));
				grafo.push_back(tri(j,i,used[j][i] == vis));
			}
		}
		init(n+10);
		sort(grafo.begin(), grafo.end());
		int ans = 0;
		for( int i = 0, sz = grafo.size(); i < sz; i++ ){
			tri at = grafo[i];
			int a = find(at.de);
			int b = find(at.para);
			if( a != b ){
				merge(at.de, at.para, a, b);
				ans += at.custo;
			}
		}
		writeInt(ans);
		putchar_unlocked('\n');
		grafo.clear();
		vis++;
	}
	return 0;
}
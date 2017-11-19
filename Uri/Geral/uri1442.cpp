#include <tr1/unordered_map>
#include <map>
#include <set>
#include <list>
#include <stack>
#include <cmath>
#include <queue>
#include <ctime>
#include <cfloat>
#include <vector>
#include <string>
#include <cstdio>
#include <bitset>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <iomanip>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>
  
using namespace std;
using namespace tr1;
  
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define RFOR(i, b, a) for(int i = b; i >= a; --i)
#define REP(i, N) for(int i = 0; i < N; ++i)
#define RREP(i, N) for(int i = N-1; i >= 0; --i)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )
#define MAXN 10000
#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFFLL
#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) __typeof((X).begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) int((V).size())
#define pb push_back
#define mp make_pair
  
struct tri{
    int atual, tipo;
    tri ( int atual = 0, int tipo = 0) : atual(atual), tipo(tipo) { }
};
  
int n, m;
typedef vector < int > vi;
typedef vector < vi > vii;
typedef vector < tri > vtri;
typedef vector < vtri > vvtri;
typedef long long int64;
typedef unsigned long long uint64;
 
#ifdef _WIN32 
    #define getchar_unlocked getchar
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

int unidire[1010][10010], dire[1010][10010], puni[1010], pdire[1010];
int qt, flag = 0;
int restrito[1010][1010], visitado[1010], vis = 1, vis2 = 1, vis3 = 1;
int dfs_low1[1010], dfs_num1[1010], dfsNumber, dfs_parent1[1010], contadorVertice[1010];
int dfs_low2[1010], dfs_num2[1010], dfs_parent[1010], S[1010], pos = 0;

int min(int a, int b){ return (a < b) ? a : b; }
int max(int a, int b){ return (a > b) ? a : b; }

void tarjanSCC(int u){
	if(qt) return ;
	dfs_low1[u] = dfs_num1[u] = dfsNumber++;
	S[pos++] = u;
	register int tam  = pdire[u], v, j, cnt, vv;
	for(j = 0; j < tam; j++){
		v = dire[u][j];
		if(dfs_num1[v] == -1) tarjanSCC(v);
		if(qt) return ;
		if(visitado[v] != vis2) dfs_low1[u] = min(dfs_low1[u],dfs_low1[v]);
	}
	if(dfs_low1[u] == dfs_num1[u]){
		cnt = 0;
		while(1){
			vv = S[pos-1]; pos--; visitado[vv] = vis2;
			if(contadorVertice[vv] != vis3) cnt++;
			contadorVertice[vv] = vis3;
			if( u == vv) break;
			if(!pos) break;
		}
		if( cnt == n ) qt = 1;
		vis3++;
	}
}

void verificaPontes(int u){
	dfs_low2[u] = dfs_num2[u] = dfsNumber++;
	register int tam = puni[u], j, v;
	if(qt == n) return;
	for(j = 0; j < tam; j++){
		v = unidire[u][j];
		if(dfs_num2[v] == -1){
			qt++;
			dfs_parent[v] = u;
			verificaPontes(v);
			if(dfs_low2[v] > dfs_num2[u]){
				if(restrito[u][v] == vis) flag = 1;
			}
			dfs_low2[u] = min(dfs_low2[u], dfs_low2[v]);
		}
		else if(v != dfs_parent[u]) dfs_low2[u] = min(dfs_low2[u], dfs_num2[v]);
	}
}

int main(){
	int de, para, i;
	int  op;
	ios::sync_with_stdio(false);
	read(n);
	while(n != -1){
		read(m);
		pos = dfsNumber = qt = 0;
		for(i = 0; i < n; i++){ dfs_num1[i] = dfs_num2[i] = -1; pdire[i] = puni[i] = 0; }
		for(i = 0; i < m; i++){
			//scanf("%d %d %c",&de,&para,&op); 
			read(de); read(para);
			read(op);
			de--; para--;
			if(!i) continue;
			dire[de][pdire[de]++] = para;
			unidire[de][puni[de]++] = para;
			unidire[para][puni[para]++] = de;
			if(op == 2) dire[para][pdire[para]++] = de;
			else restrito[de][para] = restrito[para][de] = vis;
		}
		tarjanSCC(0);
		if(qt == 1) puts("-");
		else{
			dfsNumber = qt = 0;
			verificaPontes(0);
			if(qt != n - 1) puts("*");
			else if(flag) puts("2");
			else puts("1");
		}
		vis++; vis2++; vis3++; flag = 0;
		read(n);
	}
	return  0;
}


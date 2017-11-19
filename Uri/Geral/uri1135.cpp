#include <iostream>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#define MAXN 100010
using namespace std;
 
struct tri{
    int para;
    unsigned long long int custo;
    tri(int para = 0, unsigned long long int custo = 0) : para(para), custo(custo) { }
};
 
vector < vector < tri > > grafo;
 
int nodedad[ MAXN ];
int treesize[ MAXN ];
int chain[ MAXN ];
int homepos[ MAXN ];
int pos, cntchain, vezes = 1;
int chainleader[ MAXN ];
unsigned long long int bl[100010];
 
 

 #ifdef _WIN32
    #define getchar_unlocked getchar
#endif

inline bool readInt( int &n ) {
    n = 0;
    bool neg = false;
    char c = getchar_unlocked();
    if( c == EOF){ n = 0; return false; }
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
inline void readLong( unsigned long long &n ) {
    n = 0;
    bool neg = false;
    char c = getchar_unlocked();
    if( c == EOF){ n = -400; return; }
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

 
void explore( int x, int dad, int cust) {
    if( nodedad[x] != -1 ) return;
    nodedad[x] = dad;
    treesize[x] = 1;
	 if( dad != 0 ) bl[x-1] += bl[dad-1] + cust;
    for( int i = 0; i < ( int )grafo[x].size(); ++i ){
        if( grafo[x][i].para != dad ) {
			explore( grafo[x][i].para, x, grafo[x][i].custo );
            treesize[x] += treesize[ grafo[x][i].para ];
        }
    }
}
 
void heavy_light( int x, int dad, int k, int p ) {
    if( p == 0 ){
        k = cntchain++;
        chainleader[k] = x;
    }
    chain[x] = k;
    homepos[x] = pos++;
    int mx = -1;
    for( int i = 0; i < ( int )grafo[x].size(); ++i )
        if(grafo[x][i].para != dad && (mx == -1 || treesize[grafo[x][i].para] > treesize[ grafo[x][mx].para])) mx = i;
    if( mx != -1 ) heavy_light( grafo[x][mx].para, x, k, p+1 );
    for( int i = 0; i < ( int )grafo[x].size(); ++i )
        if( grafo[x][i].para != dad && i != mx ) heavy_light( grafo[x][i].para, x, -1, 0 );
}
 
int lca(int a, int b) {
    while (chain[a] != chain[b]) {
        if (treesize[chainleader[chain[a]]] >= treesize[chainleader[chain[b]]]) b = nodedad[chainleader[chain[b]]];
        else a = nodedad[chainleader[chain[a]]];
    }
    if (treesize[a] < treesize[b]) return b;
    return a;
}
 
int main(){
    int n, de, para, q, d;
    unsigned long long  cust;
    while(readInt(n) && n){
        grafo.resize(n+1);
        for(int i = 0; i < n-1; i++){
            //scanf("%d %lld",&de,&cust);
            readInt(de); readLong(cust);
			grafo[de+1].push_back(tri(i+2,cust));
            nodedad[i] = nodedad[i+1] = nodedad[i+2] = -1;
			bl[i] = bl[i+1] = bl[i+2] = 0;
        }
        explore(1,0, 0);
        pos = 0; cntchain = 0;
        heavy_light(1, 0, -1, 0);
        //BFS();
       // scanf("%d",&q);
        readInt(q);
		for(int i = 0; i < q; i++){
            //scanf("%d %d",&de,&para);
            readInt(de); readInt(para);
			d = lca(de+1,para+1);
            cust = (bl[de] + bl[para]) - 2*bl[d-1];
            printf("%lld",cust);
            if(i + 1 != q) printf(" ");
        }
        printf("\n");
        grafo.clear();
    }
    return 0;
}
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <stdlib.h>
#include <math.h>
#include <queue>
#include <stack>
#include <map>
#include <iomanip>
#include <algorithm>
using namespace std;

#define For(i,n) for(int i = 0; i < n; i++)
#define FOR(i,b,n) for(int i = b; i < n; i++)
#define mset(vet,b,c) memset(&vet, b, sizeof(c))
#define MAXN 10000
#define INF 0x3f3f3f3f
#define pb push_back
#define mk make_pair

struct tri{
	int atual, custo;
	tri ( int atual = 0, int custo = 0) : atual(atual), custo(custo) { }
};

struct estado{
	int qt, id;
	estado(int qt = 0, int id = 0) : qt(qt), id(id) { }
};

estado sorteio[10010];
typedef vector < int > vi;
typedef vector < vi > vii;
typedef vector < tri > vtri;
typedef vector < vtri > vvtri;

bool compare(const estado &a, const estado &b){
	if(a.qt != b.qt) return a.qt < b.qt;
	return a.id < b.id;
}

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

int main(){
	register int n, c, k, num, at, pos;
	read(n); read(c); read(k);
	while((n+c+k)){
		For(i,k){sorteio[i].qt = 0; sorteio[i].id = i; }
		pos = 0;
		For(i,n){
			For(j, c){
				read(num);
				sorteio[num-1].qt++;
			}
		}
		sort(sorteio, sorteio + k, compare);
		at = sorteio[0].qt;
		cout << sorteio[pos++].id+1;
		while(at == sorteio[pos].qt && pos < k){
			printf(" %d",sorteio[pos++].id+1);
		}
		printf("\n");
		read(n); read(c); read(k);
	}
	return 0;
}


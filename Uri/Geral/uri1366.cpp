#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#define MAXN 530010
#include <sys/timeb.h>
#define For(i, n) for(int i = 0; i < n; i++)
#define FOR(i, r, n) for(int i = r; i <= n; i++)
#define MAXV 10010
#define mp make_pair
#define pb push_back
using namespace std;
int trocas = 0;
int vec[20000], posicao[20000];

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
	register int t, n;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for (int i = 1; i <= n; i++){ cin >> vec[i]; posicao[vec[i]] = i;}
		for (int i = 1; i <= n; i++) {
			if (vec[i] != i) {
				vec[posicao[i]] = vec[i];
				posicao[vec[i]] = posicao[i];
				vec[i] = posicao[i] = i;
				trocas++;
			}
		}
		fprintf(stdout,"%d\n",trocas);
		trocas = 0;
	}
	return 0;
}








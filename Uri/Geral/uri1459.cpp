#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

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
	int n=0;
    vector < pair<int,int> > vet(1000010);
    ios::sync_with_stdio(false);
	while(true){
		read(n);
		if( n == -1 ) break;
		int foto=1;
		int aux;
		for(int i=0; i<n; i++){
			read(vet[i].second);
			read(vet[i].first);
		}
		sort(vet.begin(),vet.begin()+n);  
		aux = vet[0].first;
		for(int i=1; i<n; i++){
			if(aux < vet[i].second ){
				aux = vet[i].first;
				foto++;
			}		
		}
		printf("%d\n",foto);;
	}
	return 0;
}


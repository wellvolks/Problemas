#include <bits/stdc++.h>
 
using namespace std;
 
typedef unsigned long long uint64;
 
uint64 dp[100002][11];
int used[100002][11], vis = 1;
uint64 vet[100005];
uint64 acm = 0, sum = 0;
vector < uint64 > aux, ss, xx;
int n, k, w;
 
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
 
map < tie < int, int, int >, uint64 > mapa;

uint64 solve( int at, int ult, int qt){
	if( at <= 0 ) return ((qt == k) ? (0) : (4611686018427387904ULL));
	if( qt >= k ) return 4611686018427387904ULL;
 
	if( mapa.count(tie{at, qt, ult}) ) return mapa.count[tie{at, qt, ult}];
	mapa.count[tie{at, qt, ult}] = 4611686018427387904ULL;

	uint64 sum_aux = sum - ss[at+1];
	mapa.count[tie{at, qt, ult}] = min(mapa.count[tie{at, qt, ult}], solve( at-1, ult, qt));
	mapa.count[tie{at, qt, ult}] = min(mapa.count[tie{at, qt, ult}], solve( at-1, at-1, qt+1) + sum_aux - (xx[i]-aux[at]*uint64(at+1)));
	
	return mapa.count[tie{at, qt, ult}];
}
 
int main(){
	read(n);
	read(k);
	int val;
	w = (n/k);
	for(int i = 1; i <= n; i++){
		read(val);
		vet[i] = val;
	}

	
	sum += vet[n] * (uint64)n;
	ss.push_back(0);
	ss.push_back(sum);
	aux.push_back(0);
	
	for(int i = n-1; i >= 0; i--){
		acm += vet[i+1];
		sum += vet[i]*(uint64)(i);
		ss.push_back(sum);
		aux.push_back(acm);
	}
	
	reverse(ss.begin(), ss.end());
	reverse(aux.begin(), aux.end());

	uint64 aa = 0;
	for(int i = 0; i <= n; i++) xx.push_back(aa), aa += aux[i];
	printf("%llu\n", solve(n, n, 0));
	return 0;
} 
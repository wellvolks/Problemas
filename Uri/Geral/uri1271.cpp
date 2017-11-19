#include <iostream>
#include <algorithm>
#include <ctype.h>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <vector>
#include <deque>
#include <set>
#include <iomanip>
#include <bitset>
#include <string>
#include <sstream>
#define INF 0x3f3f3f
#define For(i, n) for(register int i = 0; i < n; i++)
#define FOR(i, r, n) for(register int i = r; i < n; i++)
#define Max 100000
#define mp make_pair
#define pb push_back
#define dw -1
 
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef deque<int> di;
typedef vector<vi> vv;
 
int vet[50010], pos[50010];
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

inline void loucura(register int a, register int b){
	while(a < b){			
		pos[vet[a]] = b;
		pos[vet[b]] = a;
		swap(vet[a], vet[b]);
		a++;
		b--;
	}
}
 
int main(){
    register int n, r, q, a, b, cont = 1;
    while(true){
		scanf("%d",&n);
		if(!n)break;	
		a = 1; b = n;
		while(a <= b){
			vet[a] = pos[a] = a, vet[b] = pos[b] = b;
			a++;
			b--;
		}
        scanf("%d",&r);
        for(register int i = 0; i < r; i++){
			scanf("%d %d",&a, &b);
			loucura(a,b);            
        }
        scanf("%d",&q);
		printf("Genome %d\n", cont++);
		for(register int i = 0; i < q; i++){
            scanf("%d",&a);
            printf("%d\n", pos[a]);
        }
    }
 
    return 0;
}
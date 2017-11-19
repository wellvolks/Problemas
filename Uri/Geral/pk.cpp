#include <bits/stdc++.h>
#define INF 0x3F3F3F3F 
#define LINF 0x3F3F3F3FFFFFFFFFLL 

using namespace std;

typedef long long int64; 
typedef unsigned long long uint64; 

int tree [1000100];
 
int query(int tam, int a, int b) {
    if (a == 0) {
        int sum = 0;
        for (; b >= 0; b = (b & (b + 1)) - 1){
          sum += tree[b];
        }
        return sum; 
    } else {
        return query(tam, 0, b) - query(tam, 0, a-1);
    }
}

void increase(int tam, int k, int inc) {
    for (; k < tam+1; k |= k + 1){
        tree[k] += inc;
    }
}

void decrease(int tam, int k, int inc) {
    for (; k < tam+1; k |= k + 1){
        tree[k] -= inc;
   }
}

int vet[100000];

int main(){
	ios::sync_with_stdio(false);
    int n, val;
    string c;
    cin >> n;
    for( int i = 0; i < n; i++ ){
        cin >> val;
        vet[i] = val;
        increase(n+1,i,val);
    }

    while(cin >> c >> val){
        if( c == "a" ) decrease(n+1,val-1,vet[val-1]);
        else{
            if( val > 1 ) cout << query(n+1,0,val-2) << "\n";
            else cout << "0\n";
        }
    }
	return 0;
}
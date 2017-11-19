#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef unsigned long long uint64;

int tree [100100];
 
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
 
int main(){
	ios::sync_with_stdio(false);
	int n, q, a, b, e, p;
	cin >> n;
	for( int i = 0; i < n; i++ ){
		cin >> val;
		mapa[val] = i;
	}
	cin >> q;
	while( q-- ){
		cin >> op;
		switch(op){
			case 'I':
				cin >> e >> p;
				break;
			case 'R':
				cin >> e;
				break;
			case 'Q':
				cin >> a >> b;
				break;
		}
	}
	return 0;
}
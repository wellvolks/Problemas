#include <bits/stdc++.h>

using namespace std;

int mat[110];
int jogador[1000010];
int used[1000010], vis = 1;

int main(){
	ios::sync_with_stdio(false);
	int t, a, b, c, lo, hi, dado;
	cin >> t;
	while( t-- ){
		for( int i = 0; i < 100; i++ ) mat[i] = i;
		cin >> a >> b >> c;
		for( int i = 0; i < b; i++ ){
			cin >> lo >> hi;
			mat[lo-1] = hi-1;
		}
		int p = 0;
		bool fim = false;
		for( int i = 0; i < a; i++ ) jogador[i] = 0;
		while( c-- ){
			cin >> dado;
			if( fim ) continue;
			jogador[p] = (jogador[p] + dado);
			jogador[p] = min(jogador[p],99);
			jogador[p] = mat[jogador[p]];
			if( jogador[p] == 99 ) fim = true;
			p = (p + 1) % a;
		}
		for( int i = 0; i < a; i++ ) cout << "Position of player " << i+1 << " is " << jogador[i]+1 << ".\n";
		vis++;
	}
	return 0;
}
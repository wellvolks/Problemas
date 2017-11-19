#include <bits/stdc++.h>
#define INF 0x3F3F3F3F 
#define LINF 0x3F3F3F3FFFFFFFFFLL 

using namespace std;

typedef long long int64; 
typedef unsigned long long uint64; 

int vet[10000];

int main(){
	ios::sync_with_stdio(false);
	
	string vet;
	int m, k = 1, val;
	while( cin >> m && m ){
		vet = "";
		for( char i = 'A'; i <= 'Z'; i++ ) vet += i;
		cout << "Instancia " << k++ << '\n';
		for( int i = 0; i < m; i++ ){
			cin >> val;
			cout << vet[val-1];
			char at = vet[val-1];
			vet.erase(vet.begin()+(val-1));
			string aux = "";
			aux += at;
			aux += vet;
			vet = aux;
		}
		cout << "\n\n";
	}
}
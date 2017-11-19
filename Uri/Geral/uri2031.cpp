#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int d;
    cin >> d;
    string a, b;

    for(int i = 0; i < d; i++){
    	cin >> a >> b;
    	if( a == "ataque" ){
    		if( b == "pedra" || b == "papel" ) cout << "Jogador 1 venceu\n";
    		else cout << "Aniquilacao mutua\n";
    	}
    	else if( a == "papel" ){
    		if( b == "papel" ) cout << "Ambos venceram\n";
    		else if( b == "ataque" || b == "pedra") cout << "Jogador 2 venceu\n";
    	}
    	else{
    		if( b == "pedra" ) cout << "Sem ganhador\n";
    		else if( b == "ataque") cout << "Jogador 2 venceu\n";
    		else cout << "Jogador 1 venceu\n";
    	}
    }
    return 0;
}
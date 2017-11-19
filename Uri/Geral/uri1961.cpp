#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int p, n, at, ant;

    cin >> p >> n;

    cin >> ant;
    for(int i = 1; i < n; i++){
    	cin >> at;
    	if( abs(at-ant) > p ){
    		cout << "GAME OVER\n";
    		return 0;
    	}
    	ant = at;
    }

    cout << "YOU WIN\n";
    return 0;
}
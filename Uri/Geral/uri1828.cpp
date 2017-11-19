#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios::sync_with_stdio(false);
    map < string, map < string, int > > jogo;
    jogo["tesoura"]["papel"] = 1;
    jogo["papel"]["pedra"] = 1;
    jogo["pedra"]["lagarto"] = 1;
    jogo["lagarto"]["Spock"] = 1;
    jogo["Spock"]["tesoura"] = 1;
    jogo["tesoura"]["lagarto"] = 1;
    jogo["lagarto"]["papel"] = 1;
    jogo["papel"]["Spock"] = 1;
    jogo["Spock"]["pedra"] = 1;
    jogo["pedra"]["tesoura"] = 1;
    
    int t, k = 1;
    cin >> t;
    while( t-- ){
        string a, b;
        cin >> a >> b;
        cout << "Caso #" << k++ << ": ";
        if( jogo[a][b] && !jogo[b][a] ) cout << "Bazinga!\n";
        else if( !jogo[a][b] && jogo[b][a]) cout << "Raj trapaceou!\n";
        else cout << "De novo!\n";
    }
    return 0;
}
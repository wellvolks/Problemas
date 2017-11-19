#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios::sync_with_stdio(false);
    map < string, map < string, int > > jogo;
    jogo["tesoura"]["papel"] = 1;
    jogo["papel"]["pedra"] = 1;
    jogo["pedra"]["lagarto"] = 1;
    jogo["lagarto"]["spock"] = 1;
    jogo["spock"]["tesoura"] = 1;
    jogo["tesoura"]["lagarto"] = 1;
    jogo["lagarto"]["papel"] = 1;
    jogo["papel"]["spock"] = 1;
    jogo["spock"]["pedra"] = 1;
    jogo["pedra"]["tesoura"] = 1;
    
    int t, k = 1;
    cin >> t;
    while( t-- ){
        string aa, bb, a = "", b = "";
        cin >> bb >> aa;
        for( int i = 0; i < aa.size(); i++ ){
            a += tolower(aa[i]);
        }
        for( int i = 0; i < bb.size(); i++ ){
            b += tolower(bb[i]);
        }
        if( jogo[a][b] && !jogo[b][a] ) cout << "sheldon\n";
        else if( !jogo[a][b] && jogo[b][a]) cout << "rajesh\n";
        else cout << "empate\n";
    }
    return 0;
}
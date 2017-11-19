#include <bits/stdc++.h>
//#include <tr1/unordered_map>
 
using namespace std;
//using namespace tr1;
 
typedef long long int64;
typedef unsigned long long uint64;
 
map < string, string > mapa;
 
vector < int > vet;
 
 
int main(){
    ios::sync_with_stdio(false);
    mapa["brasil"]   =   "Feliz Natal!";
    mapa["alemanha"]   =   "Frohliche Weihnachten!";
    mapa["austria"]   =   "Frohe Weihnacht!";
    mapa["coreia"]   =   "Chuk Sung Tan!";
    mapa["espanha"]   =   "Feliz Navidad!";
    mapa["grecia"]   =   "Kala Christougena!";
    mapa["estados-unidos"]   =   "Merry Christmas!";
    mapa["inglaterra"]   =   "Merry Christmas!";
    mapa["australia"]   =   "Merry Christmas!";
    mapa["portugal"]   =   "Feliz Natal!";
    mapa["suecia"]   =   "God Jul!";
    mapa["turquia"]   =   "Mutlu Noeller";
    mapa["argentina"]   =   "Feliz Navidad!";
    mapa["chile"]   =   "Feliz Navidad!";
    mapa["mexico"]   =   "Feliz Navidad!";
    mapa["antardida"]   =   "Merry Christmas!";
    mapa["canada"]   =   "Merry Christmas!";
    mapa["irlanda"]   =   "Nollaig Shona Dhuit!";
    mapa["belgica"]   =   "Zalig Kerstfeest!";
    mapa["italia"]   =   "Buon Natale!";
    mapa["libia"]   =   "Buon Natale!";
    mapa["siria"]   =   "Milad Mubarak!";
    mapa["marrocos"]   =   "Milad Mubarak!";
    mapa["japao"]   = "Merii Kurisumasu!";
    string str;
    while( cin >> str ){
        if( mapa.count(str) ) cout << mapa[str] << "\n";
        else cout << "--- NOT FOUND ---\n";
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef unsigned long long uint64;
 
 
 #ifdef _WIN32 
    #define getchar_unlocked getchar
#endif
  
inline bool read( int &n ) {
    n = 0;
    register bool neg = false;
    register char c = getchar_unlocked();
    if( c == EOF) { n = -1; return false; }
    while (!('0' <= c && c <= '9')) {
        if( c == '-' ) neg = true;
        c = getchar_unlocked();
    }
    while ('0' <= c && c <= '9') {
        n = n * 10 + c - '0';
        c = getchar_unlocked();
    }
    n = (neg ? (-n) : (n));
    return true;
}

int vogal[300];

int main(){
    ios::sync_with_stdio(false);
    int l, n;
    string a, b;
    cin >> l >> n;
    vogal['a'] = vogal['e'] = vogal['i'] = vogal['o'] = vogal['u'] = 1;
    unordered_map < string, string > mapa;
    for( int i = 0; i < l; i++ ){
        cin >> a >> b;
        mapa[a] = b;
    }
    for( int i = 0; i < n; i++ ){
        cin >> a;
        int tam = a.size();
        if( mapa.count(a) ) cout << mapa[a] << "\n";
        else{
            if( tam >= 2 && !vogal[a[tam-2]] && a[tam-1] == 'y' ){
                a.pop_back();
                cout << a << "ies\n";
            }
            else if( tam >= 2){
                string aux = "";
                aux += a[tam-2];
                aux += a[tam-1];
                if( aux == "ch" || aux == "sh" ){
                    cout << a << "es\n";
                }
                else if(a[tam-1] == 'o' || a[tam-1] == 's' || a[tam-1] == 'x' ){
                    cout << a << "es\n";
                }
                else{
                    cout << a << "s\n";
                }
            }
            else if(a[tam-1] == 'o' || a[tam-1] == 's' || a[tam-1] == 'x' ){
                cout << a << "es\n";
            }
            else{
                cout << a << "s\n";
            }
        }
    }
    return 0;
}

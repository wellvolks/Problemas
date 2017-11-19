#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef unsigned long long uint64;

#ifdef _WIN32  
    #define getchar_unlocked getchar 
    #define putchar_unlocked putchar 
#endif 

inline void read( int &n ) {
    n = 0;
    register bool neg = false;
    register char c = getchar_unlocked();
    if( c == EOF) { n = -1; return; }
    while (!('0' <= c && c <= '9')) {
        if( c == '-' ) neg = true;
        c = getchar_unlocked();
    }
    while ('0' <= c && c <= '9') {
        n = n * 10 + c - '0';
        c = getchar_unlocked();
    }
    n = (neg ? (-n) : (n));
}

inline void writeInt(int n){ 
    register int idx = 20; 
    if( n < 0 ) putchar_unlocked('-'); 
    n = abs(n); 
    char out[21]; 
    out[20] = ' '; 
    do{ 
        idx--; 
        out[idx] = n % 10 + '0'; 
        n/= 10; 
    }while(n); 
    do{ putchar_unlocked(out[idx++]); } while (out[idx] != ' '); 
} 

map < string, map < string, int > > mapa;

int main(){
    ios::sync_with_stdio(false);
    int n;
    string nome, a, b, c;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> nome >> a >> b >> c;
        mapa[nome][a]++;
        mapa[nome][b]++;
        mapa[nome][c]++;
    }    
    while( cin >> nome >> a ){
        if( mapa[nome].count(a) ) cout << "Uhul! Seu amigo secreto vai adorar o/\n";
        else cout << "Tente Novamente!\n";
    }
    return 0;
}

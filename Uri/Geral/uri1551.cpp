#include <bits/stdc++.h>

using namespace std;

#ifdef _WIN32  
    #define getchar_unlocked getchar 
    #define putchar_unlocked putchar 
#endif 
   
inline bool read( long long &n ) { 
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
   
inline void writeInt(long long n){ 
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

int main(){
    ios::sync_with_stdio(false);
    string str;
    int t;
    cin >> t;
    cin.ignore();
    while( t-- ){
        getline(cin, str);
        int tam = str.size();
        map < char, int > mapa;
        for( int i = 0; i < tam; i++ ) if( isalpha(str[i]) ) mapa[str[i]]++;
        tam = mapa.size();
        if( tam == 26 ) cout << "frase completa\n";
        else if( tam >= 13 ) cout << "frase quase completa\n";
        else cout << "frase mal elaborada\n";
    }
    return 0;
}
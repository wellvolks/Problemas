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
 
char str[100000];

int solve( ){
    map < string, int > mapa;
    int tam = strlen(str);
    string st = "";
    st += str;
    while( !mapa.count(st) ){
        mapa[st]++;
        int val = 0;
        sscanf(str,"%d",&val);
        val *= val;
        sprintf(str,"%0*d", 2*tam, val);
        for( int i = 0; i < tam; i++ ){
            str[i] = str[i+(tam>>1)];
        }
        str[tam] = '\0';
        st = "";
        st += str;
    }
    return mapa.size();
}

int main(){
    ios::sync_with_stdio(false);
    while( cin >> str && strcmp(str,"0")){
        cout << solve() << '\n';
    }    
    return 0;
}


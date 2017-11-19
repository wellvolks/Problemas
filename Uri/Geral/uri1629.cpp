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
 
 
int main(){
    ios::sync_with_stdio(false);
    int t;
    while( cin >> t && t ){
        string str;
        for( int i = 0; i < t; i++ ){
            cin >> str;
            int tam = str.size();
            int ans = 0, zero = 0, one = 0;
            for( int j = 0; j < tam; j++ ){
                if( j & 1 ) one += (str[j]-'0');
                else zero += (str[j]-'0');
            }
            while( one ){
                ans += one % 10;
                one /= 10;
            }
            while( zero ){
                ans += zero % 10;
                zero /= 10;
            }
            cout << ans << '\n';
        }
    }
    return 0;
}


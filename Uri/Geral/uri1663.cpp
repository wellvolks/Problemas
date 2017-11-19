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

int vet[100002];
int main(){
    ios::sync_with_stdio(false);
    int t, val;
    while( read(t) && t ){
        memset(vet,0,sizeof(vet));
        for( int i = 1; i <= t; i++ ){
            read(val);
            vet[i] = val ;
        }
        bool ans = true;
        string resp[] = {"not ambiguous","ambiguous"};
        for( int i = 1; i <= t; i++ ){
            if( vet[vet[i]] != i ){
                ans = false;
                break;
            }
        }
        cout << resp[ans] << '\n';
    }
    return 0;
}

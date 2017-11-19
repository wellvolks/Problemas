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

int64 fibona[10000];

int64 fibo( int n ){
    if( n <= 1 ) return 1;
    if( fibona[n] != -1 ) return fibona[n];
    fibona[n] = fibo(n-1) + fibo(n-2);
}

bool check( int64 val ){
    while( val > 0 ){
        if( (val % 10) == 3 ) return true;
        val /= 10;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    memset(fibona,-1,sizeof(fibona));
    vector < int64 > resp;
    int n;
    for( int i = 1; i <= 100; i++ ){
        int64 ans = fibo(i);
        if( !(ans % 3LL) || check(ans) ) resp.push_back(ans); 
    }
    while( cin >> n ){
        cout << resp[n-1] << '\n';
    }
    return 0;
}

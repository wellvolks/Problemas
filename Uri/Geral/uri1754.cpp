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
    cin >> t;
    uint64 x, y;
    while( t-- ){
        cin >> x >> y;
        uint64 lo = 2, hi = 1e19, mid, ans = 0LL;
        while( lo <= hi ){
            mid = (lo+hi) >> 1LL;
            if( (mid*y) >= x ){
                ans = mid;
                hi = mid-1LL;
            }
            else lo = mid+1LL;
        }
        cout << ans << '\n';
    }
    return 0;
}

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
    int t, n;
    double d, val;
    cout << fixed << setprecision(2);
    cin >> t;
    while( t-- ){
        cin >> d >> n;
        double ans = 0.;
        for( int i = 0; i < n; i++ ){
            cin >> val;
            if( int(d/val) ) ans = max(ans,d - (val*floor(d/val)));
        }
        cout << ans << '\n';
    }
    return 0;
}

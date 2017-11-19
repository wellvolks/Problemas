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
    int n;
    while( cin >> n && n){
        int64 val, ans = 0LL;
        priority_queue < pair < int, int64 > > vender, receber;
        for( int i = 0; i < n; i++ ){
            cin >> val;
            if( val == 0 ) continue;
            if( val > 0 ){
                while( !vender.empty() && val != 0 ){
                    pair < int, int64 > at = vender.top();
                    vender.pop();
                    if( at.second >= val ){
                        ans += int64((i+1) - abs(at.first))*val;
                        at.second -= val;
                        val = 0LL;
                        if( at.second ) vender.push(at);
                    }
                    else{
                        ans += int64((i+1) - abs(at.first))*at.second;
                        val -= at.second;
                    }
                }
                if( val != 0 ) receber.push(make_pair(-(i+1),val));
            }
            else{
                val = -val;
                while( !receber.empty() && val != 0 ){
                    pair < int, int64 > at = receber.top();
                    receber.pop();
                    if( at.second >= val ){
                        ans += int64((i+1) - abs(at.first))*val;
                        at.second -= val;
                        val = 0LL;
                        if( at.second ) receber.push(at);
                    }
                    else{
                        ans += int64((i+1) - abs(at.first))*at.second;
                        val -= at.second;
                    }
                }
                if( val != 0 ) vender.push(make_pair(-(i+1),val));
            }
        }
        cout << ans << '\n';       
    }
    return 0;
}

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
    set < int > vet;
    vector < int > ans;
    for( int i = 2; i <= 35110; i++ ) vet.insert(i);   
    for( int i = 0; i <= 3000; i++ ){
        set < int > :: iterator it = vet.begin();
        ans.push_back(*it);
        vet.erase(*it);
        it = vet.begin();
        int k = 1;
        while( it != vet.end() ){
            if( k == ans.back() ){
                k = 1;
                int at = *it;
                it++;
                vet.erase(at);
            }
            else{
                it++;
                k++;
            }
        }
    }    
    while( cin >> n && n ){
        cout << ans[n-1] << '\n';
    }
    return 0;
}

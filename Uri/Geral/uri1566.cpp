#include <bits/stdc++.h>

using namespace std;

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

int mapa[300];

int main(){
    ios::sync_with_stdio(false);
    int t, n, val;
    read(t);
    while( t-- ){
        read(n);
        memset(mapa,0,sizeof(mapa));
        int m = 0;
        for( int i = 0; i < n; i++ ){
            read(val);
            mapa[val]++;
            m = max(m, val);
        }
        vector < pair < int , int > > opa;
        for( int i = 0; i <= m; i++ ) if( mapa[i] ) opa.push_back(make_pair(i,mapa[i]));
        int tam = opa.size();
        for( int i = 0; i < tam; i++ ){
            for( int j = 0; j < opa[i].second; j++ ){
                if( i || j ) cout << " ";
                cout << opa[i].first;
            }
        }
        cout << '\n';
    }
    return 0;
}
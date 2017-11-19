#include <bits/stdc++.h>
 
using namespace std;
 
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

struct maxQueue{
    queue < uint64 > fila;
    deque < uint64 > dFila;

    void push( uint64 val ){
        while( !dFila.empty() && dFila.back() < val ) dFila.pop_back();
        dFila.push_back(val);
        fila.push(val); 
    }

    void pop( ){
        if( fila.front() == dFila.front() ) dFila.pop_front();
        fila.pop();
    }

    uint64 getMax( ){
        return dFila.front();
    }
};

uint64 s;
int n, k;
 
uint64 solve(){
    uint64 ans = 0, val, ant;
    maxQueue range;
    ant = s;
    range.push(ant);
    for( int i = 1; i < k; i++ ){
        val = (1LL*ant*1103515245 + 12345);
        if( val >= 2147483648LL ) val %= 2147483648LL;
        range.push(val);
        ant = val;
    }
    ans += range.getMax();
    for( int i = k; i < n; i++ ){
        val = (1LL*ant*1103515245 + 12345);
        if( val >= 2147483648LL ) val %= 2147483648LL;
        range.pop();
        range.push(val);
        ans += range.getMax();
        ant = val;
    }
    return ans;
}
 
int main(){
    ios::sync_with_stdio(false);
    int t, val;
    read(t);
    while( t-- ){
        read(n);
        read(k);
        read(val);
        s = val;
        cout << solve() << "\n";
    }
    return 0;
}
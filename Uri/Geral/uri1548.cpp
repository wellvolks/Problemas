#include <bits/stdc++.h>
  
using namespace std;
  
typedef long long int64;
typedef unsigned long long uint64;

#ifdef _WIN32
    #define getchar_unlocked getchar
    #define putchar_unlocked putchar
#endif
   
   
bool read( int &n ) {
    n = 0LL;
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

inline void writeInt(int n){
    register int idx = 20;
    if( n < 0 ) putchar_unlocked('-');
    n = abs(n);
    char out[21];
    out[20] = ' ';
    do{
        idx--;
        out[idx] = n % 10 + '0';
        n/= 10;
    }while(n);
    do{ putchar_unlocked(out[idx++]); } while (out[idx] != ' ');
}

vector < pair < int, int > > vet;

int main(){
    ios::sync_with_stdio(false);
    int t, n, val;
    read(t);
    while( t-- ){
        read(n);
        for( int i = 0; i < n; i++ ){
            read(val);
            vet.push_back(make_pair(-val,i));
        }
        sort(vet.begin(), vet.end());
        int ans = 0;
        for( int i = 0; i < n; i++ ){
            if( vet[i].second == i ) ans++;
        }
        writeInt(ans);
        putchar_unlocked('\n');
        vet.clear();
    }
    return 0;
}
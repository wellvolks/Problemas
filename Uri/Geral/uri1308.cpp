#include <bits/stdc++.h>
  
using namespace std;
  
typedef long long int64;
typedef unsigned long long uint64;

#ifdef _WIN32
    #define getchar_unlocked getchar
    #define putchar_unlocked putchar
#endif
   
   
bool read( unsigned long long &n ) {
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
 
inline void writeInt(unsigned long long n){
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

int main(){
    ios::sync_with_stdio(false);
    unsigned long long lo, hi, mid, n, ans, at, k;
    read(k);
    while( k-- ){
        read(n);
        lo = 0; hi = min(n,10000000000ULL);
        ans = 0LL;
        while( lo <= hi ){
            mid = ( lo + hi ) >> 1LL;
            at = (mid+1)*(mid)>>1LL;
            if( at > n ) hi = mid-1LL;
            else{
                ans = max(ans,mid);
                lo = mid+1LL;
            }
        }
        writeInt(ans);
        putchar_unlocked('\n');
    }
    return 0;
}
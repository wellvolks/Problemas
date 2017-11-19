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

struct tri{
    double x, y;
    tri( double x = 0., double y = 0. ) : x(x), y(y) { }
};

double dist( tri a, tri b ){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

int main(){
    ios::sync_with_stdio(false);
    int t, n, x, y;
    read(t);
    while( t-- ){
        read(n);
        tri at;
        read(x); read(y);
        at = tri(x,y);
        int dst = 1e9, ans = 0;
        for( int i = 1; i <= n; i++ ){
            read(x); read(y);
            double d = dist(tri(x,y),at);
            if( d < dst ){
                dst = d;
                ans = i;
            }
        }
        writeInt(ans);
        putchar_unlocked('\n');
    }
    return 0;
}
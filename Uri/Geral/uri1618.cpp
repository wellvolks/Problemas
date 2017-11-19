#include <bits/stdc++.h>

using namespace std;

#ifdef _WIN32  
    #define getchar_unlocked getchar 
    #define putchar_unlocked putchar 
#endif 
   
inline bool read( int  &n ) { 
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
   
inline void writeInt(long long n){ 
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
    int t, ax, ay, bx, by, cx, cy, dx, dy, x, y;
    read(t);
    while( t-- ){
        read(ax); read(ay);
        read(bx); read(by);
        read(cx); read(cy);
        read(dx); read(dy);
        read(x); read(y);
        if( x >= ax && y >= ay && x <= bx && y >= by && x <= cx && y <= cy && x >= dx && y <= dy ) putchar_unlocked('1');
        else putchar_unlocked('0');
        putchar_unlocked('\n');
    }
    return 0;
}
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

vector < int > vet;

int main(){
    ios::sync_with_stdio(false);
    for( int i = 1; i <= 5000; i++ ) vet.push_back(i*i);
    int tam = vet.size(), n;
    while( read(n) && n ){
        for( int i = 0; i < tam && vet[i] <= n; i++ ){
            if( i ) putchar_unlocked(' ');
            writeInt(vet[i]);
        }
        putchar_unlocked('\n');
    }
    return 0;
}
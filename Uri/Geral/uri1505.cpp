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

int grafo[10000], used[10000], vis = 1;
int custo[10000], ganho[10000];

int main(){
    ios::sync_with_stdio(false);
    int n, val;
    read(n);

    for( int i = 0; i < n; i++ ){
        read(val);
        grafo[i] = val;
    }

    for( int i = 0; i < n; i++ ) read(ganho[i]);
    for( int i = 0; i < n; i++ ) read(custo[i]);

    int ans = 0;
    for( int i = 0; i < n; i++ ){
        int at = i, acm = 0, dias = 0;
        while( used[at] != vis && acm < custo[i] ){
            used[at] = vis;
            acm += ganho[at];
            dias++;
            at = grafo[at];
        }
        if( custo[i] > acm ){
            dias = (custo[i]/acm)*dias;
            at = i; vis++;
            custo[i] %= acm;
            acm = 0;
            while( used[at] != vis && acm < custo[i] ){
                used[at] = vis;
                acm += ganho[at];
                dias++;
                at = grafo[at];
            }
        }
        ans = max(ans, dias);
        vis++;
    }
    writeInt(ans);
    putchar_unlocked('\n');
    return 0;
}
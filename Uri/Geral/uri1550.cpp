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

int used[1000000], vis = 1;
char str[1000];

int solve( int a, int b ){
    queue < pair < int, int > > fila;
    fila.push(make_pair(a,0));
    used[a] = vis;
    while( !fila.empty() ){
        pair < int, int > at = fila.front();
        fila.pop();
        if( at.first == b ) return at.second;
        if( used[at.first+1] != vis ){
            used[at.first+1] = vis;
            fila.push(make_pair(at.first+1,at.second+1));
        }
        sprintf(str,"%d",at.first);
        reverse(str,str+strlen(str));
        sscanf(str,"%d",&at.first);
        if( used[at.first] != vis ){
            fila.push(make_pair(at.first,at.second+1));
            used[at.first] = vis;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    int t, a, b;
    read(t);
    while( t-- ){
        read(a);
        read(b);
        writeInt(solve(a,b));
        putchar_unlocked('\n');
        vis++;
    }
    return 0;
}
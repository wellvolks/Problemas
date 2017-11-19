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
    int t, k = 1, n;
    string resp[] = {"Uilton", "Rita","Ingred", "URI"};
    while( read(t) && t){
        int ui, ri, li, tu = 0, tr = 0, tl = 0;
        for( int i = 0; i < t; i++ ){
            read(ui);
            read(ri);
            read(li);
            if( __builtin_popcount(ui) == 1 ){
                tu++;
                if( ui > ri && ui > li ) tu++;
            }
            if( __builtin_popcount(ri) == 1 ){
                tr++;
                if( ri > ui && ri > li ) tr++;
            }
            if( __builtin_popcount(li) == 1 ){
                tl++;
                if(li > ui && li > ri) tl++;
            }
        }
        if( (tu == tr && tu > tl) || (tu == tl && tu > tr) || (tr == tl &&  tr > tu) || ( tu == tr && tu == tl ) ) cout << resp[3] << "\n";
        else if( tu > tr && tu > tl ) cout << resp[0] << '\n';
        else if( tr > tu && tr > tl ) cout << resp[1] << '\n';
        else cout << resp[2] << '\n';
    }
    return 0;
}

00000111100000001111111100
11111000011111110000000011
1000
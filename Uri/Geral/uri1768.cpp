#include <bits/stdc++.h>
//#include <tr1/unordered_map>
 
using namespace std;
//using namespace tr1;
 
typedef long long int64;
typedef unsigned long long uint64;
 
#ifdef _WIN32
    #define getchar_unlocked getchar
#endif
 
inline void read(  int &n ) {
    n = 0;
    register bool neg = false;
    register char c = getchar_unlocked();
    if( c == EOF) { n = -1; return; }
    while (!('0' <= c && c <= '9')) {
        if( c == '-' ) neg = true;
        c = getchar_unlocked();
    }
    while ('0' <= c && c <= '9') {
        n = n * 10 + c - '0';
        c = getchar_unlocked();
    }
    n = (neg ? (-n) : (n));
}
 
map < int, int > mapa;
 
vector < int > vet;
 
int main(){
    ios::sync_with_stdio(false);
    int n;
    while( cin >> n ){
        string str = "", cp = "";
        for( int i = 0; i < (n-1)/2; i++ ) str += " ";
        cp += str;
        for( int i = 0; i < n; i+=2 ){
            cout << str;
            for( int j = 0; j <= i; j++ ) cout << "*";
            cout << "\n";
            if( str.size() ) str.erase(str.begin()+str.size()-1);
        }
        cout << cp << "*\n";
        if( cp.size() ) cp.erase(cp.begin()+cp.size()-1);
        cout << cp << "***\n\n";
    }
    return 0;
}
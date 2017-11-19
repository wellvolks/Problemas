#include <map>
#include <set>
#include <list>
#include <stack>
#include <cmath>
#include <queue>
#include <ctime>
#include <cfloat>
#include <vector>
#include <string>
#include <cstdio>
#include <bitset>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <iomanip>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>
 
#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFFLL
 
#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) __typeof((X).begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) int((V).size())
 
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define RFOR(i, b, a) for(int i = b; i >= a; --i)
#define REP(i, N) for(int i = 0; i < N; ++i)
#define RREP(i, N) for(int i = N-1; i >= 0; --i)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )
 
#define PB push_back
#define MP make_pair
 
typedef long long int64;
typedef unsigned long long uint64;
 
using namespace std;
 
struct tri{
    int id, qt;
    tri(int id = 0, int qt = 0) : id(id), qt(qt) { } 
};
inline void read( int &n ) {
    n = 0;
    bool neg = false;
    char c = getchar_unlocked();
    if( c == EOF){ n = -400; return; }
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
 
inline void readChar( char &n ) {
    char c = getchar_unlocked();
    if( c == EOF) exit(1);
    while (!('a' <= c && c <= 'z')) {
        c = getchar_unlocked();
    }
    n = c;
}
 
int main(){
    int n, qt, num;
    while(true){
        read(n);
        if(!n) break;
        char a[30];
        char b[10000];
        char c[30];
        int posA = n-1, posB = 1;
        REP(i,n) readChar( a[posA--] ); //cin >> a[posA--];
        a[posA] = '\0';
        posA = n;
        REP(i,n) readChar( c[i] ); //cin >> c[i];
        bool flag = true;
        REP(i,n){
            if(!flag)break;
            if(posB != 0 && c[i] == b[posB-1]){ posB--; printf("R"); }
            else{
                while(true){
                    if(posA != 0){
                          if(c[i] == a[posA-1]){
                            putchar('I');
							putchar('R');
                            posA--;
                            flag = true;
                            break;
                        }
                        else{
                            b[posB++] = a[posA-1];
                            putchar('I');
                            posA--;
                            flag = false;
                        }
                    }
                    else{
                        flag = false;
                        break;
                    }
                }
            }
        }
        if(!flag) puts(" Impossible");
        else puts("");
    }
    return 0;
}
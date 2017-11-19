#include <map>
#include <set>
#include <deque>
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
  
using namespace std;
  
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define RFOR(i, b, a) for(int i = b; i >= a; --i)
#define REP(i, N) for(int i = 0; i < N; ++i)
#define RREP(i, N) for(int i = N-1; i >= 1; --i)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )
#define MAXN 20101
#define LINF 0x3F3F3F3FFFFFFFFFLL
#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) __typeof((X).begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) int((V).size())
#define pb push_back
#define mk make_pair

typedef long long int64;
typedef unsigned long long uint64;

struct tri{
	char pilha[9][9];
	int ans;
	tri( int ans = 0, char pp[9][9] = new char[9][9] ) :  ans(ans) { 
		REP(i,9) REP(j,9) pilha[i][j] = pp[i][j];
	}
};
  
  
#ifdef _WIN32 
    #define getchar_unlocked getchar
	#define putchar_unlocked putchar
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

vector < unsigned int > memoria;

unsigned int getBin( string &str ){
    unsigned int ans = 0, k = 0;
    RFOR(i,7,0){
        if(str[i] == '1') ans |= (1 << k);
        k++;
    }
    return ans;
}

int main(){
	ios::sync_with_stdio(false);
    string str;
    while( cin >> str ){
        memoria.pb(getBin(str));
        FOR(i,1,31){
            cin >> str;
            memoria.pb(getBin(str));
        }
        unsigned pc = 0, acm = 0;
        bool ok = true;
        while( ok ){
            unsigned int op = memoria[pc] >> 5;
            unsigned int pos = (memoria[pc] << 27) >> 27;
            pc = (pc+1) % 32;
            //cout << op << " " << pos << " " << memoria[pc] << "\n";
           // continue;
            switch(op){
                case 0: acm <<= 24; acm >>= 24; memoria[pos] = acm; break;
                case 1: acm = memoria[pos]; break;
                case 2: acm <<= 24; acm >>= 24; if( acm == 0 ) pc = pos; break;
                case 3:  break;
                case 4:  acm--;  break;
                case 5:  acm++; acm <<= 24; acm >>= 24; break;
                case 6: pc = pos;break;
                case 7: ok = false; break;
            }
            //cout << acm << "\n";
        }
        acm <<= 24; acm >>= 24;
        RFOR(i,7,0) cout << ((acm &(1 << i) ) ? ("1") : ("0"));
        cout << "\n";
        memoria.clear();
    }    
    return 0;
}


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
#define MAXN 10000
#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFFLL
#define FILL(X, V, T, P) memset( X, V, T * sizeof(P) )
#define TI(X) __typeof((X).begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) int((V).size())
 
const double pi = acos(-1.0);
const double EPS = 1e-9;
 
int cmp(double a, double b){
    if(fabs(a-b) < EPS) return 0;
    return a > b ? 1 : -1;
}
 #ifdef _WIN32 
    #define getchar_unlocked getchar
#endif

inline void readInt( int &n ) {
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

inline void readDouble( double &n ) {
    n = 0.;
    register bool neg = false;
    register char c = getchar_unlocked();
    if( c == EOF) { n = -1.; return; }
    while (!('0' <= c && c <= '9')) {
        if( c == '-' ) neg = true;
        c = getchar_unlocked();
    }
	register double k = 1.;
	register bool ok = true;
    while (('0' <= c && c <= '9')) {
        n = n * 10 + c - '0';
        c = getchar_unlocked();
		if( !ok ) k *= 10.;
		if( c == '.' ){  c = getchar_unlocked(); ok = false; }
		
    }
	n /= k;
    n = (neg ? (-n) : (n));
}

vector < string > nameRand;

void generateNamesSpecies(){
	char alphabet[ ] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
	string nameEspecie = "";
	char numberAux[100];
	for(int i = 0; i < 10000; i++){
		sprintf(numberAux, "%d", i);
		for( int j = 0; j < 26; j++ ){
			nameEspecie += alphabet[j];
			nameRand.push_back(nameEspecie + numberAux);
			nameEspecie = "";
		}
	}
}

int main(){
    generateNamesSpecies();
	map < string, int > mapa;
	REP(i,nameRand.size()){
		mapa[nameRand[i]]++;
		if( mapa[nameRand[i]] > 1 ){ cout << "erro!"; break; }
	}
    return 0;
}
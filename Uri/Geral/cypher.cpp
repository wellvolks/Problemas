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
#include <complex>

using namespace std;

#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define RFOR(i, b, a) for(int i = b; i >= a; --i)
#define REP(i, N) for(int i = 0; i < N; ++i)
#define RREP(i, N) for(int i = N-1; i >= 1; --i)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )
#define MAXN 10000
#define LINF 0x3F3F3F3FFFFFFFFFLL
#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) __typeof((X).begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) int((V).size())
#define pb push_back
#define mk make_pair

struct tri{
	int used;
	double valor;
	tri ( int used = 0, double valor = 0.) : used(used), valor(valor) { }
};

struct par{
	int de, para;
	par(int de = 0, int para = 0) : de(de), para(para) { }
};

int n, m;
typedef vector < int > vi;
typedef vector < vi > vii;
typedef vector < tri > vtri;
typedef vector < vtri > vvtri;
typedef long long int64;
typedef unsigned long long uint64;

int main(){
	ios::sync_with_stdio(false);
	string alpha, tradu, text;
	int tamAlpha;
	while( getline(cin, alpha) ){
		getline(cin,tradu);
		tamAlpha = tradu.size();
		while( getline(cin, text) ){
			int tam = text.size();
			if( text == "-1" ) cout << "\n";
			REP(i,tam){
				REP( j,tamAlpha ){
					if( alpha[j] == text[i] ){
						text[i] = tradu[j];
						break;
					}
				}
			}
			cout << text << "\n";
		}
	}
	return 0;
}
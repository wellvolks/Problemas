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

using namespace std;

#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define RFOR(i, b, a) for(int i = b; i >= a; --i)
#define REP(i, N) for(int i = 0; i < N; ++i)
#define RREP(i, N) for(int i = N-1; i >= 0; --i)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )
#define MAXN 10000
#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFFLL
#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) __typeof((X).begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) int((V).size())
#define pb push_back
#define mp make_pair
#define pair < int, int > pii;

struct tri{
	int atual, custo;
	tri ( int atual = 0, int custo = 0) : atual(atual), custo(custo) { }
};

int n, m;
typedef vector < int > vi;
typedef vector < vi > vii;
typedef vector < tri > vtri;
typedef vector < vtri > vvtri;
typedef long long int64;
typedef unsigned long long uint64;

int x[] = {-1,-1,-1, 0, 1, 1, 1, 0 };
int y[] = {-1, 0, 1, 1, 1, 0,-1,-1 };
char str[100], cort[100];

int read(){
	int k = 0;
	char c = getchar_unlocked();
	if ( c == EOF ) return -1;
	while ( c >= '0' && c <= '9' || c == '.' ){
		str[k++] = c;
		c = getchar_unlocked();
	}
	str[k] = '\0';
	c = getchar_unlocked();
	k = 0;
	while ( c >= '0' && c <= '9' || c == '.'){
		cort[k++] = c;
		c = getchar_unlocked();
	}
	cort[k] = '\0';
	return 0;
}

int main(){
	while( read() != -1 ){
		register int p = 0, parteInt = 0, parteFra = 0, k = 0;
		register bool corte = false;
		register int tam = strlen(str);
		for( register int i = tam; i <= 10; i++ ) str[i] = '0';
		for( register int i = 6; i <= 10; i++) cort[i] = '0';
		str[11] = '\0';
		while ( p < tam && str[p] != '\0' && str[p] != '.' ) parteInt = (parteInt * 10) + (str[p++] - '0');
		if( str[p] != '\0'){ 
			p++;
			k = 2;
			while ( str[p] != '\0' ){ 
				if( (str[p]-'0') > (cort[k]-'0')){
					corte = true;
					break;
				}
				else if(  (str[p]-'0') < (cort[k]-'0') ) break;
				k++;
				p++;
			}
		}

		if( corte ) parteInt++;
		fprintf(stdout,"%d\n",parteInt);
	}
	return 0;
}

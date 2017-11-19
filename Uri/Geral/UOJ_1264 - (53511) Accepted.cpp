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
#include <stdint.h>
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
#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) __typeof((X).begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) int((V).size())

#define pb push_back
#define mk make_pair

struct tri{
int atual, custo;
tri ( int atual = 0, int custo = 0) : atual(atual), custo(custo) { }
};

int k;
typedef vector < int > vi;
typedef vector < vi > vii;
typedef vector < tri > vtri;
typedef vector < vtri > vvtri;
typedef long long int64;
typedef unsigned long long uint64;

int x[] = {-1,-1,-1, 0, 1, 1, 1, 0 };
int y[] = {-1, 0, 1, 1, 1, 0,-1,-1 };

char str[10000];
int base[400];

int main(){
	base['0'] = 0;  base['1'] = 1;  base['2'] = 2;  base['3'] = 3;  base['4'] = 4;  base['5'] = 5;  base['6'] = 6;  base['7'] = 7;
	base['8'] = 8;  base['9'] = 9;  base['A'] = 10; base['B'] = 11; base['C'] = 12; base['D'] = 13; base['E'] = 14; base['F'] = 15;
	base['G'] = 16; base['H'] = 17; base['I'] = 18; base['J'] = 19; base['K'] = 20; base['L'] = 21; base['M'] = 22; base['N'] = 23;
	base['O'] = 24; base['P'] = 25; base['Q'] = 26; base['R'] = 27; base['S'] = 28; base['T'] = 29; base['U'] = 30; base['V'] = 31;
	base['W'] = 32; base['X'] = 33; base['Y'] = 34; base['Z'] = 35; base['a'] = 36; base['b'] = 37; base['c'] = 38; base['d'] = 39;
	base['e'] = 40; base['f'] = 41; base['g'] = 42; base['h'] = 43; base['i'] = 44; base['j'] = 45; base['k'] = 46; base['l'] = 47;
	base['m'] = 48; base['n'] = 49; base['o'] = 50; base['p'] = 51; base['q'] = 52; base['r'] = 53; base['s'] = 54; base['t'] = 55;
	base['u'] = 56; base['v'] = 57; base['w'] = 58; base['x'] = 59; base['y'] = 60; base['z'] = 61; 
	
	while(gets(str) != NULL){
		char *p = strtok(str, " +-");
		int i = 0, ans = 0, pos = -1, start = 0;
		while(p[i] != '\0'){ ans += base[p[i]]; start = max(start, base[p[i]]); i++; }
		if(!ans){printf("2\n",pos); continue; }
		for(i = start; i <= 61 ; i++) if( !(ans % i) ){ pos = i + 1; break; }
		if(pos != -1 ) printf("%d\n",pos);
		else printf("such number is impossible!\n");
	}
	return 0;
}

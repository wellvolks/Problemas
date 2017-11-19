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

char str[1000];
char ans[400];

int main(){
	ans['!'] = '!'; ans['@'] = '@'; ans['#'] = '#'; ans['$'] = '$'; ans['%'] = '%'; ans['^'] = '^'; ans['&'] = '&'; ans['*'] = '*'; ans['('] = '('; ans[')'] = ')';
	ans['-'] = '-'; ans['_'] = '_'; ans['='] = '='; ans['+'] = '+'; ans['['] = '['; ans[']'] = ']'; ans['{'] = '{'; ans['}'] = '}'; ans['|'] = '|'; 
	ans[';'] = ';'; ans['\''] = '\''; ans[':'] = ':'; ans[','] = ','; ans['.'] = '.'; ans['/'] = '/'; ans['<'] = '<'; ans['>'] = '>'; ans['?'] = '?'; ans['\"'] = '\"';
	ans['a'] = 'n'; ans['b'] = 'o'; ans['c'] = 'p'; ans['d'] = 'q'; ans['e'] = 'r'; ans['f'] = 's'; ans['g'] = 't'; ans['h'] = 'u'; ans['i'] = 'v'; ans['j'] = 'w'; ans['k'] = 'x';
	ans['l'] = 'y'; ans['m'] = 'z'; ans['n'] = 'a'; ans['o'] = 'b'; ans['p'] = 'c'; ans['q'] = 'd'; ans['r'] = 'e'; ans['s'] = 'f'; ans['t'] = 'g'; ans['u'] = 'h'; ans['v'] = 'i';
	ans['w'] = 'j'; ans['x'] = 'k'; ans['y'] = 'l'; ans['z'] = 'm';
	ans['A'] = 'N'; ans['B'] = 'O'; ans['C'] = 'P'; ans['D'] = 'Q'; ans['E'] = 'R'; ans['F'] = 'S'; ans['G'] = 'T'; ans['H'] = 'U'; ans['I'] = 'V'; ans['J'] = 'W'; ans['K'] = 'X';
	ans['L'] = 'Y'; ans['M'] = 'Z'; ans['N'] = 'A'; ans['O'] = 'B'; ans['P'] = 'C'; ans['Q'] = 'D'; ans['R'] = 'E'; ans['S'] = 'F'; ans['T'] = 'G'; ans['U'] = 'H'; ans['V'] = 'I';
	ans['W'] = 'J'; ans['X'] = 'K'; ans['Y'] = 'L'; ans['Z'] = 'M';
	ans[' '] = ' '; ans['\n'] = '\n'; ans['1'] = '1'; ans['2'] = '2'; ans['3'] = '3'; ans['4'] = '4'; ans['5'] = '5'; ans['6'] = '6'; ans['7'] = '7'; ans['8'] = '8'; ans['9'] = '9'; ans['0'] = '0';
	ans['~'] = '~'; ans['\\'] = '\\'; ans['`'] = '`';
	while(gets(str) != NULL){
		int tam = strlen(str);
		REP(i,tam) putchar(ans[str[i]]);
		printf("\n");
	}
 	return 0;
}

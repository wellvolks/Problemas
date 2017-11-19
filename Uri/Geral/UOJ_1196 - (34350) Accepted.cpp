#include <set>
#include <map>
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

struct tri{
	int atual, custo;
	tri ( int atual = 0, int custo = 0) : atual(atual), custo(custo) { }
};


typedef vector < int > vi;
typedef vector < vi > vii;
typedef vector < tri > vtri;
typedef vector < vtri > vvtri;
typedef long long int64;
typedef unsigned long long uint64;

char str[10000], ans[10000];
char teclado[10000];

int main(){
	teclado['1'] = '`'; teclado['2'] = '1'; teclado['3'] = '2'; teclado['4'] = '3'; teclado['5'] = '4'; teclado['6'] = '5';teclado['7'] = '6';
	teclado['8'] = '7'; teclado['9'] = '8'; teclado['0'] = '9'; teclado['-'] = '0'; teclado['='] = '-'; teclado['W'] = 'Q';teclado['E'] = 'W'; 
	teclado['R'] = 'E'; teclado['T'] = 'R'; teclado['Y'] = 'T'; teclado['U'] = 'Y'; teclado['I'] = 'U'; teclado['O'] = 'I'; teclado['P'] = 'O'; 
	teclado['['] = 'P'; teclado[']'] = '['; teclado['\\'] = ']'; teclado['S'] = 'A'; teclado['D'] = 'S'; teclado['F'] = 'D'; teclado['G'] = 'F'; 
	teclado['H'] = 'G'; teclado['J'] = 'H'; teclado['K'] = 'J'; teclado['L'] = 'K'; teclado[';'] = 'L'; teclado['\''] = ';'; teclado['X'] = 'Z'; 
	teclado['C'] = 'X'; teclado['V'] = 'C'; teclado['B'] = 'V'; teclado['N'] = 'B'; teclado['M'] = 'N'; teclado[','] = 'M'; teclado['.'] = ','; 
	teclado['/'] = '.'; teclado[' '] = ' '; teclado['\n'] = '\n'; teclado['Q'] = '='; teclado['A'] = '\\'; teclado['Z'] = '\'';
//	string str = "";
//	while(getline(cin,str)){
	while(gets(str) != NULL){
		//cout << str << "\n";
		if(!strcmp(str,"")){ printf("\n"); continue; }
		int tam = strlen(str);
		REP(i,tam) ans[i] = teclado[str[i]];
		ans[tam] = '\0';
		printf("%s\n",ans);
	}
	return 0;
}

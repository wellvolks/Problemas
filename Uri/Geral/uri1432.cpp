#include <tr1/unordered_set>
#include <tr1/unordered_map>
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
using namespace tr1;

#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define RFOR(i, b, a) for(int i = b; i >= a; --i)
#define REP(i, N) for(int i = 0; i < N; ++i)
#define RREP(i, N) for(int i = N-1; i >= 0; --i)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )
#define MAXN 10000
#define INF 0x3f3f3f3f
#define LINF 0x3F3F3F3FFFFFFFFFLL
#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) __typeof((X).begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) int((V).size())
#define pb push_back
#define mp make_pair

struct tri{
	int atual, custo, b;
	int filhos[3];
	tri ( int atual = 0, int custo = 0, int b = 0, int *f = NULL) : atual(atual), custo(custo), b(b) {
		filhos[0] = f[0]; filhos[1] = f[1]; filhos[2] = f[2];
	}
	bool operator < (const tri &a) const{
		return a.custo > custo;
	}
};

struct cord{
	int x, y, direcao;
	cord (int x = 0, int y = 0, int direcao = 0) : x(x), y(y), direcao(direcao) { }
};

int x[] = {-1,-1,-1, 0, 1, 1, 1, 0 };
int y[] = {-1, 0, 1, 1, 1, 0,-1,-1 };

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
unsigned long long ans = 0;
char str[1000];
vector < int > tams;
int visit[100], vis = 1;
int n;
unordered_set < string > tem;

int check(int w){
	string aux = "", eita = "";
	for( int i = 0; i < w; i++ ){
		for( int j = 1; i + j < w; j++ ){
			aux = "";
			eita = "";
			for( int k = 0; k < j; k++ ) aux += str[i+k];
			eita += aux;
			eita += aux;
			eita += aux;
			if( !strncmp(eita.c_str(), str+i, j*3) ) return 0;
		}
	}
	return 1;
}

void solve(int k){
	if( k >= n ){ 
		str[k] = '\0';
		//puts(str);
		ans += check(k);
		return ;
	}
	solve(k + 1);
	if( visit[k] != vis ) return;
	str[k] = '1';
	solve(k + 1);
	str[k] = '0';
}

int main(){
	ios::sync_with_stdio(false);
	int c = 1;
	while( cin >> n && n ){
		cin >> str;
		ans = 0;
		for( int i = 0; str[i] != '\0'; i++ ) if( str[i] == '*' ){ str[i] = '0'; visit[i] = vis; }
		solve(0);
		cout << "Case " << c++ <<": " << ans << "\n";
		vis++;
	}
	return 0;
}
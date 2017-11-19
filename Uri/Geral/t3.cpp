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
#define MAXN 1006003
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
  
struct pt{
    int x, y;
    pt ( int x = 0, int y = 0 ) : x(x), y(y) { }
};
 
typedef vector < int > vi;
typedef vector < vi > vii;
typedef vector < tri > vtri;
typedef vector < vtri > vvtri;
typedef long long int64;

char mat[100][100];
vector < pt > vet;
int main(){
	int n, m;
	ios::sync_with_stdio(false);
	int t, b, d;
	cin >> t;
	while( t-- ){
		cin >> b >> d;
		vet.resize(d);
		REP(i,d) cin >> vet[i].x >> vet[i].y;
		pt cord;
		vector < int > cc;
		cc.resize(d);
		REP(i,d) cin >> cc[i];
		int total = 1;
		REP(i,d) total *= ((vet[i].y - vet[i].x)+1); 
		int l = 0;
		REP(i,d){
			int kk = 1;
			for( int j = 0; j < i; j++ ) kk *= (vet[j].y-vet[j].x + 1);
			l += (cc[i] - vet[i].x) * kk;
		}
		l += b;
		cout << total << " " << l << "\n";
		vet.clear();
	}
	return 0;
}

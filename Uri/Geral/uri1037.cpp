#include <set>
//#include <tr1/unordered_map>
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
//using namespace tr1;
 
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define RFOR(i, b, a) for(int i = b; i >= a; --i)
#define REP(i, N) for(int i = 0; i < N; ++i)
#define RREP(i, N) for(int i = N-1; i >= 0; --i)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )
#define MAXN 10000
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
 
int n, m;
typedef vector < int > vi;
typedef vector < vi > vii;
typedef vector < tri > vtri;
typedef vector < vtri > vvtri;
typedef long long int64;
typedef unsigned long long uint64;
const double EPS = 1e-50;
const double INF = 1e50;
 
int cmp(double a, double b = 0.0){ if(fabs(a-b) < EPS) return 0; return a > b ? 1 : -1; }
 
int main(){
  double valor;
  scanf("%lf",&valor);
  if( cmp(valor, 100.) == 1 || cmp(valor, 0.) == -1 ) printf("Fora de intervalo\n");
  else if( cmp(valor,75.) == 1 ) printf("Intervalo (75,100]\n");
  else if( cmp(valor,50.) == 1 ) printf("Intervalo (50,75]\n");
  else if( cmp(valor,25.) == 1 ) printf("Intervalo (25,50]\n");
  else if( cmp(valor,0.) == 0  ) printf("Intervalo [0,25]\n");
  else if( cmp(valor,0.) == 1  ) printf("Intervalo [0,25]\n");
  return 0;
}
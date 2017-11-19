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
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )
#define MAXN 1200001
#define LINF 0x3F3F3F3FFFFFFFFFLL
#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) __typeof((X).begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) int((V).size())

#define pb push_back
#define mk make_pair
const double pi = acos(-1.0);
const double EPS = 1e-9;

typedef long long int64;
typedef unsigned long long uint64;

struct tri{
    int a, b, c, q, l;
    tri( int a = 0, int b = 0, int c = 0, int q = 0, int l = 0 ) :
    a(a), b(b), c(c), q(q), l(l) { }
};

string str;
map < string, int > mapa;

int main(){
    ios::sync_with_stdio(false);
    int t;
    cout << fixed << setprecision(6);
    while( cin >> t && t ){
        str = "";
        string aux = "";
        cin.ignore();
        REP(i,t){
            getline(cin,aux);
            str += aux;
        }
        int tam = str.size();
        REP(i,tam-1){
            aux = "";
            FOR(j,i,i+1) aux += str[j];
            mapa[aux]++;
        }
        map < string, int > :: iterator it;
        double tt = 0.;
        FORIT(i,mapa) tt += i->second;
        REP(i,5){
            int qt = 0;
            aux = "";
            it = mapa.end();
            FORIT(j,mapa){
                if( j->second > qt ){
                    qt = j->second;
                    it = j;
                }
            }
            if(it != mapa.end()){
                cout << it->first;
                cout << " " << it->second <<  " " << (double(it->second)/tt) << "\n";
                it->second = -1;
            }
        }
        cout << "\n";
        mapa.clear();
    }
    return 0;
}
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
#define calc (((h * 3600.0 + m * 60.0 + s) - (ath * 3600.0 + atm * 60.0 + ats)) *  atkm / 3600.0)

int main() {
    char str[100];
    double h = 0., m = 0., s = 0., ans = 0., km = 0.;
    double ath = 0., atm = 0., ats = 0., atkm = 0.;
	int k = 0;
	bool query;
    cout << fixed << setprecision(2);
    while( gets(str) ){
		k = 8;
		query = true;
        h = ((str[0]-'0')*10+(str[1]-'0'));
        m = ((str[3]-'0')*10+(str[4]-'0'));
        s = ((str[6]-'0')*10+(str[7]-'0'));
        while( str[k] != '\0' && str[k] == ' ') k++;
        if( str[k] != '\0' ){ 
			query = false;
            double casas = 1.;
			km = 0.;
            while( str[k] != '\0' && str[k]  >= '0' && str[k] <= '9' ) km = km * 10. + double(str[k++]-'0'); 
            if( str[k] != '\0' ){ 
                k++;
                while( str[k] == ' ' ) k++;
                while( str[k] != '\0' && str[k] != '.' ){ km = km * 10. + double(str[k++]-'0'); casas *= 10.; }
                km /= casas;
            }
        } 
		ans += calc;
        ath = h; atm = m; ats = s; atkm = km;
		if( !query ) continue;
        else{
            str[8] = '\0';
            printf("%s ",str);
            cout << calc + ans << " km\n";
        }
    }
    return 0;
}


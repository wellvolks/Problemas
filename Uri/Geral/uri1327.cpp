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
#define mk make_pair

struct tri{
	int atual, custo;
	tri ( int atual = 0, int custo = 0) : atual(atual), custo(custo) { }
};

struct cord{
    int x, y, z;
    cord (int x = 0, int y = 0, int z = 0 ) : x(x), y(y), z(z) { }
    bool operator < (const cord a) const{
        if( a.x != x ) return (a.x < x);
        else if(a.y != y) return (a.y < y);
        else if(a.z != z) return (a.z < z);
        return false;
    }
};

map < cord, int > ans;

void rotaciona(cord a, cord b){
    if( a.x <= b.x && a.y <= b.y && a.z <= b.z ) ans[b] ++;
}

typedef vector < int > vi;
typedef vector < vi > vii;
typedef vector < tri > vtri;
typedef vector < vtri > vvtri;
typedef long long int64;
typedef unsigned long long uint64;
vector < string > names;
deque < int >  cartas;


int main(){
	ios::sync_with_stdio(false);
	int n, c;
	string nome;
	vector < pair < int, int > > round;
	vector < int > opa;
	while( cin >> n && n ){
		REP(i,n){ cin >> nome; names.pb(nome); }
		REP(i,52){
			cin >> c;
			cartas.push_back(c);
		}
		int64 mask = (int64(1) << n)-1, backup;
		int qtd = __builtin_popcount(mask);
		bool stop = true;
		int k = 0;
		while( qtd > 1 && stop){
			REP(i,n){
				if( mask & (int64)1 << k ){
					if( cartas.empty() ){ stop = true; backup = mask; break; }
					round.pb(mk(cartas.front(),k));
					cartas.pop_front();
				}
				k = (k + 1)%n;
			}
			if( !stop ) break;
			sort(ALL(round));
			int menor = round[0].first;
			backup = mask;
			if( cartas.empty() ) break;
			REP(i,round.size()){
				if( round[i].first != menor ) break;
				mask = mask ^ int64(1)<<round[i].second;
			}
			qtd = __builtin_popcount(mask);
			round.clear();
		}
		if( qtd == 0 ) mask = backup;
		bool flag = false;
		REP(i,n){
			if(  mask & (int64)1 << i ){
				//if( flag ) cout << " ";
				cout << names[i];
				cout << " ";
				flag = true;
			}
		}
		cout << "\n";
		round.clear();
		names.clear();
		while(!cartas.empty()) cartas.pop_front();
	}
}

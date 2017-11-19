#include <tr1/unordered_map>
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
using namespace tr1;

#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define RFOR(i, b, a) for(int i = b; i >= a; --i)
#define REP(i, N) for(int i = 0; i < N; ++i)
#define RREP(i, N) for(int i = N-1; i >= 0; --i)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )
#define MAXN 530010
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

int n, k;
typedef vector < int > vi;
typedef vector < vi > vii;
typedef vector < tri > vtri;
typedef vector < vtri > vvtri;
typedef long long int64;
typedef unsigned long long uint64;

int x[] = {-1,-1,-1, 0, 1, 1, 1, 0 };
int y[] = {-1, 0, 1, 1, 1, 0,-1,-1 };
/*
inline void read( int &n ) {
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
*/


int tree[MAXN];
bool flag[MAXN];
int atual[MAXN];

void build (int node, int ld, int rd){
	flag[node] = false;
	atual[node] = 1;
	if ( ld == rd ){
        tree[node] = 1;
 	}
	else{
		int tm = (ld + rd) >> 1;
		build(node*2, ld, tm);
		build(node*2+1, tm+1, rd);
		tree[node] = tree[2*node] = tree[2*node+1] = 1;
	}
}

int get (int node){
	if ( !flag[node] ) return tree[node];
	tree[node] = atual[node];
	atual[2*node] *= atual[node];
	atual[2*node+1] *= atual[node];
	atual[node] = 1;
	flag[2*node] = flag[2*node+1] = true;
	flag[node] = false;
	return tree[node];
}

int get2 (int node, int valor){
	//if ( !flag[node] ) return tree[node];
	tree[node] = valor;
	atual[2*node] /= atual[node];
	atual[2*node+1] /= atual[node];
	atual[node] = valor;
	//flag[2*node] = flag[2*node+1] = true;
	//flag[node] = false;
	return tree[node];
}

int query (int node, int ld, int rd, int l, int r){
	if ( l > rd || r < ld ) return 1;
	if ( ld >= l && rd <= r )
		return get(node);	
	else{
		int tm = (ld + rd) >> 1;
		get(node);
		return query(2*node, ld, tm, l, r) * query(2*node+1, tm+1, rd, l, r);
	}
}

void update (int node, int ld, int rd, int l, int r, int valor){
     if ( l > rd || r < ld ) return;
     if ( ld >= l && rd <= r ){
        //flag[node]  = true;
		//atual[node] = valor;
		get2(node, valor);
        return;
     }
     else{
          int tm = (ld + rd) >> 1;
		  get(node);
          update(2*node, ld, tm, l, r, valor);
          update(2*node+1, tm+1, rd, l, r, valor);
          tree[node] = get(2*node) * get(2*node+1);
     }
}

int main(){
	ios::sync_with_stdio(false);
	int valor, de, para;
	char op;
	
	while( cin >> n >> k ){
		build(1,0,n-1);
		REP(i,n){
			cin >> valor;
			update (1, 0, n-1, i, i, valor);
			query(1,0,n-1, i, i);
		}
		while( k-- ){
			cin >> op;
			if( op == 'P' ){
				cin >> de >> para;
				int ret = query(1,0,n-1, de-1, para-1);
				if( !ret ) cout << '0';
				else if( ret < 0 ) cout << '-';
				else cout << '+';
			}
			else{
				cin >> de >> valor;
				update (1, 0, n-1, de-1, de-1, valor);
			}
		}
		cout << '\n';
	}
	return 0;
}

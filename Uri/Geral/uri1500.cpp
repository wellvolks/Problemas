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
#define MAXN 5000603
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
  
struct aresta{
    int atual;
    string str;
    aresta( int atual = 0, string str = "" ) : atual(atual) , str(str) { }
};
  
typedef vector < int > vi;
typedef vector < vi > vii;
typedef vector < tri > vtri;
typedef vector < vtri > vvtri;
typedef long long int64;
typedef unsigned long long uint64;
  
int x[] = {-1,-1,-1, 0, 1, 1, 1, 0 };
int y[] = {-1, 0, 1, 1, 1, 0,-1,-1 };
  
#ifdef _WIN32 
    #define getchar_unlocked getchar
#endif
 
inline bool read( int &n ) {
    n = 0;
    register bool neg = false;
    register char c = getchar_unlocked();
    if( c == EOF) { n = -1; return false; }
    while (!('0' <= c && c <= '9')) {
        if( c == '-' ) neg = true;
        c = getchar_unlocked();
    }
    while ('0' <= c && c <= '9') {
        n = n * 10 + c - '0';
        c = getchar_unlocked();
    }
    n = (neg ? (-n) : (n));
    return true;
}

uint64 tree[1LL<<20];
uint64 flag[1LL<<20];

void build (int node, int ld, int rd){
     flag[node] = 0;
	 tree[node] = 0;
     if ( ld == rd ){
        return ;
 	}
	else{
		int tm = (ld + rd) >> 1;
		build(node*2, ld, tm);
		build(node*2+1, tm+1, rd);
	}
}

uint64 get (int node, int ld, int rd){
	tree[node] += flag[node] * (rd - ld + 1);
	flag[2*node] = (flag[2*node] + flag[node]);
	flag[2*node+1] = (flag[2*node+1] + flag[node]);
	flag[node] = 0;
	return tree[node];
}

uint64 query (int node, int ld, int rd, int l, int r){
	get(node,2*node,2*node+1);
	if ( l > rd || r < ld ) return 0;
	if ( ld >= l && rd <= r )
		return tree[node];	
	else{
		int tm = (ld + rd) >> 1;
		uint64 a = query(2*node, ld, tm, l, r);
		uint64 b = query(2*node+1, tm+1, rd, l, r);
		return a+b;
	}
}

void update (int node, int ld, int rd, int l, int r, uint64 val){
	 get(node,2*node,2*node+1);
     if ( l > rd || r < ld ) return;
     if ( ld >= l && rd <= r ){
        if( ld == rd ) tree[node] += val;
		else{ 
            tree[node] += val * (rd - ld + 1);
            flag[ 2*node ] += val;
            flag[ 2*node+1 ] += val;
        }
        return;
     }
     else{
          int tm = (ld + rd) >> 1;
		  update(2*node, ld, tm, l, r, val);
          update(2*node+1, tm+1, rd, l, r, val);
          tree[node] = tree[node*2] + tree[2*node+1];
     }
}
 
int main(){
	ios::sync_with_stdio(false);
	int t, n, q, lo, hi, val, op;
	read(t);
	while( t-- ){
		read(n); read(q);
		build(1, 0, n-1);
		while( q-- ){
			read(op); read(lo); read(hi);
			if( op ) cout << query(1,0,n-1, lo-1, hi-1) << '\n';
			else{
				read(val);
				update (1, 0, n-1, lo-1, hi-1, val);
			}
		}
	}
	return 0;
}

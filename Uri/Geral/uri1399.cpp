#include <tr1/unordered_map>
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
using namespace tr1;

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

int k;
typedef vector < int > vi;
typedef vector < vi > vii;
typedef vector < tri > vtri;
typedef vector < vtri > vvtri;
typedef long long int64;
typedef unsigned long long uint64;

#ifdef _WIN32
    #define getchar_unlocked getchar
#endif
      
inline void readInt(  int &n ) {
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

inline void readLong(  uint64 &n ) {
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

struct node_t{
	int sz, pr;
	uint64 key;
	node_t *l, *r;
	node_t( uint64 val = 0 ) : key(val), sz(0), pr(rand()), l(NULL), r(NULL) {}
	~node_t(){ if(l) delete l; if(r) delete r; }
	void walk(int d = 0){
		if( l ) l->walk(d+1);
		REP( i, d ) putchar('\t'); 
		printf("%lld\n", key);
		if( r ) r->walk(d+1);
	}
};

void rotate_right(node_t* &t ){
	node_t* n = t->l;
	t->l = n->r;
	n->r = t;
	t = n;
}

void rotate_left(node_t* &t ){
	node_t* n = t->r;
	t->r = n->l;
	n->l = t;
	t = n;
}

void update(node_t* t){
	if(!t) return;
	t->sz = ((t->l)?(t->l->sz):(0)) + 1 + ((t->r)?(t->r->sz):(0));
}

void fix( node_t* &t ){
	if(!t) return;
	update(t->l); update(t->r); update(t);
}

void insert(node_t* &t, uint64 val){
	if( !t ) t = new node_t(val);
	else{
	//	if( t->key == val ) return;
		if( val < t->key ) insert( t->l, val);
		else insert( t->r, val);
	}
	
	if( t->l && (t->l->pr > t->pr) ) rotate_right(t);
	else if( t->r && (t->r->pr > t->pr) ) rotate_left(t);
	
	fix(t);
}

inline int p( node_t* t ){ return (t ? (t->pr) : (-1)); }

void erase( node_t* &t, uint64 val ){
	if( !t ) return;
	if( t->key != val ) erase( ((val < t->key)?(t->l):(t->r)), val );
	else {
		if( !(t->l) && !(t->r) ){ delete t, t = NULL; }
		else{
			(p(t->l) < p(t->r)) ? rotate_left(t) : rotate_right(t);
			erase( t, val );
		}
	}
	fix(t);
}

int qcount( node_t* t, uint64 val ){
	if( !t ) return 0;
	if( t->key == val ) return (t->l)?(t->l->sz):(0);
	if( val < t->key ) return qcount(t->l, val);
	return ((t->l)?(t->l->sz):(0)) + 1 + qcount(t->r, val);
}

long long kth( node_t* t, int k ){
	int lsz = (t->l)?(t->l->sz):(0);
	if( lsz+1 == k ) return t->key;
	if( lsz >= k ) return kth(t->l, k);
	return kth(t->r, k-lsz-1 );
}



int main(){
	srand(time(NULL));
	uint64  u, val, v;
	int n, m;
	
	readInt(n);// readInt(m); readLong(u);
	
	node_t *treap = NULL;
	
	multimap < uint64, int > mapa;
	multimap< uint64,int>::iterator it;
	
	REP(i,(int)n){
		readLong(val);
		insert(treap,val);
		mapa.insert(mk(val,1));
	}
	it = lower_bound(10);
	cout << (it - mapa.begin()) << "\n";
	int lo, hi, p;
	REP(i,(int)m){
		readInt(lo);
		readInt(hi);
		readLong(v);
		readInt(p);
	}
	//num = kth(treap,(i>>1)+1);
	return 0;
}


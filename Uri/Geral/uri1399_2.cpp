#include <bits/stdc++.h>
  
using namespace std;
  
typedef long long int64;
typedef unsigned long long uint64;

#ifdef _WIN32
    #define getchar_unlocked getchar
    #define putchar_unlocked putchar
#endif
   
   
bool readLong ( long long &n ) {
    n = 0LL;
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

bool readInt ( int &n ) {
    n = 0LL;
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
 
inline void writeLong(long long n){
    register int idx = 20;
    if( n < 0 ) putchar_unlocked('-');
    n = abs(n);
    char out[21];
    out[20] = ' ';
    do{
        idx--;
        out[idx] = n % 10 + '0';
        n/= 10;
    }while(n);
    do{ putchar_unlocked(out[idx++]); } while (out[idx] != ' ');
}

int n, m;
int64 u, v;

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
    //  if( t->key == val ) return;
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

vector < node_t > tree[4*100001];

void build( int v, int tl, int tr ){
    if( tl == tr ) tree[v].insert(vet[tl]);
    else{
        int tm = (tl + tr) >> 1;
        int lo = v<<1;
        int hi = lo+1;
        build(lo, tl, tm);
        build(hi, tm+1, tr);
        merge(tree[lo].begin(), tree[lo].end(), tree[hi].begin(), tree[hi].end(), back_inserter(tree[v]));
    }
}

int query( int v, int tl, int tr, int l, int r, int64 x ){
    if( l > r ) return 0;
    if( l == tl && tr == r ){
        vector < int64 > :: iterator it = lower_bound(tree[v].begin(), tree[v].end(), x);
        if( it == tree[v].end() ) return 0;
        else return (it - vet[v].begin());
    }
    int tm = (tl + tr) >> 1;
    int lo = v << 1;
    int hi = lo + 1;
    return query(lo, tl, tm, l, min(r,tm), x) + query(hi, tm+1, tr, max(l,tm+1), r, x);
}

void upadte( int v, int tl, int tr, int pos, int64 val ){
    tree[v].
    if( tl != tr ){
        int tm = ( tl + tr ) >> 1;
        if( pos <= tm ) 
    }
}

vector < pair < int64, int > > aux;
vector < int64 > vet;
vector < int > pos; 
int id[1000000];

int main(){
    ios::sync_with_stdio(false);
    readInt(n);
    readInt(m);
    readLong(u);

    for( int i = 0; i < n; i++ ){
        readLong(val);
        aux.push_back(make_pair(val,i));
    }
    
    sort(aux.begin(),aux.end());
    for( int i = 0; i < n; i++ ){
        aux.push_back(aux[i].first);
        pos.push_back(aux[i].second);
        id[aux[i].second] = i;
    }

    while( m-- ){
        readInt(l);
        readInt(r);
        readLong(v);
        readInt(p);
        vector < int64 > :: iterator it = lower_bound(vet.begin(), vet.end());
        if( it == vet.end() ) aux[id[p-1]] = 0LL;
        else{

        }
    }
    return 0;
}
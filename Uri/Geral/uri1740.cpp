#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef unsigned long long uint64;

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

struct tri{
	int tipo, lo, hi;
	tri( int tipo = 0, int lo = -1000000001, int hi = -1000000001) : tipo(tipo), lo(lo), hi(hi) { }
};

int  n, q;

tri mergeEqual(tri &a, tri &b){
	switch( b.tipo ){
		case 0: 
			if( a.lo == b.hi ) return tri(0, a.lo, b.lo);
			if( a.hi < b.lo ) return tri(1, a.lo, b.hi);
			return tri(2,b.lo,a.lo);
			break;
		case 1: 
			if( a.lo == b.lo ) return b;
			if( a.lo > b.lo ) return tri(3, 0, 0);
			return tri(1, a.lo, b.hi);
			break;
		case 2: 
			if( a.lo == b.hi ) return b;
			if( a.lo < b.hi ) return tri(3, a.lo, b.hi);
			return tri(2, b.lo, a.lo);
			break;
		case 3: return tri(3,0,0); break;
	}
}

tri mergeNonDecreasing(tri &a, tri &b){
	switch( b.tipo ){
		case 0: 
			if( a.hi <= b.lo ) return tri(1, a.lo, b.hi);
			break;
		case 1: 
			if( a.hi <= b.lo ) return tri(1, a.lo, b.hi);
			break;
	}
	return tri(3, 0, 0);
}

tri mergeNonIncreasing(tri &a, tri &b){
	switch( b.tipo ){
		case 0: 
			if( a.lo >= b.hi ) return tri(2, b.lo, a.hi);
			break;
		case 2: 
			if( a.lo >= b.hi ) return tri(2, b.lo, a.hi);
			break;
	}
	return tri(3, 0, 0);
}

tri mergeNone(tri &a, tri &b){
	return tri(3,0,0);
}

tri merge( tri &a, tri &b ){
	if( a.lo == -1000000001 && b.lo == -1000000001 ) return tri(3,0,0);
	if( a.lo == -1000000001 ) return b;
	if( b.lo == -1000000001 ) return a;
	switch( a.tipo ){
		case 0: return mergeEqual(a, b); break; // all equal
		case 1: return mergeNonDecreasing(a,b); break; // non decreasing
		case 2: return mergeNonIncreasing(a,b); break; // non increasing
		case 3: return mergeNone(a,b); break; // none
	}
}

struct node_t {
    int key, pr, sz;
    tri seg;

    node_t *l, *r;
       
    node_t(int k) : key(k), pr(rand()), sz(0), l(NULL), r(NULL) {}
       
    ~node_t() {
        if(l) delete l;
        if(r) delete r;
    }
};
 
void rotate_right(node_t* &t) {
        node_t *n = t->l;
        t->l = n->r;
        n->r = t;
        t = n;
}
 
void rotate_left(node_t* &t) {
        node_t *n = t->r;
        t->r = n->l;
        n->l = t;
        t = n;
}
 
void fix(node_t* t) {
    if(!t) return;
    t->sz = 1 + ((t->l)?(t->l->sz):(0)) + ((t->r)?(t->r->sz):(0));
    tri lseg, rseg, at = tri(0, t->key, t->key);
    lseg = (t->l)?((t->l->seg)):(tri(0,-1000000001,-1000000001));
    rseg = (t->r)?((t->r->seg)):(tri(0,-1000000001,-1000000001));
    t->seg = merge(lseg, at);
    t->seg = merge(t->seg, rseg);
}
 
void insert(node_t* &t, int val, int pos) {
    if(!t) t = new node_t(val);
    else {
        int lsz = ((t->l)?(t->l->sz):(0));
        if (lsz >= pos) insert(t->l, val, pos);
        else insert(t->r, val, pos-lsz-1);
    }
    if (t->l && ((t->l->pr) > (t->pr))) rotate_right(t);
    else if (t->r && ((t->r->pr) > (t->pr))) rotate_left(t);
    fix(t->l); fix(t->r); fix(t);
}
 
inline int p(node_t* t) { return (t) ? (t->pr) : (-1); }
 
void erase(node_t* &t, int pos) {
	if(!t) return;
	int lsz = ((t->l)?(t->l->sz):(0));
	if (lsz+1 != pos) {
		if (lsz >= pos) erase(t->l, pos);
		else erase(t->r, pos-lsz-1);
	} 
	else{
		if (!t->l && !t->r) {
			delete t;
			t = NULL;
		}
		else{
			if (p(t->l) < p(t->r)) rotate_left(t);
			else rotate_right(t);
			erase(t, pos);
		}
	}

	if (t) { fix(t->l); fix(t->r); fix(t); }
}
 
void replace(node_t* t, int pos, int val) {
        if(!t) return;
       
        int lsz = ((t->l)?(t->l->sz):(0));
        if (lsz+1 != pos) {
            if (lsz >= pos) replace(t->l, pos, val);
            else replace(t->r, pos-lsz-1, val);
        } else t->key = val;
       
        fix(t);
}
 
int ith(node_t* t, int i) {
        int lsz = (t->l)?(t->l->sz):(0);
        if (lsz+1 == i) return t->key;
        if (lsz >= i) return ith(t->l, i);
        return ith(t->r, i-lsz-1 );
}

int x, y;
tri query(node_t* t, int lo, int hi) {
	if (x <= lo && hi <= y) return t->seg;

	int mid = lo + ((t->l)?(t->l->sz):(0)) - 1;

	tri q1, q2, ans, at = tri(0, t->key, t->key);
	bool f1 = false, f2 = false;

	if (mid >= lo && mid >= x) { f1 = true; q1 = query(t->l, lo, mid); }
	if (mid+2 <= hi && mid+2 <= y) { f2 = true; q2 = query(t->r, mid+2, hi); }

	if (!f1 && !f2) return at;

	if (f1 && f2) {
		ans = merge(q1, at);
		return merge(ans, q2);
	}
	else if (f1) {
		if (x <= mid+1 && mid+1 <= y){
			return merge(q1, at);
		}
		else return q1;
	}
	else if (x <= mid+1 && mid+1 <= y) {
		return merge(at, q2);
	} 
	return q2;
}

int main(){
	ios::sync_with_stdio(false);
	srand(time(NULL));
	string ans[] = {"ALL EQUAL","NON DECREASING","NON INCREASING","NONE"};
	string resp = "";
	int op, lo, hi, val;
	while( read(n) ){
		node_t *treap = NULL;
		for( int i = 0; i < n; i++ ){
			read(val);
			insert(treap, val, i);
		}
		read(q);
		for( int i = 0; i < q; i++ ){
			read(op);
			switch(op){
				case 0:
					read(x);
					read(y);
					lo = ith(treap, x);
					hi = ith(treap, y);
					replace(treap, x, hi);
					replace(treap, y, lo);
					break;
				case 1:
					read(x);
					read(y);
					replace(treap, x, y);
					break;
				case 2:
					read(x);
					read(y);
					insert(treap, y, x-1);
					break;
				case 3:
					read(x);
					erase(treap, x);
					break;
				case 4:
					read(x);
					read(y);
					resp += ans[query(treap, 1, treap->sz).tipo];
					resp += "\n";
				break;
			}
		}
	}
	cout << resp;
	return 0;
}

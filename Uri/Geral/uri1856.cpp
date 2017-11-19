#include <bits/stdc++.h>

using namespace std;

 
#ifdef _WIN32  
    #define getchar_unlocked getchar 
    #define putchar_unlocked putchar 
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

inline void writeInt(int n){ 
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

typedef long long int64;

typedef struct item * pitem;

unordered_map < long long, pitem > mapa;

struct item {
	int prior, cnt;
	bool rev;
	pitem l, r, testeDNA;
	item() : prior(rand()), rev(false), cnt(0), l(NULL), r(NULL), testeDNA(NULL) { }
};

void updatePai(pitem t, pitem &l, pitem &r){
	if (!t) return;
	if (l) l->testeDNA = t;
	if (r) r->testeDNA = t;
}

void push(pitem it) {
	if (it) {
		updatePai(it, it->l, it->r);
		if (it->rev){
			it->rev = false;
			swap(it->l, it->r);
			if (it->l)  it->l->rev ^= true;
			if (it->r)  it->r->rev ^= true;
		}
	}
}

int cnt(pitem it) {
	return it ? it->cnt : 0;
}

void upd_cnt(pitem it) {
	if (it){
		it->cnt = cnt(it->l) + cnt(it->r) + 1;
		push(it);
	}
}

void merge(pitem & t, pitem l, pitem r) {
	push(l);
	push(r);
	if (!l || !r)
		t = l ? l : r;
	else if (l->prior > r->prior)
		merge(l->r, l->r, r), t = l;
	else
		merge(r->l, l, r->l), t = r;
	upd_cnt(t);
}

void split(pitem t, pitem & l, pitem & r, int key, int add = 0) {
	if (!t)
		return void(l = r = 0);
	push(t);
	int cur_key = add + cnt(t->l);
	if (key <= cur_key){
		split(t->l, l, t->l, key, add);
		r = t;
	}
	else{
		split(t->r, t->r, r, key, add + 1 + cnt(t->l));
		l = t;
	}
	if (l) l->testeDNA = NULL;
	if (r) r->testeDNA = NULL;
	upd_cnt(r);
	upd_cnt(l);
}

void upToTree(pitem t){
	if (!t) return;
	upToTree(t->testeDNA);
	push(t);
}

int kth(pitem t){
	if (!t->testeDNA) return 0;
	if (t->testeDNA->l == t) return kth(t->testeDNA);
	return kth(t->testeDNA) + ((t->testeDNA->l) ? (t->testeDNA->l->cnt) : (0)) + 1;
}

int main(){
	ios::sync_with_stdio(false);

	srand(time(NULL));
	int n, q, p, e, a, b, k, ka, kb, val;
	char op;

	read(n);

	pitem treap = NULL;

	for (int i = 0; i < n; i++){
		read(val);
		mapa[val] = new item();
		merge(treap, treap, mapa[val]);
	}

	read(q);

	while( q-- ){
		op = getchar_unlocked();
		while( !isalpha(op) ) op = getchar_unlocked();

		pitem t1, t2, t3;
		
		switch( op ){
			case 'I':
				read(p); read(e);
				upToTree(mapa[e]);
				k = kth(mapa[e]) + ((mapa[e]->l) ? (mapa[e]->l->cnt) : (0));
				mapa[p] = new item();
				split(treap, t1, t2, k+1);
				merge(treap, t1, mapa[p]);
				merge(treap, treap, t2);
			break;
			case 'R':
				read(e);
				upToTree(mapa[e]);
				k = kth(mapa[e]) + ((mapa[e]->l) ? (mapa[e]->l->cnt) : (0));
				split(treap, t1, t2, k);
				split(t2, t2, t3, 1);
				merge(treap, t1, t3);
			break;
			case 'Q':
				read(a); read(b);
				upToTree(mapa[a]);
				upToTree(mapa[b]);
				ka = kth(mapa[a]) + ((mapa[a]->l) ? (mapa[a]->l->cnt) : (0));
				kb = kth(mapa[b]) + ((mapa[b]->l) ? (mapa[b]->l->cnt) : (0));
				writeInt(max(0,abs(kb-ka)-1));
				putchar_unlocked('\n');
			break;
		}
		/*
		unordered_map < int, pitem > :: iterator it = mapa.begin();
		while( it != mapa.end() ){
			int kk = it->first;
			upToTree(mapa[kk]);
			cout << it->first << " " << kth(it->second) + ((it->second->l) ? (it->second->l->cnt) : (0)) << endl;;
			it++;
		}*/
	}

	return 0;
}
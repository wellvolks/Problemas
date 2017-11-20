#include <bits/stdc++.h>

using namespace std;
#define MAXD 5500000

typedef long long int64;
typedef unsigned long long uint64;

#ifdef _WIN32  
    #define getchar_unlocked getchar 
    #define putchar_unlocked putchar 
#endif 

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

string str = "";

struct tri{
    int letra[28];
    tri(){
        memset(letra, 0, sizeof(letra));
    }
};

tri combine( tri &a, tri &b ){
    tri novo;
    for(int i = 0; i < 28; i++){
        novo.letra[i] = a.letra[i] + b.letra[i];
    }
    novo.letra;
    return novo;
}

struct node{
    int c, y, val, swap;
    tri sum;
    node *l, *r; 
    node(){}
    node( int v ){
        val=v;
        sum.letra[v] = 1;
        y=rand();
        c=1;
        swap=0;
    }
};

FILE *in, *out;
node null, data[MAXD];
node *tree;
int d_cnt = 0;

node* new_node( int val ){
    node *ret = &(data[d_cnt++]=node(val));
    ret->r=ret->l=&null;
    return ret;
}

void relax( node* t ){
    if( t!=&null ){
        t->c = t->l->c + t->r->c + 1;

        for(int i = 0; i < 27; i++){
            t->sum.letra[i] = 0;
            if( t->l != &null ) t->sum.letra[i] = t->l->sum.letra[i];
            if( t->r != &null ) t->sum.letra[i] += t->r->sum.letra[i];
        }
        t->sum.letra[t->val]++;
        
        if( t->swap==1 ){
            node* aux=t->l;
            t->l=t->r;
            t->r=aux;
            t->l->swap^=1;
            t->r->swap^=1;
            t->swap=0;
        }
    }
}

void relax_child( node* &t ){
    if( t!=&null ){
        relax(t);
        relax(t->l);
        relax(t->r);
    }
}

void split( node* &t, int x, node* &lt, node* &rt){
    relax_child(t);
    if( t==&null ){
        lt=rt=&null;
    }
    else{
        node *a, *b;
        if( x <= t->l->c ){
            split(t->l,x,a,b);
            t->l=b;
            lt=a;
            rt=t;
            relax(t);
        } 
        else{
            split(t->r,x-t->l->c-1,a,b);
            t->r=a;
            lt=t;
            rt=b;
            relax(t);
        }
    }
}

void merge( node* &t1, node* &t2, node* &t ){
    relax_child(t1);
    relax_child(t2);
    if( t1==&null ){
        t = t2;
    }
    else if( t2==&null ){
        t = t1;
    }
    else{
        node* a;
        if( t1->y < t2->y ){
            merge(t1->r,t2,a);
            t1->r = a;
            relax(t1);
            t = t1;
        }
        else{
            merge(t1,t2->l,a);
            t2->l = a;
            relax(t2);
            t = t2;
        }
    }
}

void insert( node* &t, int pos, int val ){
    node *lt, *rt, *a, *b;
    split(t,pos-1,lt,rt);
    a = new_node(val);
    merge(lt,a,b);
    merge(b,rt,t);
}

void put_print( node* t ){
    relax_child(t);
    if( t!=&null ){
        put_print(t->l);
        str += char(t->val+'a');
        put_print(t->r);
    }
}

void up( node* t ){
    relax_child(t);
    if( t!=&null ){
        put_print(t->l);
        put_print(t->r);
    }
}

int querySum( node* &t, int a, int b, int c){
    int ret=0;
    if( t!=&null ){
        relax_child(t);
        if( a<=1 && t->c<=b ){
            return t->sum.letra[c];
        }
        if( t->l->c >= a ){
            ret+=querySum(t->l,a,b, c);
        }
        if( t->l->c+1 >= a && t->l->c+1 <= b ){
            ret+=t->val == c;
        }
        if( b > t->l->c+1 ){
            ret+=querySum(t->r,a-t->l->c-1,b-t->l->c-1, c);
        }       
    }
    return ret;
}

void reverse( node* &t, int a, int b ){
    node *t1, *t2, *t3, *aux;
    split(t,a-1,t1,aux);
    split(aux,b-a+1,t2,t3);
    t2->swap^=1;
    merge(t1,t2,aux);
    merge(aux,t3,t);    
}

int queryRangeHi(node *& t, int c){
    if( t != &null ){
        relax_child(t);
        if( !t->sum.letra[c] || !t->c ) return 0;
        if( t->r && t->r->sum.letra[c] ) return queryRangeHi(t->r, c) + 1 + ((t->l) ? (t->l->c) : (0));
        else if( t->val != c && t->l && t->l->sum.letra[c] ) return queryRangeHi(t->l, c);
        return (t->val == c) +  ((t->l) ? (t->l->c) : (0));
    }
    return 0;
}

int queryRangeLo(node *& t, int c){
    if( t != &null ){
        relax_child(t);
        if(!t->sum.letra[c] || !t->c) return 0;
        if( t->l && t->l->sum.letra[c] ) return queryRangeLo(t->l, c);
        else if( t->val == c ) return 1 + ((t->l) ? (t->l->c) : (0));
        else if( t->r && t->r->sum.letra[c] ) return queryRangeLo(t->r, c) + 1 + ((t->l) ? (t->l->c) : (0));
        return t->val == c;
    }
    return 0;
}

pair < int, int > queryRange(node *&t, int a, int b, int val) {
    pair < int, int > ans;
    node *t1, *t2, *t3, *aux;
    relax_child(t);
    split(t,a-1,t1,aux);
    split(aux,b-a+1,t2,t3);
    ans.first = queryRangeLo(t2, val)-1;
    ans.second = queryRangeHi(t2, val)-1;
    merge(t1,t2,aux);
    merge(aux,t3,t);
    return ans;
}


int main(){
    ios::sync_with_stdio(false);
    srand(time(NULL));
    /*
    cout << 1000000 << " " << 100000 << "\n";
    for(int i = 0; i < 1000000; i++){
        cout << char((rand() % 26)+'a');
    }
    cout << endl;
    int t = 1000000;
    for(int i = 0; i < 100000; i++){
        int op = (rand() % 4);
        cout << max(op+1,2) << " ";
        if( op == 0 ){
            int u = rand() % t;
            int v = rand() % t;
            char c = (rand() % 26)+'a';
            cout << min(u,v)+1 << " " << max(u,v)+1 << " " << c << endl;
        }
        if( op <= 1){
            int u = rand() % t;
            int v = rand() % t;
            char c = (rand() % 26)+'a';
            cout << min(u,v)+1 << " " << max(u,v)+1 << " " << c << endl;
        }
        if( op == 2 ){
            int u = rand() % t;
            int v = rand() % t;
            cout << min(u,v)+1 << " " << max(u,v)+1 << endl;
        }
        if( op == 3 ){
            cout << (rand() % t)+1 << " " << char((rand() % 26)+'a') << endl;
            t++;
        }
    }
    exit(1);*/
    int l, n, a, b, lo, hi, mid, s, p1 = 0, p2 = 0, op, qt;
    pair < int, int > p;
    char c;
    str = "";
    cin >> l >> n;
    d_cnt=0;
    tree = &null;
    null.c = 0;
    null.val = 0;
    cin >> str;
    for(int i = 0; i < l; i++){
        insert(tree,i+1,str[i]-'a');
    }
    int k = 1, w = 1;
    while( n-- ){
        relax_child(tree);
        cin >> op;
        switch(op){
            case 1:
                cin >> a >> b >> c;
                if( b < a ) swap(a,b);
                cout << querySum(tree, a, b, c-'a') << '\n';
            break;
            case 2:
                cin >> a >> b >> c;
                if( b < a ) swap(a,b);
                qt = querySum(tree, a, b, c-'a');
                if( qt <= 0 ) cout << "-1\n";
                else{
                    p = queryRange(tree, a, b, c-'a');
                    cout << p.first+a << " " << p.second+a << '\n';
                }
            break;
            case 3:
                cin >> a >> b;
                if( b < a ) swap(a,b);
                reverse(tree, a, b);
            break;
            case 4:
                cin >> a >> c;
                insert(tree, a, c-'a');
                l++;
            break;
        }
    }
    str = "";
    put_print(tree);
    cout << str << endl;
    return 0;
}

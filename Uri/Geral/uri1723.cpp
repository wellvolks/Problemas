//#include <tr1/unordered_map>
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
//using namespace tr1;

#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define RFOR(i, b, a) for(int i = b; i >= a; --i)
#define REP(i, N) for(int i = 0; i < N; ++i)
#define RREP(i, N) for(int i = N-1; i >= 1; --i)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )
#define MAXN 20101
#define LINF 0x3F3F3F3FFFFFFFFFLL
#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) __typeof((X).begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) int((V).size())
#define pb push_back
#define mk make_pair

typedef long long int64;
typedef unsigned long long uint64;

struct tri{
    int mask[1001], cust;
};
  
  
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

int n, m;

char str[1025][1010];
string opc = "ARNDCQEGHILKMFPSTWYV";
int id[400];
int mask[10001];

tri tree[2048];

void merge( int node, int lo, int hi ){
    int l = 0, r = m-1;
    tree[node].cust = tree[lo].cust + tree[hi].cust;
    while( l <= r ){
        if( tree[lo].mask[l] & tree[hi].mask[l] ){
            //tree[node].mask[l] = 0;
            int mask = (tree[lo].mask[l] & tree[hi].mask[l]);
            tree[node].mask[l] |= mask;//(mask ^ (mask & (mask-1)));
        }
        else{
            tree[node].mask[l] = (tree[lo].mask[l] | tree[hi].mask[l]);
            tree[node].cust++;
        }
        if( l == r ) break;
        if( tree[lo].mask[r] & tree[hi].mask[r] ){
            //tree[node].mask[r] = 0;
            int mask = (tree[lo].mask[r] & tree[hi].mask[r]);
            tree[node].mask[r] |= mask;//(mask ^ (mask & (mask-1)));
        }
        else{
            tree[node].mask[r] = (tree[lo].mask[r] | tree[hi].mask[r]);
            tree[node].cust++;
        }
        l++;
        r--;
    }
}

void segmentTree( int node, int lo, int hi ){
    tree[node].cust = 0;
    if( lo == hi ){
        int l = 0, r = m-1;
        while( l <= r ){
            tree[node].mask[l] = ( 1 << id[str[lo][l]]);
            tree[node].mask[r] = ( 1 << id[str[lo][r]]);
            l++;
            r--;
        }
    }
    else{
        int mid = ( lo + hi ) >> 1;
        int l = ( node << 1 ) + 1;
        int r = l + 1;
        segmentTree( l, lo, mid );
        segmentTree( r, mid+1, hi );
        merge(node,l,r);
    } 
}


int main(){
    ios::sync_with_stdio(false);

    REP(i,20) id[opc[i]] = i;

    while( cin >> n >> m && (n+m) ){
        
        REP(i,n) cin >> str[i];
        
        segmentTree(0, 0, n-1);

        REP(i,m){
            REP(j,20){
                if( tree[0].mask[i] & (1 << j) ){
                    cout << opc[j];
                    break;
                }
            }
        }
        cout << " " << tree[0].cust  << "\n";
        memset(tree,0,sizeof(tree));
    }
    return 0;
}


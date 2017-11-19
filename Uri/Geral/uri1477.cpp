#include <list>
#include <set>
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
#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFFLL
#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) __typeof((X).begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) int((V).size())
#define pb push_back
#define mp make_pair
 
typedef  long long int64;
#define MAXN 530010

typedef struct segment{
       int h, e, r;
}iii;

iii tree[MAXN];
int flag[MAXN];

void build (int node, int ld, int rd){
     flag[node] = 0;
     if ( ld == rd ){
        tree[node].h = 1;
		tree[node].e = 0;
		tree[node].r = 0;
 	}
	else{
		int tm = (ld + rd) >> 1;
		build(node*2, ld, tm);
		build(node*2+1, tm+1, rd);
		tree[node].h = tree[2*node].h + tree[2*node+1].h;
		tree[node].e = tree[2*node].e + tree[2*node+1].e;
		tree[node].r = tree[2*node].r + tree[2*node+1].r;
	}
}
iii get (int node){
	if ( !flag[node] ) return tree[node];
	int i;
	for ( i = 0; i < flag[node]; i++ ){
        int x = tree[node].h;
		tree[node].h = tree[node].r;
		int y = tree[node].e;
		tree[node].e = x;
		tree[node].r = y;
	}
	flag[2*node] = (flag[2*node] + flag[node]) % 3;
	flag[2*node+1] = (flag[2*node+1] + flag[node]) % 3;
	flag[node] = 0;
	return tree[node];
}
iii query (int node, int ld, int rd, int l, int r){
    iii zero;
    zero.h = 0; zero.e = 0; zero.r = 0;
	if ( l > rd || r < ld ) return zero;
	if ( ld >= l && rd <= r )
		return get(node);	
	else{
		int tm = (ld + rd) >> 1;
		get(node);
		iii a = query(2*node, ld, tm, l, r);
		iii b = query(2*node+1, tm+1, rd, l, r);
		a.h += b.h; a.e += b.e; a.r += b.r;
		return a;
	}
}
void update (int node, int ld, int rd, int l, int r){
     if ( l > rd || r < ld ) return;
     if ( ld >= l && rd <= r ){
        flag[node] = (flag[node] + 1) % 3;
        return;
     }
     else{
          int tm = (ld + rd) >> 1;
          update(2*node, ld, tm, l, r);
          update(2*node+1, tm+1, rd, l, r);
          iii a = get(2*node);
          iii b = get(2*node+1);
          a.h += b.h; a.e += b.e; a.r += b.r;
          tree[node] = a;
     }
}

int main(){
	int n, m, a, b;
	char c;
	while ( scanf("%d %d", &n, &m) != EOF ){
          build(1, 0, n-1);
          while ( m-- ){
                scanf(" %c %d %d", &c, &a, &b);
                if ( c == 'C' ){
                   iii resp = query(1,0,n-1, a-1, b-1);
                   printf("%d %d %d\n", resp.h, resp.e, resp.r);
                }
                else
                    update (1, 0, n-1, a-1, b-1);
          }
          printf("\n");
	}
	return 0;
}

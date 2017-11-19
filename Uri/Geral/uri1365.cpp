#include <bits/stdc++.h>

#define pb push_back
#define mk make_pair
#define INF 0x3f3f3f3f
#define LINF 0x3F3F3F3FFFFFFFFFLL

using namespace std;

typedef int int64;
typedef unsigned long long uint64;

int n, m, tot, sa, sb;

#ifdef _WIN32 
    #define getchar_unlocked getchar
#endif
   
bool read( int &n ) {
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

int tree[400][400];
int mat[320][320];

struct pt{
	int x, y;
	pt( int x = 0, int y = 0 ) : x(x), y(y) { }
};

int getTot( int a, int b ){
	return abs(a-sa) * abs(b-sb);
}

int64 sum(int x,int y){ 
   int64 sum= 0;         
     while(x){
          int y1 = y;
         while(y1){
             sum = (sum + tree[x][y1]);
               y1 -= y1 & -y1;
        }
        x -= x & -x;
    }
  	return sum;
}
 
void update(int x , int y , int64 val){
    int y1;
    while (x <= n+2){
        y1 = y;
        while (y1 <= m+2){
            tree[x][y1] = (tree[x][y1] + val);
            y1 += (y1 & -y1); 
        }
        x += (x & -x); 
    }
}

int64 get(int a, int b){
	return mat[a][b];
}

int64 cordCorrect( pt a, pt b ){
    return ((((get(b.x,b.y) - ((get(a.x-1,b.y) + get(b.x,a.y-1)))))) + get(a.x-1,a.y-1));
}

int main(){
	ios::sync_with_stdio(false);
	char at;
	while( true ){
		read(n); read(m); read(tot);
		if(!(n + m + tot)) break;
		memset(tree, 0, sizeof(tree));
		memset(mat, 0, sizeof(mat));
		for( int i = 0; i < n; i++ ){
			for( int j = 0; j < m; j++ ){
				at = getchar_unlocked();
				while( at != '.' && at != 'X' ) at = getchar_unlocked();
				if( at == '.' ) update(i+1, j+1, 1);
			}
		}
		int ans = 1e9;
		for( int i = 1; i <= n; i++ ){
			for( int j = 1; j <= m; j++ ){
				mat[i][j] = sum(i,j);
			}
		}
		for( int i = 1; i <= n; i++ ){
			for( int j = 1; j <= m; j++ ){
				if( cordCorrect(pt(i, j), pt(n, m)) < tot) break;
				for( int w = 0; w+j <= m; w++ ){
					int lo = 0, hi = (n-i)+1, mid;
					while( lo <= hi ){
						mid = ( lo + hi ) >> 1;
						int r = cordCorrect(pt(i, j), pt(i+mid, j+w));
						if( r >= tot ){
							ans = min(ans, (mid+1) * (w+1));
							hi = mid-1;
						}
						else lo = mid+1;
					}
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}

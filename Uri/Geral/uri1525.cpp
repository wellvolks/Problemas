#include <bits/stdc++.h>
#include <tr1/unordered_map>
  
using namespace std;
using namespace tr1;
  
typedef long long int64;
typedef unsigned long long uint64;
  
int n, m, k;
  
char inv[400];
int used[110][110][110], vis = 1;
char mat[110][110];
int dir[400];
  
int x[] = {-1,0,1,0};
int y[] = {0,1,0,-1};
  
bool solve( int lo, int hi, int qt){
    if( mat[lo][hi] == '.' ) return (qt <= k );
    if( qt > k ) return false;
    if( used[lo][hi][qt] == vis ) return false;
    used[lo][hi][qt] = vis;
    int xx = lo + x[dir[mat[lo][hi]]];
    int yy = hi + y[dir[mat[lo][hi]]];
    if( mat[lo][hi] == 'x' ){
        for( int i = 0; i < 4; i++ ){
            xx = lo + x[i];
            yy = hi + y[i];
            if( (i == dir[mat[lo][hi]] || i == dir[inv[mat[lo][hi]]]) && xx >= 0 && xx <= n && yy >= 0 && yy <= m && solve(xx,yy,qt) ) return true;
        }
    }
    else{
        if( xx >= 0 && xx <= n && yy >= 0 && yy <= m && mat[xx][yy] != 'x' && solve(xx,yy,qt) ) return true;
        xx = lo + x[dir[inv[mat[lo][hi]]]];
        yy = hi + y[dir[inv[mat[lo][hi]]]];
        if( xx >= 0 && xx <= n && yy >= 0 && yy <= m && mat[xx][yy] != 'x' && solve(xx,yy,qt+1) ) return true;
    }
    return false;
}
  
int main(){
    ios::sync_with_stdio(false);
    inv['>'] = '<';
    inv['<'] = '>';
    inv['^'] = 'v';
    inv['v'] = '^';
    inv['x'] = 'x';
    dir['^'] = 0;
    dir['>'] = 1;
    dir['v'] = 2;
    dir['<'] = 3;
    int lo, hi;
    char c;
    string ans[] = {"Nao","Sim"};
    while( cin >> n >> m >> k && (n+m+k) ){
        memset(mat,'.',sizeof(mat));
        for( int i = 1; i <= n; i++ ){
            for( int j = 1; j <= m; j++ ){
                cin >> c;
                mat[i][j] = inv[c];
                if( c == 'x' ){ lo = i; hi = j; }
            }
        }
        n++; m++;
        cout << ans[solve(lo,hi,0)] << "\n";
        vis++; 
    }
    return 0;
}
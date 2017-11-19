#include <bits/stdc++.h>
 
using namespace std;
 
int mat[110][110];

int main(){
    ios::sync_with_stdio(false);
    int n;
    while( cin >> n ){
        int d = n/3;
        int m = (n - (d*2))/2;
        memset(mat, 0, sizeof(mat));
        for( int i = 0; i < n; i++ ){
            mat[i][i] = 2;
            mat[i][n-1-i] = 3;
            mat[n-1-i][i] = 3;
            mat[n-1-i][n-1-i] = 2;
        }
        for( int i = 0; i <= m*2; i++ ){
            for( int j = 0; j <= m*2; j++ ){
                mat[i+d][j+d] = 1;
            }
        }
        mat[n>>1][n>>1] = 4;
        for( int i = 0; i < n; i++){
            for( int j = 0; j < n; j++ ){
                cout << mat[i][j];
            }
            cout << '\n';
        }
        cout << '\n';
    }
    return 0;
}
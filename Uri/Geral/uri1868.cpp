#include <bits/stdc++.h>
 
using namespace std;
 
int x[] = {0,1,0,-1};
int y[] = {1,0,-1,0};

char mat[100][100];
int used[100][100], vis = 1;
vector < string > ans;

int main(){
    ios::sync_with_stdio(false);
    int t;
    while( cin >> t && t ){
        memset(mat, 'O', sizeof(mat));
        mat[t>>1][t>>1] = 'X';
        for( int i = 0; i < t; i++ ){
            for( int j = 0; j < t; j++ ){
                cout << mat[i][j];
            }
            cout << '\n';
        }
        cout << "@\n";
        mat[t>>1][t>>1] = 'O';
        mat[t-1][t-1] = 'X';

        int atx = t-1;
        int aty = t-1;
        int id = 2;
        ans.clear();
        used[t-1][t-1] = vis;
        while( !(atx == t>>1 && aty == t>>1) ){
            string aux = "";
            for( int i = 0; i < t; i++ ){
                for( int j = 0; j < t; j++ ){
                    aux += mat[i][j];
                }
                aux += "\n";
            }
            ans.push_back(aux);
            mat[atx][aty] = 'O';
            atx += x[id];
            aty += y[id];
            if( atx < 0 || atx >= t || aty < 0 || aty >= t || used[atx][aty] == vis){
                atx -= x[id];
                aty -= y[id];
                id = (id + 1) % 4;
                atx += x[id];
                aty += y[id];
            }
            used[atx][aty] = vis;
            mat[atx][aty] = 'X';
            if( atx == (t>>1) && aty == (t>>1) ) break;
        }
        reverse(ans.begin(), ans.end());
        for( int i = 0;  i < ans.size(); i++ ){
            cout << ans[i] << "@\n";
        }
        vis++;
    }
    return 0;
}
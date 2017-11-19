#include <bits/stdc++.h>

using namespace std;

bool check( int a, int b, int c, int d, int dir){
	if( !(a+b+c+d) ) return false;
	if( (a == b && a) || (b == c && c) || (c == d && d) ) return true;
	if( dir == 1 ) return ( (a && (!b || !c || !d)) || (b && (!c || !d )) || (c && !d ) );
	return ( (d && (!c || !b || !a)) || (c && (!b || !a)) || (b && !a) );
}

int mat[5][5];

int main(){
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while( t-- ){
		bool ok = true;
		for( int i = 0; i < 4; i++ ) for( int j = 0; j < 4; j++ ){
			cin >> mat[i][j];
			if(mat[i][j] == 2048) ok = false;
		}
		string ans[] = {"","","",""};
		for( int i = 0; i < 4 && ok; i++ ){
			if( check(mat[3][i],mat[2][i],mat[1][i],mat[0][i],0) ) ans[0] = "DOWN";
			if( check(mat[3][i],mat[2][i],mat[1][i],mat[0][i],1) ) ans[3] = "UP";
			if( check(mat[i][0],mat[i][1],mat[i][2],mat[i][3],0) ) ans[1] = "LEFT";
			if( check(mat[i][0],mat[i][1],mat[i][2],mat[i][3],1) ) ans[2] = "RIGHT";
		}
		string resp = ans[0];
		for( int i = 1; i < 4; i++ ){
			if( resp.size() && ans[i].size() ) resp += " ";
			resp += ans[i];
		}
		if( !resp.size() ) cout << "NONE";
		else cout << resp;
		cout << '\n';
	}	
	return 0;
}
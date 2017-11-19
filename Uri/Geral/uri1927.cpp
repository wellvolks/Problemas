#include <bits/stdc++.h>

using namespace std;

int n;
int x[] = {-1,0,1,0};
int y[] = {0,1,0,-1};
int dp[22][22][2002];
int used[22][22][2002], vis = 1;
int opaTrufas[22][22][2002];
int ultTrufa;

int solve( int atx, int aty, int tmp ){
	if( tmp > ultTrufa ) return 0;
	int &ans = dp[atx][aty][tmp];
	int &us = used[atx][aty][tmp];
	if( us == vis ) return ans;
	ans = 0;
	us = vis;
	for( int i = 0; i < 4; i++ ){
		int xx = atx + x[i];
		int yy = aty + y[i];
		if( xx >= 0 && xx < 22 && yy >= 0 && yy < 22 ){
			ans = max(ans, solve(xx,yy,tmp+1) + opaTrufas[xx][yy][tmp+1]);
		}
	}
	ans = max(ans, solve(atx,aty,tmp+1) + opaTrufas[atx][aty][tmp+1]);
	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	int a, b, t;
	cin >> n;
	ultTrufa = 0;
	for( int i = 0; i < n; i++ ){
		cin >> a >> b >> t;
		opaTrufas[a][b][t]++;
		ultTrufa = max(ultTrufa, t);
	}
	cout << (solve(6, 6, 0) + opaTrufas[6][6][0]) << '\n';
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef unsigned long long uint64;

char mapa[200][200];
int used[200][200];

struct tri{
	int x, y, d;
	tri(int x = 0, int y = 0, int d = 0) : x(x), y(y), d(d) { }
};

int x[] = {-1,0,1,0};
int y[] = {0,1,0,-1};
int dir[500];
int n, m;

char solve(){
	queue < tri > fila;
	fila.push(tri(0,0,dir[mapa[0][0]]));
	if( mapa[0][0] == '.' ) return '!';
	while( !fila.empty() ){
		tri at = fila.front();
		fila.pop();
		if( used[at.x][at.y] ) continue;
		used[at.x][at.y] = 1;
		if( mapa[at.x][at.y] == '*' ) return '*';
		if( mapa[at.x][at.y] != '.' ){
			at.d = dir[mapa[at.x][at.y]];
		}
		at.x += x[at.d];
		at.y += y[at.d];
		if( at.x >= 0 && at.x < n && at.y >= 0 && at.y < m )
			fila.push(at);
	}
	return '!';
}

int main(){
	ios::sync_with_stdio(false);
	dir['^'] = 0;
	dir['>'] = 1;
	dir['v'] = 2;
	dir['<'] = 3;

	cin >> m >> n;
	bool ok = false;
	for( int i = 0; i < n; i++ ){
		cin >> mapa[i];
		for( int j = 0; j < m; j++ ){
			if( mapa[i][j] == '*' ) ok = true;
		}
	}

	if( !ok ) cout << "!\n";
	else cout << solve() << '\n';

	return 0;
}
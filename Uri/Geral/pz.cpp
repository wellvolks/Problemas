#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef unsigned long long uint64;

struct tri{
	int x, y, b, d;
	tri( int x = 0, int y = 0, int d = 0, int b = 0 ) : x(x), y(y), d(d), b(b) { }
};

int used[110][110][1<<8], vis = 1;
int x[] = {-1,0,1,0};
int y[] = {0,1,0,-1};
int n, m;

vector < string > vet;

int solve( int a, int b ){
	queue < tri > fila;
	fila.push(tri(a,b,0,0));
	used[0][0][0] = vis;
	while( !fila.empty() ){
		tri at = fila.front();
		fila.pop();
		if( vet[at.x][at.y] == '*' ) return at.b;
		for( int i = 0; i < 4; i++ ){
			int xx = at.x + x[i];
			int yy = at.y + y[i];
			if( xx >= 0 && xx < n && yy >= 0 && yy < m && vet[xx][yy] != '#' && used[xx][yy][at.d] != vis ){
				if( vet[xx][yy] >= 'A' && vet[xx][yy] <= 'G' ){
					if( at.d & (1 << (vet[xx][yy]-'A')) ){
						used[xx][yy][at.d] = vis;
						fila.push(tri(xx,yy,at.d,at.b+1));
					}
				}
				else if( vet[xx][yy] >= 'a' && vet[xx][yy] <= 'g' ){
					used[xx][yy][at.d|(1<< (vet[xx][yy]-'a'))] = vis;
					fila.push(tri(xx,yy,at.d|(1<< (vet[xx][yy]-'a')), at.b+1));
				}
				else{
					if( vet[xx][yy] == '*' ) return at.b+1;
					used[xx][yy][at.d] = vis;
					fila.push(tri(xx,yy,at.d,at.b+1));
				}
			}
		}
	}
	return -1;
}

int main(){
	ios::sync_with_stdio(false);
	string str;
	while( cin >> str ){
		vet.push_back(str);
	}
	n = vet.size();
	m = vet[0].size();
	int ans = -1;
	for( int i = 0; i < n; i++ ){
		for( int j = 0; j < m; j++ ){
			if( vet[i][j] == '@' ){
				ans = solve(i,j);
				if( ans == -1 ) cout << "--\n";
				else cout << ans << '\n';
			}
		}
	}
	return 0;
}
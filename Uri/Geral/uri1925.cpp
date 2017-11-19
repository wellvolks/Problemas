#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

int pai[1004004], rk[1004004], qtSub[1004004];
int x[] = {-1,0,1,0};
int y[] = {0,1,0,-1};
int id[1002][1002];
char mat[1002][1002];

void init( int n ){
	for( int i = 0; i <= n; i++ ){
		pai[i] = i;
		rk[i] = 0;
		qtSub[i] = 1;
	}
}

int find( int u ){
	int a = u;
	while( pai[a] != a ) a = pai[a];
	int b = u;
	while( pai[b] != b ){
		int c = pai[b];
		pai[b] = a;
		b = c;
	}
	return a;
}

void merge(int u, int v){
	int ax = find(u);
	int ay = find(v);

	if( ax == ay ) return;
	if( rk[ay] > rk[ax] ) swap(ax,ay);
	if( rk[ay] == rk[ax] ) rk[ax]++;

	pai[ay] = ax;
	qtSub[ax] += qtSub[ay];
}


int main(){
	ios::sync_with_stdio(false);
	int l, c, w = 0;
	cin >> l >> c;

	vector < pair < int, int > > resp;
	for( int i = 0; i < l; i++ ){
		for( int j = 0; j < c; j++ ){
			cin >> mat[i][j];
			id[i][j] = w++;
			if( mat[i][j] == '*' ) resp.push_back(make_pair(i,j));
		}
	}

	init(w+10);
	for( int i = 0; i < l; i++ ){
		for( int j = 0; j < c; j++ ){
			if( mat[i][j] != 'n' ) continue;
			for( int k = 0; k < 4; k++ ){
				int xx = i + x[k];
				int yy = j + y[k];
				if( xx >= 0 && xx < l && yy >= 0 && yy < c && mat[xx][yy] == 'n' ){
					merge(id[xx][yy], id[i][j]);
				}
			}
		}
	}

	int ansx = 1e9, ansy = 1e9, ans = -1;
	for( int i = 0; i < l; i++ ){
		for( int j = 0; j < c; j++ ){
			if( mat[i][j] != '*' ) continue;
			map < int, int > mapa;
			for( int k = 0; k < 4; k++ ){
				int xx = i + x[k];
				int yy = j + y[k];
				if( xx >= 0 && xx < l && yy >= 0 && yy < c && mat[xx][yy] == 'n' ){
					int p = find(id[xx][yy]);
					mapa[p]++;
				}
			}
			map < int, int > :: iterator it = mapa.begin();
			int tot = 0;
			while( it != mapa.end() ){
				tot += qtSub[it->first];
				it++;
			}			
			if( tot > ans ){
				ans = tot;
				ansx = i;
				ansy = j;
			}
			else if( tot == ans ){
				if( i < ansx ){ ansx = i; ansy = j; }
				else if( i == ansx && j < ansy ){ ansx = i; ansy = j; }
			}
		}
	}
	if( ansx < 1e9 ) cout << ansx+1 << "," << ansy+1 << '\n';
	else{
		sort(resp.begin(), resp.end());
		cout << resp[0].first+1 << "," << resp[0].second+1 << '\n';
	}
	return 0;

}
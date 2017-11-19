#include <bits/stdc++.h>

using namespace std;
 
#ifdef _WIN32 
    #define getchar_unlocked getchar
#endif

inline bool read( int &n ) {
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

int pai[110], rk[110];
char mat[110][1100];

void init( int n ){
	for( int i = 0; i <= n; i++ ){
		pai[i] = i;
		rk[i] = 0;
	}
}

int find( int u ){
	int a = pai[u];
	while( a != pai[a] ) a = pai[a];
	int b = u;
	while( b != a ){
		int c = pai[b];
		pai[b] = a;
		b = c;
	}
	return a;
}

bool uniao(int u, int v){
	int a = find(u);
	int b = find(v);
	if( a == b ) return false;

	if(rk[b] > rk[a]) swap(a,b);
	if(rk[a] == rk[b]) rk[a]++;

	pai[b] = a;
	return true;
}

int main(){
	ios::sync_with_stdio(false);
	int n, m, k = 1;

	while( read(n) && read(m) && n ){
		vector < pair < int, pair < int, int > > > grafo;

		for( int i = 0; i < n; i++ ){
			for( int j = 0; j < m; j++ ){
				char c = getchar_unlocked();
				while( !isalpha(c) ) c = getchar_unlocked();
				mat[i][j] = c;
			}
		}

		for( int i = 0; i < n; i++ ){
			for( int j = 0; j < n; j++ ){
				if( i == j ) continue;
				int custo = 0;
				for( int w = 0; w < m; w++ ){
					custo += (mat[i][w] != mat[j][w]);
				}
				grafo.push_back(make_pair(custo, make_pair(i,j)));
			}
		}

		sort(grafo.begin(), grafo.end());
		init(n);

		int ans = 0;
		for( int i = 0, sz = grafo.size(); i < sz; i++ ){
			int u = grafo[i].second.first;
			int v = grafo[i].second.second;
			if( uniao(u,v) ){
				ans += grafo[i].first;
			}
		}

		cout << "Instancia " << k++ << "\n" << ans << "\n\n";

	}

	return 0;
}
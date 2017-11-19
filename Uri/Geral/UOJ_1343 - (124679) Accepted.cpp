#include <tr1/unordered_map>
#include <set>
#include <list>
#include <stack>
#include <cmath>
#include <queue>
#include <ctime>
#include <cfloat>
#include <vector>
#include <string>
#include <cstdio>
#include <bitset>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <iomanip>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>

using namespace std;
using namespace tr1;

#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define RFOR(i, b, a) for(int i = b; i >= a; --i)
#define REP(i, N) for(int i = 0; i < N; ++i)
#define RREP(i, N) for(int i = N-1; i >= 0; --i)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )
#define MAXN 10000
#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFFLL
#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) __typeof((X).begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) int((V).size())
#define pb push_back
#define mp make_pair

struct pt{
	int x, y, r;
	pt(int x = 0, int y = 0, int r = 0) : x(x), y(y), r(r) { }
};

bool ordenaX(const pt &a, const pt &b){
	if( a.x != b.x ) return a.x < b.x;
	return a.y < b.y;
}

bool ordenaY(const pt &a, const pt &b){
	if( a.y != b.y ) return a.y < b.y;
	return a.x < b.x;
}

int n, m;

typedef long long int64;
typedef unsigned long long uint64;


using namespace std;

struct estado{
	bool mat[8][8];
	int linha, coluna;

	estado(){
		memset(mat,0,sizeof mat);
	}

	estado *operator = (const estado &q){

		for(int i = 0; i < 8; ++i)
			for(int j = 0; j < 8; ++j)
				mat[i][j] = q.mat[i][j];
		linha = q.linha;
		coluna = q.coluna;
	}

	bool operator < (const estado &q) const{
		for(int i = 0; i < 8; ++i)
			for(int j = 0; j < 8; ++j){
				if(mat[i][j] != q.mat[i][j])
					return (mat[i][j] == 0);
			}
			return ((linha == q.linha && coluna < q.coluna)||(linha < q.linha));
	}

	bool operator == (const estado &q) const{
		for(int i = 0; i < 8; ++i)
			for(int j = 0; j < 8; ++j)
				if(mat[i][j] != q.mat[i][j])
					return false;

		return (linha == q.linha && coluna == q.coluna);
	}

};


int main(){
	int t = 0, p, pos, l, c, b;
	bool vencedor = false, ch = false;
	scanf("%d",&t);
	while( t != 0 ){
		estado inicio;
		for(int k = 0; k < t; k++){
			scanf("%d",&p);
			p--;
			l = p/8;
			c = p%8;
			inicio.mat[l][c] = true;
		}
		scanf("%d",&pos);
		pos--;
		inicio.linha = pos/8;
		inicio.coluna = pos%8;
		set<estado> visitado;
		queue < pair<int,estado> > fila;
		fila.push(make_pair(0,inicio));
		vencedor = false;
		while(fila.size()){
			estado s = fila.front().second;
			b = fila.front().first;
			fila.pop();
			for(int i = 0; i < 8; ++i){
				for(int j = 0; j < 8; ++j){
					if(s.mat[i][j]){
						ch = true;
						break;
					}
				}
				if(ch == true)
				   break;
			}
			if(ch == false){
				cout << b << endl;
				vencedor = true;
				break;
			}
			ch = false;
			if(visitado.count(s)) continue;
			visitado.insert(s);
			for(int j = 0; j < 8; ++j){
				estado k = s;
				switch (j){
							case (0):
								k.linha += -1;
								k.coluna += -2;
								break;
							case (1):
								k.linha += -1;
								k.coluna += +2;
								break;
							case (2):
								k.linha += +1;
								k.coluna += -2;
								break;
							case (3):
								k.linha += +1;
								k.coluna += +2;
								break;
							case (4):
								k.linha += -2;
								k.coluna += -1;
								break;
							case (5):
								k.linha += -2;
								k.coluna += +1;
								break;
							case (6):
								k.linha += +2;
								k.coluna += +1;
								break;
							case (7):
								k.linha += +2;
								k.coluna += -1;
								break;
				}
                ch = false;
				if(0 <= k.linha && k.linha < 8 && 0 <= k.coluna && k.coluna < 8){
					k.mat[k.linha][k.coluna] = false;
					
                for(int i = 0; i < 8; ++i){
					if(k.mat[7][i]){
	                   ch = true;
				 	   break;
					}
				}
				if(!ch){
					for(int i = 7; i > 0; --i)
		               for(int f = 0; f < 8; ++f)
                           if(!k.mat[i][f] && k.mat[i-1][f]){
			                    swap(k.mat[i-1][f], k.mat[i][f]);
							  }
				              if(visitado.count(k) == 0){
					             fila.push(make_pair(b + 1, k));
					      }	
					}
				}
			}
		}
		if(vencedor == false) cout << "impossible" <<endl;
		scanf("%d",&t);
	}
	return 0;
}

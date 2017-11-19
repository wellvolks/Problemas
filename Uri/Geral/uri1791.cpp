#include <bits/stdc++.h>
#define MAXN 100005

using namespace std;

typedef long long int64;
typedef unsigned long long uint64;

set < vector < vector < double > > > used;
vector < vector < int > > mat;
double aux[10][10];

int n;

bool check(bool &flag){
	for( int i = 0; i < n; i++ ) if( !(fabs(mat[i][0]-1.) < 1e-50) ) return false;
	flag = true;
	for( int i = 2; i < n; i++ ){
		for( int j = 0; j < n; j++ ){
			if( mat[j][i] <= mat[j][1] ) return false;
			if( !(fabs(powl(mat[j][1],i) - mat[j][i]) < 1e-50) ) return false;
		}
	}
	return true;
}

bool solve( ){
	vector < int > vet;
	int base = 0;
	for(int i = 0; i < n; i++ ){
		for( int j = 0; j < n; j++ ){
			vet.push_back(mat[i][j]);
			if( mat[i][j] == )
		}
	}
	sort(vet.begin(), vet.end());

}

int main(){
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	int val;
	while( t-- ){
		cin >> n;
		mat.clear();
		mat.resize(n);
		for( int i = 0; i < n; i++ ){
			for( int j = 0; j < n; j++ ){
				cin >> val;
				mat[i].push_back(val);
			}
		}
		cout << (solve() ? ("Potencia\n") : ("Nao Potencia\n"));
		used.clear();
	}
	return 0;
}
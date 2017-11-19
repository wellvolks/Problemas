#include <bits/stdc++.h>
#define MAXSZ 9000005

using namespace std;

int lo, mid, hi;

vector < vector < int > > grafoIda;
vector < vector < int > > grafoVolta;
int final[1000000];
int inicial[1000000];
int used[10000000], vis = 1;
bool ciclo = false;

bool dfsIda(int at){
	if( final[at] ) return true;
	if( used[at] == vis ){
		ciclo = true;
		return true;
	}
	used[at] = vis;
	for( int i = 0, sz = grafoIda[at].size(); i < sz; i++ ){
		if( dfsIda(grafoIda[at][i]) ) return true;
	}
	return false;
}

bool dfsVolta(int at){
	if( final[at] ) return true;
	if( used[at] == vis ){
		ciclo = true;
		return true;
	}
	used[at] = vis;
	for( int i = 0, sz = grafoVolta[at].size(); i < sz; i++ ){
		if( dfsVolta(grafoVolta[at][i]) ) return true;
	}
	return false;
}

int main(){
	ios::sync_with_stdio(false);
	cin >> lo >> mid >> hi;
	int k, val;
	grafoIda.resize(lo+mid+hi+10);
	grafoVolta.resize(lo+mid+hi+10);
	for( int i = 1; i <= mid; i++ ){
		cin >> k;
		for( int j = 1; j <= k; j++ ){
			cin >> val;
			grafoIda[val].push_back(i+lo);
			grafoVolta[i+lo].push_back(val);
		}
	}
	for( int i = 1; i <= hi; i++ ){
		cin >> val;
		grafoIda[val].push_back(lo+mid+i);
		grafoVolta[lo+mid+i].push_back(val);
	}
	for( int i = 1; i <= lo; i++ ) inicial[i] = 1;
	for( int j = 1; j <= hi; j++ ) final[lo+mid+j] = 1;

	for(int i = 1; i <= lo; i++ ){
		ciclo = false;
		if( !dfsIda(i) || ciclo ){
			cout << "u.u\n";
			return 0;
		}
		vis++;
	}
	for( int i = 1; i <= hi; i++ ){
		ciclo = false;
		if( !dfsVolta(lo+mid+i) || ciclo ){
			cout << "u.u\n";
			return 0;
		}
		vis++;
	}
	for( int i = 1; i <= mid; i++ ){
		ciclo = false;
		if( !dfsIda(i+lo) || ciclo ){
			cout << "u.u\n";
			return 0;
		}
		vis++;
	}
	cout << "o.o\n";
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef unsigned long long uint64;

char str[100000];
map < string, int > mapa;
map < string, int > :: iterator it;
string aux = "";
int used[400], vis = 1;
string ans[400];

int main(){
	ios::sync_with_stdio(false);
	while( gets(str) != NULL && str[0] != '.' ){
		aux = "";
		aux += str;
		aux += ":)";
		int us = 0;
		char *p = strtok(str, " ");
		while( p != NULL ){
			if( strlen(p) > 2 ) mapa[p]++;
			p = strtok(NULL, " ");
		}
		it = mapa.begin();
		vector < pair < int, string > > vet;
		map < string, int > abr;
		while( it != mapa.end() ){
			vet.push_back(make_pair(-((it->second)*((int)it->first.size()-2)),it->first));
			it++;
		}
		sort(vet.begin(),vet.end());
		for( int i = 0; i < vet.size(); i++ ){
			if( used[vet[i].second[0]] == vis ) continue;
			used[vet[i].second[0]] = vis;
			ans[vet[i].second[0]] = vet[i].second;
			abr[vet[i].second]++;
			us++;
		}
		string opa = "", resp = "";
		for( int i = 0; aux[i] != ')'; i++ ){
			if( !isalpha(aux[i]) ){
				if( abr.count(opa) ){ resp += opa[0]; resp += "."; }
				else resp += opa;
				if( aux[i] != ':' ) resp += aux[i];
				opa = "";
			}
			else opa += aux[i];
		}
		cout << resp << "\n";
		cout << us << "\n";
		for( char i = 'a'; i <= 'z'; i++ ) if( used[i] == vis ) cout << i << ". = " << ans[i] << "\n";
		mapa.clear();
		vis++;

	}
    return 0;
}
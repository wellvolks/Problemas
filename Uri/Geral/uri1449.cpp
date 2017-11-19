#include <iostream>
#include <vector>
#include <tr1/unordered_map>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <sys/timeb.h>
#define For(i, n) for(int i = 0; i < n; i++)
#define FOR(i, r, n) for(int i = r; i < n; i++)
#define MAXV 10010
#define mp make_pair
#define pb push_back
using namespace std;
using namespace tr1;

unordered_map< string, string > mapa;

void converte(string str){
	string aux = "", resp = "";
	For(i, (int)str.size()){
		if(str[i] >= 'a' && str[i] <= 'z') aux += str[i];
		else{
			if(mapa.count(aux)) resp += mapa[aux];
			else resp += aux;
			resp += " ";
			aux = "";
		}
	}
	if(mapa.count(aux)){ resp += mapa[aux]; resp += " "; }
	else{ resp += aux; resp += " "; }
	resp.erase(resp.size()-1);
	cout << resp << "\n";
}
int main(){
	int n, m, qt;
	ios::sync_with_stdio(false);
	cin >> n;
	string pala, frase;
	while(n--){
		cin >> m >> qt;
		cin.ignore();
		For(i, m){
			getline(cin,pala);
			getline(cin,frase);
			mapa[pala] = frase;
		}
		For(i, qt){
			getline(cin,frase);
			converte(frase);
		}
		cout << "\n";
		mapa.clear();
	}
	return 0;
}


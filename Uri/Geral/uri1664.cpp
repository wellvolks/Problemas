#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <map>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	string str, aux = "";
	int lo = 0, hi = 0;
	map < string, int > mapa;
	while( getline(cin,str) ){
		str += " ";
		for( int i = 0; i < str.size(); i++ ){
			if( !isalpha(str[i]) ){
				if( aux == "BULLSHIT" ){ hi++; lo += mapa.size(); mapa.clear(); }
				else if( aux.size() ) mapa[aux]++;
				aux = "";
			}
			else aux += toupper(str[i]);
		}
	}
	int gcd = __gcd(lo,hi);
	cout << (lo/gcd) << " / " << (hi/gcd) << "\n";

	return 0;
}
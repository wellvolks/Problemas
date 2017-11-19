#include <bits/stdc++.h>
#define MAXN 100005

using namespace std;

typedef long long int64;
typedef unsigned long long uint64;

string str;

int main(){
	ios::sync_with_stdio(false);
	int tam = 0;
	while( cin >> str ){
		if( str == "<br>" ){
			cout << '\n';
			tam = 0;
		}
		else if( str == "<hr>" ){
			if( tam ) cout << "\n";
			cout << "--------------------------------------------------------------------------------\n";
			tam = 0;
		}
		else if( tam + (tam!=0) + str.size() > 80 ){
			cout << '\n';
			tam = str.size();
			cout << str;
		}
		else if( tam + (tam != 0) + str.size() == 80 ){
			if( tam ) cout << " ";
			cout << str << "\n";
			tam = 0;
		}
		else{
			if( tam ){ tam++; cout << " "; }
			cout << str;
			tam += str.size();
		}
	}
	cout << '\n';
	return 0;
}
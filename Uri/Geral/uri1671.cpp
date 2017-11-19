#include <bits/stdc++.h>

using namespace std;

int n, k;
vector < vector < string > > mapa;
int used[10][10];
string str;


bool bk(int tam){
	if( !tam ){ cout << str << endl; return true; }
	for(char i = '0'; i <= '9'; i++ ){
		if( !used[str.back()][i] ){
			used[str.back()][i] = 1;
			str += i;
			if( bk(tam-1) ){
				str.pop_back();
				used[str.back()][i] = 0;
				return true;
			}
			str.pop_back();
			used[str.back()][i] = 0;
		}
	}
	return false;
}



int main(){
	ios::sync_with_stdio(false);
	mapa.resize(7);
	for( int i = 1; i <= 6; i++ ){
		k = i;
		str = "";
		bk(pow(10,i)+i-1);
	}
	return 0;
}
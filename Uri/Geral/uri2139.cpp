#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int mes[] = {31, 29, 31,30,31,30,31,31,30,31,30,31};
	int a, b, n = 0;
	for(int i = 0; i <= 10; i++) n += mes[i];
	n += 25;
	while( cin >> a >> b ){
		int tot = 0;
		for(int i = 0; i < a-1; i++){
			tot += mes[i];
		}
		tot += b;
		if( tot == n ) cout << "E natal!\n";
		else if( tot+1 == n ) cout << "E vespera de natal!\n";
		else if( tot > n ) cout << "Ja passou!\n";
		else cout << "Faltam " << n-tot << " dias para o natal!\n";
	}
	return 0;
}
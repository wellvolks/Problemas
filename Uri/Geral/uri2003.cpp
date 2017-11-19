#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	int a, b;
	char c;
	while(scanf("%d%c%d",&a,&c,&b) != EOF){

		cout << "Atraso maximo: " << max(0, (a*60 + b + 60)-(8*60)) << "\n";
	}
	return 0;
}
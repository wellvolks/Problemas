#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	double a, b;
	int k = 1;
	while( cin >> a >> b ){
		cout << "Projeto " << k++ << ":\n";
		cout << "Percentual dos juros da aplicacao: " << fixed << setprecision(2) << ((b-a)/a)*100. << " %\n\n";
	}
	return 0;
}
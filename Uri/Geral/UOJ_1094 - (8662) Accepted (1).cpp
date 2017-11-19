#include <iostream>
#include <cstdio>
#include <string>
#include <iomanip>
#include <math.h>
#include <cstdlib>
#define PI 3.14159
using namespace std;
int main(){
	int n;
	ios::sync_with_stdio(false);
	double cobaias[400], qt, total = 0;
	cobaias['C'] = cobaias['R'] = cobaias['S'] = 0;
	cin >> n;
	char c;
	while(n--){
		cin >>  qt >> c;
		total += qt;
		cobaias[c] += qt;
	}
	cout << "Total: " << total << " cobaias\n";
	cout << "Total de coelhos: " << cobaias['C'] << "\n";
	cout << "Total de ratos: " << cobaias['R'] << "\n";
	cout << "Total de sapos: " << cobaias['S'] << "\n";
	cout << "Percentual de coelhos: " << fixed << setprecision(2) << (cobaias['C']/total)*100 << " %\n";
	cout << "Percentual de ratos: " << fixed << setprecision(2) << (cobaias['R']/total)*100 << " %\n";
	cout << "Percentual de sapos: " << fixed << setprecision(2) << (cobaias['S']/total)*100 << " %\n";

}
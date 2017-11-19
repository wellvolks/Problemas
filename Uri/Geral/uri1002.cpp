#include <iostream>
#include <cstdio>
#include <utility>
#include <iomanip>
using namespace std;

double PI  = 3.14159; 
int main(){
    double raio, a;
    cout << fixed << setprecision(4);
    cin >> raio;
    cout << "A=" << (raio*raio*PI) << '\n';
    return 0;
}
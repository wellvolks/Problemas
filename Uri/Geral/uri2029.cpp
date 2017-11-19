#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    double v, d;

    while( cin >> v ){
        cin >> d;
        cout << fixed << setprecision(2);
        cout << "ALTURA = " << v/(3.14*(d/2.)*(d/2.)) << '\n';
        cout << "AREA = " << (d/2.)*(d/2.)*3.14 << "\n";
    }


    return 0;
}
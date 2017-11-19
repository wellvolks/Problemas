#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    double a, b;
    cin >> a >> b;

    cout << fixed << setprecision(2) << (((b-a)*100.)/a) << "%\n";
    return 0;
}
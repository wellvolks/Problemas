#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int v;
    int ans = 0;
    for(int i = 0; i < 4; i++){ cin >> v; ans += v; }

    cout << ans-3 << '\n';

    return 0;
}
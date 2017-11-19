#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios::sync_with_stdio(false);
    long long m, n;
    while( cin >> m >> n && ( n + m ) ){
        long long ans = m + n;
        string resp = "";
        while( ans ){
            long long r = (ans % 10LL);
            if( r ) resp += char(r + '0'); 
            ans /= 10LL;
        }
        reverse(resp.begin(), resp.end());
        cout << resp << '\n';
    }
    return 0;
}
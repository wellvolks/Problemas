#include <bits/stdc++.h>
#include <tr1/unordered_map>

using namespace std;
using namespace tr1;

typedef long long int64;
typedef unsigned long long uint64;

#ifdef _WIN32 
    #define getchar_unlocked getchar
#endif
 

bool read( int &n ) {
    n = 0;
    register bool neg = false;
    register char c = getchar_unlocked();
    if( c == EOF) { n = -1; return false; }
    while (!('0' <= c && c <= '9')){
        if( c == '-' ) neg = true;
        c = getchar_unlocked();
    }
    while ('0' <= c && c <= '9') {
        n = n * 10 + c - '0';
        c = getchar_unlocked();
    }
    n = (neg ? (-n) : (n));
    return true;
}

int n, l, m, p;
int venda[2002], manu[2002];
int dp1[2002][2002];
int used1[2002][2002], vis1 = 1;
int dp2[2002][2002];
int used2[2002][2002], vis2 = 1;
vector < int > resp;

int solve( int ano, int usado ){
    if( ano >= n ) return 0;
    int &ans = dp1[ano][usado];
    int &us = used1[ano][usado];
    if( us == vis1 ) return ans;
    ans = 0;
    us = vis1;
    ans = solve(ano+1,1) + (p - venda[usado]) + manu[0];
    //cout << ano << " " << usado << ":" << endl;
    //cout << ans << endl;
    if( usado < m ){
        int a = solve(ano+1, usado+1) + manu[usado];
        //cout << ano << " " << usado << ":" << endl;
        //cout << a << endl;
        ans = min(ans, a);
    }
    //cout << "\n";
    return ans;
} 

void getSolve( int ano, int usado ){ 
    while( ano < n ){
        if( solve(ano,usado) == (solve(ano+1,1) + (p - venda[usado]) + manu[0]) ){
            resp.push_back(ano);
            ano++;
            usado = 1;
        }
        else{
            ano++;
            usado++;
        }
    }
} 

int main(){
    ios::sync_with_stdio(false);
    while( read(n) ){
        read(l);
        read(m);
        read(p);
        for( int i = 0; i < m; i++ )read(manu[i]);
        for( int i = 1; i <= m; i++ ) read(venda[i]);
        int ans = solve(0,l);
        getSolve(0,l);
        cout << ans << '\n';
        if( resp.size() == 0 ) cout << "0";
        for( int i = 0; i < resp.size(); i++ ){
            if( i ) cout << " ";
            cout << resp[i]+1;
        }
        cout << '\n';
        vis1++; vis2++;
        resp.clear();
    }
    return 0;
}
#include <bits/stdc++.h>
 
using namespace std;
vector<long long> vet;
 
long long dp[10000][10000][2];
char used[10000][10000][2], vis = 1;

 
long long solve(int i, int j, int op){
        if ( i > j ) return 0;
        if (i == j) return vet[i];
        long long &ans = dp[i][j][op];
        char &us = used[i][j][op];
        if ( us == vis ) return ans;
        us = vis;
        if ( i - j == 1 ) return ans = max(vet[i], vet[j]);
 		if( op ) ans = max(solve(i+1,j,0), solve(i,j+1,0));
 		else ans = max(solve(i+1,j,1)+vet[i], solve(i,j+1,1)+vet[j]);
 		return ans;
}

int main(){
        int n;
        ios::sync_with_stdio(false);
        while ( cin >> n ){

            vet.resize(n);
            for ( int i = 0 ; i < n ; i++ ) cin >> vet[i];
	
            cout << solve(0, n-1,0) << "\n";
        	vet.clear();
        	vis++;
        }
        return 0;
}
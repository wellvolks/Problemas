#include <bits/stdc++.h>

using namespace std;
typedef long long int64;
typedef unsigned long long uint64;
 
#ifdef _WIN32 
    #define getchar_unlocked getchar
#endif

inline bool read( int &n ) {
    n = 0;
    register bool neg = false;
    register char c = getchar_unlocked();
	while( c == '\n' ) c = getchar_unlocked();
    if( c == EOF) { n = -1; return false; }
    while (!('0' <= c && c <= '9')) {
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

vector < pair < int, int > > vet;

int dp[1002][1002][3];
int used[1002][1002][3], vis = 1;
int n;

int solve(int ant, int at, int upOrDown){
    if( at >= n ) return 0;
    int &ans = dp[ant][at][upOrDown];
    int &us = used[ant][at][upOrDown];
    if( us == vis ) return ans;
    ans = 0;
    us = vis;
    if( vet[ant].first < vet[at].first ){
        if ( upOrDown == 0 && (vet[ant].second+2) == vet[at].second){
            ans = max(ans, solve(at, at+1, 1) + 1);
        }
        else if( upOrDown == 1 && (vet[ant].second-2) == vet[at].second){
            ans = max(ans, solve(at, at+1, 0) + 1);
        }
    }
    ans = max(ans, solve(ant, at+1, upOrDown));
    return ans;
}

int main(){
	ios::sync_with_stdio(false);
	while( read(n) ){
		int a, b;
        for(int i = 0; i < n; i++){
            read(a);
            read(b);    
            vet.push_back(make_pair(a,b));
        }
        sort(vet.begin(), vet.end());
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans = max(ans, max(solve(i,i+1,0)+1, solve(i, i+1, 1)+1));
        }
        printf("%d\n",ans);
        vet.clear();
        vis++;
	}
	return 0;
}
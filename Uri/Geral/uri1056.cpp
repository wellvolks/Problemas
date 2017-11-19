#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

#define MAXN 1111

int N, M;
vector< int > gr[MAXN];
bool seen[MAXN];        
int m[MAXN], m1[MAXN];

int dfs( int u ){
    if( u < 0 ) return 1;
    if( seen[u] ) return 0;
    seen[u] = true;
    for( size_t i = 0, sz = gr[u].size(); i < sz; i++ ){
        if( dfs( m1[ gr[u][i] ] ) ){
            m[u] = gr[u][i];
            m1[ gr[u][i] ] = u;
            return 1;
        }
    }
    return 0;
}

int dfsExp( int u ){
    for( int i = 0; i < N; i++ ) seen[i] = false;
    return dfs( u );
}

int bipMatch(){
    for( int i = 0; i < N; i++ ) m[i] = -1;
    for( int i = 0; i < M; i++ ) m1[i] = -1;
    int aug, ans = 0;
    do{
        aug = 0;
        bool first = true;
        for( int i = 0; i < N; i++ ) if( m[i] < 0 ){
            if( first ) aug += dfsExp( i );
            else aug += dfs( i );
            first = false;
        }
        ans += aug;
    } while( aug );
    return ans;
}

int64 vetA[1000];
int64 vetB[1000];

int main(){
    ios::sync_with_stdio(false);
    int t, k = 1;
    cin >> t;
    while( t-- ){
        cin >> N;
        for(int i = 0; i < N; i++) cin >> vetA[i];
        cin >> M;
        for(int i = 0; i < M; i++) cin >> vetB[i];
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if( !vetB[j] || (vetA[i] && !(vetB[j] % vetA[i]) ) ){
                    gr[i].push_back(j);
                    //gr[j].push_back(i);
                }
            }
        }
        cout << "Case " << k++ << ": " << bipMatch() << '\n';
        for(int i = 0; i <= N; i++) gr[i].clear();
    }
    return 0;
}
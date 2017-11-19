#include <bits/stdc++.h>
  
using namespace std;
  
typedef long long int64;
typedef unsigned long long uint64;

#ifdef _WIN32
    #define getchar_unlocked getchar
    #define putchar_unlocked putchar
#endif
   
   
bool read( int &n ) {
    n = 0LL;
    register bool neg = false;
    register char c = getchar_unlocked();
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

int grafo[1001][30], tem[1001][30], vis2 = 1;
int used[1000], vis = 1;
string str;
int tam;

void bfs( ){
    queue < pair < int, string > > fila;
    vector < string > ans;
    for( int i = 0; i < tam; i++ ){
        if( used[str[i]] == vis ) continue;
        used[str[i]] = vis;
        string aux = ""; aux += str[i];
        fila.push(make_pair(i,aux));
    }
    while( !fila.empty() ){
        pair < int, string > at = fila.front();
        fila.pop();
        bool ok = true;
        for( int i = 0; i < 26; i++ ){
            if( tem[at.first][i] == vis2 ){
                ok = false;
                fila.push(make_pair(grafo[at.first][i],at.second+char(i+'a')));
            }
        }
        ans.push_back(at.second);
    }
    sort(ans.begin(), ans.end());
    tam = ans.size();
    for( int i = 0; i < tam; i++ ) cout << ans[i] << '\n';
    cout << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    while( cin >> str ){
        tam = str.size();
        for( int i = 0; i < tam; i++ ){
            for( char j = 'a'; j <= 'z'; j++ ){
                for( int w = i+1; w < tam; w++ ){
                    if( str[w] == j ){
                        grafo[i][j-'a'] = w;
                        tem[i][j-'a'] = vis2;
                        break;
                    }
                }
            }
        }
        bfs();
        vis++;
        vis2++;
    }
    return 0;
}
#include <bits/stdc++.h>
 
using namespace std;
vector < vector < int > > grafo;
int used[100000], vis = 1;
int ciclo[100000], vis2 = 1;

bool dfs( int at ){
    if( used[at] != vis ){
        used[at] = vis;
        ciclo[at] = vis2;
        for( int i = 0; i < grafo[at].size(); i++ ){
            if( used[grafo[at][i]] != vis && dfs(grafo[at][i]) ) return true;
            else if( ciclo[grafo[at][i]] == vis2 ) return true;
        }
    }
    ciclo[at] = 0;
    return false;
}
 
int main(){
    ios::sync_with_stdio(false);
    int t, n, m, de, para;
    cin >> t;
    while( t-- ){
        cin >> n >> m;
        map < pair<int, int >, int > mapa;
        map < pair<int, int >, int > :: iterator it;
        for( int i = 0; i < m; i++ ){
            cin >> de >> para;
            mapa[make_pair(de,para)]++;
        }
        grafo.resize(n+10);
        for( it = mapa.begin(); it != mapa.end(); it++ ){
            grafo[it->first.first].push_back(it->first.second);
        }
        bool ans = true;
        for( int i =1; i <= n; i++ ){
            if( dfs( i ) ){
                ans = false;
                break;
            }
            vis2++;
            vis++;
        }
        string resp[] = {"SIM", "NAO"};
        cout << resp[ans] << "\n";
        grafo.clear();
        vis++; vis2++;
    }
    return 0;
}
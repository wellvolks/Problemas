#include <set>
#include <map>
#include <list> 
#include <stack> 
#include <cmath> 
#include <queue> 
#include <ctime> 
#include <cfloat> 
#include <vector> 
#include <string> 
#include <cstdio> 
#include <bitset> 
#include <climits> 
#include <cstring> 
#include <cassert> 
#include <iomanip> 
#include <sstream> 
#include <utility> 
#include <iostream> 
#include <algorithm> 
#include <tr1/unordered_map>
#define MOD 100000000    
        
using namespace std;
using namespace tr1;
    
struct tri{
    int at, qtd, id;
    long long custo;
    tri( int at= 0, long long custo = 0LL, int qtd = 0, int id ) : at(at), custo(custo), qtd(qtd), id(id) { };
    bool operator < ( const tri a ) const{
        if( custo != a.custo ) return custo > a.custo;
        if( qtd != a.qtd ) return qtd > a.qtd;
        return at < a.at;
    }
};
    
struct are{
    int at, cust;
    are(int at = 0, int cust = 0 ) : at(at), cust(cust) { }
};
    
vector < vector <are> > grafo;
    
int n, m, k;
long long dist[10001];
#define INF 0x3f3f3f3f
int used[1001], vis = 1;
vector < unordered_map < int, int > > mapa;

long long solve( ){
    queue < tri > fila;
    for( int i = 0; i < grafo[0].size(); i++ ) fila.push(tri(0,0,2,i));
    long long ans = INF;
    while( !fila.empty() ){
        tri at = fila.front();
        fila.pop();
        if( at.at == n-1 ){
            ans = min(ans, at.cust);
            continue;
        }
        if( mapa[at.at].count(at.id) ) continue;
        mapa[at.at][at.id] = 1;
        for( int i = 0; i < grafo[at.at].size(); i++){
            if( at.qtd+1 <= k ){
                fila.push(tri(grafo[at.at][i].at,at.custo + grafo[at.at][i].cust,at.qtd+1));
            }
        }
    }
    return ((ans < INF ) ? (ans) : (-1));
}
    
int main(){
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    int de, para, custo;
    while(t--){
        cin >> n >> m >> k;
        grafo.resize(n+1);
        for( int i = 0; i < m; i++ ){
            cin >> de >> para >> custo;
            grafo[de].push_back(are(para,custo));
        }
        cout << solve() << '\n';
        grafo.clear();
        vis++;
    }
    return 0;
}
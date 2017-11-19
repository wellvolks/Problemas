#include <bits/stdc++.h>
  
using namespace std;
  
  
#ifdef _WIN32  
    #define getchar_unlocked getchar 
    #define putchar_unlocked putchar 
#endif 
     
inline bool read( int  &n ) { 
    n = 0; 
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
  
struct tri{
    int de, para, custo, id;
    tri(int para = 0, int de = 0, int custo = 0, int id = 0 ) : para(para), de(de), custo(custo), id(id) { }
    bool operator < ( const tri &a ) const{
        if( custo != a.custo ) return custo < a.custo;
        if( para != a.para ) return para < a.para;
        return id < a.id;
    }
};
  
int n, m;
  
vector < vector < tri > > grafo;
int used[110][110], ciclo[110][110], vis = 1, vis2 = 1;
  
int solve2( int at, int ant ){
    if( used[ant][at] == vis  ) return 1e9;
    used[ant][at] = used[at][ant] = vis;
    if( at == 0 ){
        used[ant][at] = used[at][ant] = 0;
        return 0;
    }
    int tam = grafo[at].size();
    int ans = 1e9;
    for( int i = 0; i < tam; i++ ){
        if( grafo[at][i].para == ant ) continue;
        ans = min(ans, solve2(grafo[at][i].para, at) + grafo[at][i].custo);
    }
    used[ant][at] = used[at][ant] = 0;
    return ans;
}
  
int solve1( int at, int ant ){
    if( used[ant][at] == vis ) return 1e9;
    used[ant][at] = used[at][ant] = vis;
    int tam = grafo[at].size();
    int ans = 1e9;
    if( at == n-1 ){
        for( int i = 0; i < tam; i++ ){
            if( grafo[at][i].para == ant ) continue;
            ans = min(ans, solve2(grafo[at][i].para, at) + grafo[at][i].custo);
        }
    }
    else{
        for( int i = 0; i < tam; i++ ){
            if( grafo[at][i].para == ant ) continue;
            ans = min(ans, solve1(grafo[at][i].para, at) + grafo[at][i].custo);
        }
    }
    used[ant][at] = used[at][ant] = 0;
    return ans;
}
  
int main(){
    ios::sync_with_stdio(false);
    int de, para, custo, m;
    while( cin >> n && n ){
        cin >> m;
        grafo.resize(n+10);
        for( int i = 0; i < m; i++ ){
            cin >> de >> para >> custo;
            grafo[de-1].push_back(tri(para-1, de-1, custo));
            grafo[para-1].push_back(tri(de-1, para-1, custo));
        }
        int ans = solve1(0, 0);
        if( ans < 1e9 ) cout << ans << "\n";
        else cout << "Pernoite.\n";
        vis++;
        grafo.clear();
    }
    return 0;
}
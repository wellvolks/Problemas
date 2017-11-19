#include <bits/stdc++.h>
#define INF 0x3f3f3f3ffff
using namespace std;
typedef unsigned long long uint64;
typedef long long int64;
 
 #ifdef _WIN32  
    #define getchar_unlocked getchar 
    #define putchar_unlocked putchar 
#endif 
   
inline void read( int &n ) { 
    n = 0; 
    register bool neg = false; 
    register char c = getchar_unlocked(); 
    if( c == EOF) { n = -1; return; } 
    while (!('0' <= c && c <= '9')) { 
        if( c == '-' ) neg = true; 
        c = getchar_unlocked(); 
    } 
    while ('0' <= c && c <= '9') { 
        n = n * 10 + c - '0'; 
        c = getchar_unlocked(); 
    } 
    n = (neg ? (-n) : (n)); 
} 
   
inline void writeInt(int n){ 
    register int idx = 20; 
    if( n < 0 ) putchar_unlocked('-'); 
    n = abs(n); 
    char out[21]; 
    out[20] = ' '; 
    do{ 
        idx--; 
        out[idx] = n % 10 + '0'; 
        n/= 10; 
    }while(n); 
    do{ putchar_unlocked(out[idx++]); } while (out[idx] != ' '); 
} 
struct torre{
    int v, a, c;
    torre(int v = -1, int a = 0, int c = 0 ) : v(v), a(a), c(c) { }
};
 
vector < torre > torres;
vector < vector < int > > grafo;
int used[10000], vis = 1;
int64 dist[10000];
int64 acm[10000];
int n, m, f, p, q;
 
void bfs(int id){
    vis++;
    queue < pair < int, int > > fila;
    fila.push(make_pair(torres[id].v,0));
    used[torres[id].v] = vis;
    while( !fila.empty() ){
        pair < int, int > at = fila.front();
        fila.pop();
        if(at.first == f) continue;
        acm[at.first] += torres[id].a;
        for(int i = 0, sz = grafo[at.first].size(); i < sz; i++){
            int u = grafo[at.first][i];
            if( at.second+1 <= torres[id].c && used[u] != vis ){
                used[u] = vis;
                fila.push(make_pair(u, at.second+1));
            }
        }
    }
}
 
void dijsktra(){
    priority_queue < pair < int64, int > > fila;
    dist[f] = 0;
    vis++;
    fila.push(make_pair(0,f));
    while( !fila.empty() ){
        pair < int64, int > at = fila.top();
        fila.pop();
        int64 cust = -at.first;
        int u = at.second;
        if( used[u] == vis ) continue;
        used[u] = vis;
        for(int i = 0, sz = grafo[u].size(); i < sz; i++){
            int v = grafo[u][i];
            if( dist[v] > (cust + acm[v]) ){
                dist[v] = cust + acm[v];
                fila.push(make_pair(-dist[v],v));
            }
        }
    }
}
 
int main(){
    ios::sync_with_stdio(false);
    int t, u, v, k, h, w = 1;
    torre to;
    read(t);
    while( t-- ){
        read(n); read(m); read(f);
        f--;
        grafo.resize(n+10);
        for(int i = 0; i <= n; i++){
        	dist[i] = INF;
        	acm[i] = 0;
        }
        for( int i = 0; i < m; i++ ){
            read(u); read(v); u--; v--;
            grafo[u].push_back(v);
            grafo[v].push_back(u);
        }
         
        read(p);
        for( int i = 0; i < p; i++ ){
            read(to.v); read(to.a); read(to.c);
            to.v--;
            torres.push_back(to);
        }
 
        for( int i = 0; i < p; i++ ) bfs(i);
 
        dijsktra();
         
        int ans = 0;
 		
 		read(q);
        for( int i = 0; i < q; i++ ){
            read(k); read(h);
            if( dist[k-1] < h || k-1 == f) ans++;
        }

        putchar_unlocked('C');
        putchar_unlocked('a');
        putchar_unlocked('s');
        putchar_unlocked('o');
        putchar_unlocked(' ');
        putchar_unlocked('#');
        writeInt(w++);
        putchar_unlocked(':');
        putchar_unlocked(' ');
        writeInt(ans);
        putchar_unlocked('\n');
        
        grafo.clear();
        torres.clear();
    }
    return 0;
}
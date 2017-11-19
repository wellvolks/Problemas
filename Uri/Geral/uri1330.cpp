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
   
inline void writeInt(long long n){ 
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

#define MAXN 20001

int N, M;   // N - # of vertexes on X,  M - # of vertexes on Y
vector < vector < int > > gr;  // gr[u] -- edges from u in X to v in Y
bool seen[MAXN];        
int m[MAXN], m1[MAXN];   // with whom it's matched

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

int mat[110][110], id[110][110], vis = 1;
int x[] = {-1,1,0,0};
int y[] = {0,0,-1,1};
vector < pair < int, int > > grafo;

int main(){
    ios::sync_with_stdio(false);
    int n, m, lo, hi;
    while( read(n) && read(m) && (n+m) ){
        int k;
        read(k);
        for( int i = 0; i < k; i++ ){
            read(lo); read(hi); lo--; hi--;
            mat[lo][hi] = vis;
        }
        k = 0;
        for( int i = 0; i < n; i++ ) for( int j = 0; k < m; j++ ) id[i][j] = k++;
        map < pair < int, int > , int > mapa;
        map < pair < int, int > , int > :: iterator it;
        k = 0;
        int ans = 0;
        for( int i = 0; i < n; i++ ){
            for( int j = 0; j < m; j++ ){
                if( mat[i][j] == vis ) continue;
                for( int w = 0; w < 4; w++ ){
                    int xx = i + x[w];
                    int yy = j + y[w];
                    if( xx >= 0 && xx < n && yy >= 0 && yy < m && mat[xx][yy] != vis ){
                        pair < int, int > at = make_pair(id[i][j],id[xx][yy]);
                        if( !mapa.count(at) ) mapa[at] = k++; 
                    }
                }
            }
        }
        N = k;
        gr.resize(k);
        for( int i = 0; i < n; i++ ){
            for( int j = 0; j < m; j++ ){
                if( mat[i][j] == vis ) continue;
                vector < pair < int , int > > aux;
                for( int w = 0; w < 4; w++ ){
                    int xx = i + x[w];
                    int yy = j + y[w];
                    if( xx >= 0 && xx < n && yy >= 0 && yy < m && mat[xx][yy] != vis ){
                        pair < int, int > at = make_pair(id[i][j],id[xx][yy]);
                        aux.push_back(at);
                    }
                }
                //if(aux.size() == 1) ans++;
                for( int w = 0; w < aux.size(); w++ ){
                    for( int z = 0; z < aux.size(); z++ ){
                        if( w == z ) continue;
                        gr[mapa[aux[w]]].push_back(mapa[aux[z]]);
                    }
                }
            }
        }
        M = k;
        writeInt(bipMatch()+ans);
        putchar_unlocked('\n');
        gr.clear();
        grafo.clear();
        vis++;
    }
    return 0;
}
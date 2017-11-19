#include <bits/stdc++.h>
#include <tr1/unordered_map>

using namespace std;
using namespace tr1;

typedef long long int64;
typedef unsigned long long uint64;

 #ifdef _WIN32 
    #define getchar_unlocked getchar
#endif

inline bool read( int &n ) {
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

vector < pair < double, double > > vet;
vector < pair < double, pair < int, int > > > mapa;
vector < pair < double, pair < int, int > > > :: iterator it;
double dist[1001][1001];

double getDist( int i, int j ){
    return (double)sqrt(((vet[i].first - vet[j].first)*(vet[i].first - vet[j].first) +
               (vet[i].second - vet[j].second)*(vet[i].second - vet[j].second)));
} 

int solve(){
    int tam = mapa.size();
    int ans = 0;
    for( int i = 0; i < tam; i++){
        for( int j = i+1; j < tam && (fabs(mapa[j].first-mapa[i].first) < 1e-50); j++ ){
            int p1a = mapa[i].second.first;
            int p1b = mapa[i].second.second;
            int p2a = mapa[j].second.first;
            int p2b = mapa[j].second.second;
            if( p1a == p2a ){
                double d = dist[p1b][p2b];
                if( (d > mapa[i].first || d < mapa[i].first) ) ans++;
            }
            else if( p1a == p2b ){
                double d = dist[p1b][p2a];
                if( (d > mapa[i].first || d < mapa[i].first) ) ans++;
            }
            else if( p1b == p2a ){
                double d = dist[p1a][p2b];
                if( (d > mapa[i].first || d < mapa[i].first) ) ans++;
            }
            else if( p1b == p2b ){
                double d = dist[p1a][p2a];
                if( (d > mapa[i].first || d < mapa[i].first) ) ans++;
            }
        }
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    int t, x, y;
    while( read(t) && t ){
        vet.clear();
        mapa.clear();
        for( int i = 0; i < t; i++ ){
            read(x); read(y);
            vet.push_back(make_pair(x,y));
        }
        for( int i = 0; i < t; i++ ){
            for( int j = i+1; j < t; j++ ){   
                dist[i][j] = dist[j][i] = getDist(i,j);
                mapa.push_back(make_pair(dist[i][j],make_pair(i,j)));
            }
        }
        sort(mapa.begin(), mapa.end());
        cout << solve() << "\n";
        //cout << ans << "\n";
    }
    return 0;
}
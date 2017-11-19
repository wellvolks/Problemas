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

struct tri{
    int de, para;
    double custo;
    tri( int de = 0, int para = 0, double custo = 0. ) : de(de), para(para), custo(custo) { }
    bool operator < ( const tri &a ) const{
        if( !(fabs(custo-a.custo) < 1e-50) ) return custo < a.custo;
        if( de != a.de ) return de < a.de;
        return para < a.para;
    }
};

vector < tri > grafo; 
vector < pair < double, double > > vet;
int n, used[10000000], vis = 1;

double getDist( int i, int j ){
    return sqrt(((vet[i].first - vet[j].first)*(vet[i].first - vet[j].first)) + 
                ((vet[i].second - vet[j].second)*(vet[i].second - vet[j].second)))/100.;
}

double mst_prim( ) {
    int v = 0; double weight, distance, result = 0;
    vector<double> dist(n, 1e9);  vector<bool> intree(n, false);
    dist[v] = 0;
    while ( !intree[v] ) {
        intree[v] = true;
        for(int i = 0; i < n; i++ ) if(!intree[i]) dist[i] = min(dist[i],getDist(v,i));
        v = 0; distance = 1e9;
        for(int i = 1; i < n; i++ ) if ( !intree[i] && dist[i] < distance ) {
            distance = dist[i]; v = i;
        }
        if( distance != 1e9 ) result += distance;
    }
    return result;
}

int main(){
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(2);
    int t, x, y;
    read(t);
    while( t-- ){
        read(n);
        for( int i = 0; i < n; i++ ){
            read(x);
            read(y);
            vet.push_back(make_pair(x,y));
        }
        cout << mst_prim() << '\n';
        vis++;
        vet.clear();
    }
    return 0;
}
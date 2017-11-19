#include <set>
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
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <iomanip>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>
    
using namespace std;
    
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define RFOR(i, b, a) for(int i = b; i >= a; --i)
#define REP(i, N) for(int i = 0; i < N; ++i)
#define RREP(i, N) for(int i = N-1; i >= 0; --i)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )
#define MAXN 1006003
#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFFLL
#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) __typeof((X).begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) int((V).size())
#define pb push_back
#define mp make_pair
    
    
struct tri{
    int qtd, pts, id, insc, sofrido;
    tri( int qtd = 0, int pts = 0, int id = 0, int insc = 0, int sofrido = 0) : qtd(qtd) , pts(pts), id(id), insc(insc), sofrido(sofrido) { }
};
   
typedef vector < int > vi;
typedef vector < vi > vii;
typedef vector < tri > vtri;
typedef vector < vtri > vvtri;
typedef long long int64;
typedef unsigned long long uint64;
  
#ifdef _WIN32 
    #define getchar_unlocked getchar
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
  
vector < tri > vet;
  
bool comp( const tri &a, const tri &b ){
    if( a.qtd != b.qtd ) return a.qtd > b.qtd;
    register double da = double(double(a.pts)/double(max(a.sofrido,1)));
    register double db = double(double(b.pts)/double(max(b.sofrido,1)));
    if( da < db || da > db ) return da > db;
    if( a.pts != b.pts ) return a.pts > b.pts;
    return a.id < b.id;
}
  
int main(){
    register int n, qt, ida, idb, pta, ptb, caso = 1;
    register bool ok = false;
    while( true ){
        read(n);
        if( !n ) break;
		if( ok ) printf("\n");
        ok = true;
        qt = n;
        vet.resize(n);
        n = (n * (n-1)) >> 1;
        REP(i,n){
            read(ida); read(pta); 
            vet[ida-1].id = ida;
            vet[ida-1].pts += pta;
            vet[ida-1].insc++;
            read(idb); read(ptb);
            vet[idb-1].id = idb;
            vet[idb-1].pts += ptb;
            vet[idb-1].insc++;
            vet[idb-1].sofrido += pta; 
            vet[ida-1].sofrido += ptb;
            if( ptb > pta ){ vet[idb-1].qtd += 2; vet[ida-1].qtd++; }
            else if( ptb < pta ){ vet[idb-1].qtd++; vet[ida-1].qtd += 2; }
            else { vet[idb-1].qtd += (idb > ida ) ? 2 : 1; vet[ida-1].qtd += (ida > idb) ? 2 : 1; }
        }
        //cout << "\n\n";
        //REP(i,qt) cout << vet[i].id << " " << vet[i].qtd << " " << vet[i].pts << " " << vet[i].sofrido << " " << vet[i].insc << "\n";
        sort(ALL(vet), comp);
        printf("Instancia %d\n",caso++);
        REP(i,qt){ if( i ) printf(" "); printf("%d",vet[i].id);  }
        printf("\n");
        vet.clear();
    }
    return 0;
}
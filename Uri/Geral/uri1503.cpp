#include <tr1/unordered_map>
#include <map>
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
using namespace tr1;
    
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define RFOR(i, b, a) for(int i = b; i >= a; --i)
#define REP(i, N) for(int i = 0; i < N; ++i)
#define RREP(i, N) for(int i = N-1; i >= 0; --i)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )
#define MAXN 10000000
#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFFLL
#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) __typeof((X).begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) int((V).size())
#define pb push_back
#define mp make_pair
    
struct tri{
    int atual, tipo;
    tri ( int atual = 0, int tipo = 0) : atual(atual), tipo(tipo) { }
};
    
int n, m;
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
  
char str[MAXN];
int S;
vi v;
uint64 poww[1000000], L[1000000];

void powwB(){
    poww[0] = 1ULL;
    for(int i = 1; i < 1000010; i++) poww[i] = poww[i-1]*33;
    char c = 'a';
    REP(i,26){ v.pb(c-'a'); c++; }
    random_shuffle (v.begin(),v.end());
}
const uint64 C = 5381ULL;
 
void Lcalc(){
    L[0] = C;
    REP(i,S) L[i+1] = L[i] * 33 + v[str[i]-'a'];
}
 
uint64 calc_hash(int a, int b){
    return (L[b] - L[a] * poww[b-a]);
}

unordered_map < uint64, int > ans, tam;
unordered_map < uint64, int > :: iterator it;

void Manakera(int n){
    /* impar */
    unordered_map < uint64 , int > mapa;
    vector < int > d1(n,0) , d2(n, 0);
    int l=0, r=-1, sum = 0;
    for (int i=0; i<n; ++i) {
        int k = (i > r ? 0 : min (d1[l+r-i], r-i)) + 1;
        while (i+k < n && i-k >= 0 && str[i+k] == str[i-k]){
            uint64 h = calc_hash(i-k,i+k);
            if(!(i+k == i-k)){
                mapa[h]++;
                tam[h] = (2*k)+1;
            }
            ++k;
        }  
        d1[i] = --k;
        if (i+k > r)
            l = i-k,  r = i+k;
    }
    /* par */
    l=0, r=-1;
    for (int i=0; i<n; ++i) {
        int k = (i>r ? 0 : min (d2[l+r-i+1], r-i+1)) + 1;
        while (i+k-1 < n && i-k >= 0 && str[i+k-1] == str[i-k]){
            uint64 h = calc_hash(i-k,i+k-1);
            if( !(i+k-1 == i-k) ){  
                mapa[h]++;
                tam[h] = (2*k);
            }
            ++k;
        }  
        d2[i] = --k;
        if (i+k-1 > r) l = i-k,  r = i+k-1;
    }
    it = mapa.begin();
    while( it != mapa.end() ){
        ans[it->first]++;
        it++;
    }
}

int used[300], vis = 1;

int main(){
    ios::sync_with_stdio(false);
    int n;
    powwB();
    while( cin >> n ){
        unordered_map < char, int > opa;
        REP(i,n){
            cin >> str;
            S = strlen(str);
            for( int i = 0; i < S; i++ ) used[str[i]] = vis;
            for( char i = 'a'; i <= 'z'; i++ ) if( used[i] == vis ) opa[i]++;
            vis++;
            Lcalc();
            Manakera(S);
        }
        it = ans.begin();
        int resp = 0;
        while( it != ans.end() ){
            if( it->second == n ) resp = max(resp, tam[it->first] );
            it++;
        }
        if( resp == 0 ) for( char i = 'a'; i <= 'z'; i++ ) if( opa[i] == n ){ resp = 1; break; }
        cout << resp << '\n';
        ans.clear();
        tam.clear();
    }
    return 0;
}
//#include <tr1/unordered_map>
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
//using namespace tr1;
 
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define RFOR(i, b, a) for(int i = b; i >= a; --i)
#define REP(i, N) for(int i = 0; i < N; ++i)
#define RREP(i, N) for(int i = N-1; i >= 0; --i)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )
#define MAXN 10000
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
 
int x[] = {-1,-1,-1, 0, 1, 1, 1, 0 };
int y[] = {-1, 0, 1, 1, 1, 0,-1,-1 };
 
int main(){
    double vet[4], a, b, c;
    cin >> vet[0] >> vet[1] >> vet[2];
    sort(vet, vet + 3);
    a = vet[2], b = vet[1], c = vet[0];
    if(a >= (b + c)) cout << "NAO FORMA TRIANGULO\n";
    else{
        if((a * a) == ((b * b) + (c * c))) cout << "TRIANGULO RETANGULO\n";
        if((a * a) > ((b * b) + (c * c))) cout << "TRIANGULO OBTUSANGULO\n";
        if((a * a) < ((b * b) + (c * c))) cout << "TRIANGULO ACUTANGULO\n";
        if(a == b && a == c && b == c) cout << "TRIANGULO EQUILATERO\n";
        if((a == b && b != c) || (b == c && b != a) || (a == c && a != b)) cout << "TRIANGULO ISOSCELES\n"; 
    }
    return 0;
}
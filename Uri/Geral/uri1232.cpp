#include <map>
#include <set>
#include <deque>
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
#define RREP(i, N) for(int i = N-1; i >= 1; --i)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )
#define MAXN 10000
#define LINF 0x3F3F3F3FFFFFFFFFLL
#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) __typeof((X).begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) int((V).size())
#define pb push_back
#define mk make_pair
 
struct tri{
    int atual, custo;
    tri ( int atual = 0, int custo = 0) : atual(atual), custo(custo) { }
};
 
struct par{
    int de, para;
    par(int de = 0, int para = 0) : de(de), para(para) { }
};
 
int n, m;
typedef vector < int > vi;
typedef vector < vi > vii;
typedef vector < tri > vtri;
typedef vector < vtri > vvtri;
typedef long long int64;
typedef unsigned long long uint64;
const  double pi = acos(-1.0);
const  double EPS = 1e-15;
const  double INF = 1e50;
int x[] = {-1,-1,-1, 0, 1, 1, 1, 0 };
int y[] = {-1, 0, 1, 1, 1, 0,-1,-1 };
 
int cmp(double a, double b = 0.0){ if(fabs(a-b) < EPS) return 0; return a > b ? 1 : -1; }
 
 
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
 
char cubo[7][10], cuboOri[7][10];
char comando[100];

void readInput(){
    int k = 0;
    REP(i,9) cubo[4][i] = '1';
    char str[] = {'2','2','2','3','3','3','4','4','4','5','5','5'};
    REP(j,3){
        k = 0;
        REP(i,12){
            cubo[k][i%3 + (j*3)] = str[i];
            if( i == 2 || i == 5 || i == 8 ) k++;
        }
    }
    REP(i,9) cubo[5][i] = '6';
    memcpy(cuboOri, cubo, sizeof(cubo));
}
 
 
 
void rotate(int face){
    char cp[4];
    face--;
     
    // rotaciona a face atual
    cp[0] = cubo[face][0];
    cp[1] = cubo[face][1];
    cp[2] = cubo[face][2];
     
    cubo[face][0] = cp[2];
    cubo[face][1] = cubo[face][5];
    cubo[face][2] = cubo[face][8];
 
    cubo[face][2] = cubo[face][8];
    cubo[face][5] = cubo[face][7];
    cubo[face][8] = cubo[face][6];
 
    cubo[face][8] = cubo[face][6];
    cubo[face][7] = cubo[face][3];
    cubo[face][6] = cp[0];
 
    cubo[face][6] = cp[0];
    cubo[face][3] = cp[1];
    cubo[face][0] = cp[2];
 
    // rotaciona os que estão ligados a face atual
    switch ( face ){
        case 0:
            cp[0] = cubo[1][0];
            cp[1] = cubo[1][3];
            cp[2] = cubo[1][6];
             
            cubo[1][0] = cubo[5][0];
            cubo[1][3] = cubo[5][3];
            cubo[1][6] = cubo[5][6];
             
            cubo[5][0] = cubo[3][8];
            cubo[5][3] = cubo[3][5];
            cubo[5][6] = cubo[3][2];
             
            cubo[3][8] = cubo[4][0];
            cubo[3][5] = cubo[4][3];
            cubo[3][2] = cubo[4][6];
             
            cubo[4][0] = cp[0];
            cubo[4][3] = cp[1];
            cubo[4][6] = cp[2];
        break;
        case 1:
            cp[0] = cubo[4][6];
            cp[1] = cubo[4][7];
            cp[2] = cubo[4][8];
             
            cubo[4][6] = cubo[2][0];
            cubo[4][7] = cubo[2][3];
            cubo[4][8] = cubo[2][6];
             
            cubo[2][0] = cubo[5][2];
            cubo[2][3] = cubo[5][1];
            cubo[2][6] = cubo[5][0];
             
            cubo[5][2] = cubo[0][8];
            cubo[5][1] = cubo[0][5];
            cubo[5][0] = cubo[0][2];
             
            cubo[0][8] = cp[0];
            cubo[0][5] = cp[1];
            cubo[0][2] = cp[2];
        break;
        case 2:
            cp[0] = cubo[3][0];
            cp[1] = cubo[3][3];
            cp[2] = cubo[3][6];
             
            cubo[3][0] = cubo[5][8];
            cubo[3][3] = cubo[5][5];
            cubo[3][6] = cubo[5][2];
             
            cubo[5][8] = cubo[1][8];
            cubo[5][5] = cubo[1][5];
            cubo[5][2] = cubo[1][2];
             
            cubo[1][8] = cubo[4][8];
            cubo[1][5] = cubo[4][5];
            cubo[1][2] = cubo[4][2];
             
            cubo[4][8] = cp[0];
            cubo[4][5] = cp[1];
            cubo[4][2] = cp[2];
        break;
        case 3:
            cp[0] = cubo[2][2];
            cp[1] = cubo[2][5];
            cp[2] = cubo[2][8];
             
            cubo[2][2] = cubo[4][0];
            cubo[2][5] = cubo[4][1];
            cubo[2][8] = cubo[4][2];
             
            cubo[4][0] = cubo[0][6];
            cubo[4][1] = cubo[0][3];
            cubo[4][2] = cubo[0][0];
             
            cubo[0][6] = cubo[5][8];
            cubo[0][3] = cubo[5][7];
            cubo[0][0] = cubo[5][6];
             
            cubo[5][8] = cp[0];
            cubo[5][7] = cp[1];
            cubo[5][6] = cp[2];
        break;
        case 4:
            cp[0] = cubo[3][0];
            cp[1] = cubo[3][1];
            cp[2] = cubo[3][2];
             
            cubo[3][0] = cubo[2][0];
            cubo[3][1] = cubo[2][1];
            cubo[3][2] = cubo[2][2];
             
            cubo[2][0] = cubo[1][0];
            cubo[2][1] = cubo[1][1];
            cubo[2][2] = cubo[1][2];
             
            cubo[1][0] = cubo[0][0];
            cubo[1][1] = cubo[0][1];
            cubo[1][2] = cubo[0][2];
             
            cubo[0][0] = cp[0];
            cubo[0][1] = cp[1];
            cubo[0][2] = cp[2];
        break;
        case 5:
            cp[0] = cubo[3][6];
            cp[1] = cubo[3][7];
            cp[2] = cubo[3][8];
             
            cubo[3][6] = cubo[0][6];
            cubo[3][7] = cubo[0][7];
            cubo[3][8] = cubo[0][8];
             
            cubo[0][6] = cubo[1][6];
            cubo[0][7] = cubo[1][7];
            cubo[0][8] = cubo[1][8];
             
            cubo[1][6] = cubo[2][6];
            cubo[1][7] = cubo[2][7];
            cubo[1][8] = cubo[2][8];
             
            cubo[2][6] = cp[0];
            cubo[2][7] = cp[1];
            cubo[2][8] = cp[2];
        break;
    }
}
 
bool check(){
    REP(i,6){
        REP(j,9){
           // cout << cubo[i][j] << " ";
            if( cuboOri[i][j] != cubo[i][j] ) return true;
        }
       // cout << endl;
    }
    //exit(1);
    return false;
}
 
int op[1000]; 

int main(){
    ios::sync_with_stdio(false);
    int t, r;
    op['L'] = 1;
    op['D'] = 2;
    op['R'] = 3;
    op['U'] = 4;
    op['F'] = 5;
    op['B'] = 6;
    readInput();
    while( gets(comando) != NULL ){
        int ans = 0;
        memcpy(cubo,cuboOri,sizeof(cubo));
        do{
            REP(i,strlen(comando)){
                r = (( toupper(comando[i]) == comando[i] ) ? ( 1 ) : ( -1 ));
                if( r < 0 ) rotate( op[toupper(comando[i])] );
                else REP(j,3) rotate( op[toupper(comando[i])] );
            }
            ans++;
        }while(check());
        printf("%d\n",ans);
    }
    return 0;
}
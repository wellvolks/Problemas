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
#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFFLL
#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) __typeof((X).begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) int((V).size())
#define pb push_back
#define mp make_pair
   
#ifdef _WIN32
    #define getchar_unlocked getchar
#endif
   
inline void read(  int &n ) {
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

vector < vector < int > > nivel;
   
typedef struct no{
    int chave;
    struct no *esquerdo;
    struct no* direito;
}No;
 
typedef struct ab{
    No* raiz;
}AB;
 
void inicializa(AB *arv){ arv->raiz = NULL; }
 int mxNivel = 0;
 
void in(No *num, int k){
	mxNivel = max(mxNivel, k);
    if(num->esquerdo == NULL && num->direito == NULL){ nivel[k].pb(num->chave); return ; }
    if(num->esquerdo != NULL) in(num->esquerdo, k + 1);
    nivel[k].pb(num->chave);
    if(num->direito != NULL) in(num->direito, k + 1);
}

 
void inserir(AB *arv,int chave){
    if(arv->raiz==NULL){
        arv->raiz= (No*) malloc(sizeof(No));
        arv->raiz->chave = chave;
        arv->raiz->direito = NULL;
        arv->raiz->esquerdo = NULL;
    }
    else{
        No *aux = arv->raiz;
        while(1){
            if(aux->chave > chave){
                if(aux->esquerdo == NULL){
                    aux->esquerdo = (No*) malloc(sizeof(No)) ;
                    aux->esquerdo->chave = chave;
                    aux->esquerdo->direito = NULL;
                    aux->esquerdo->esquerdo = NULL;
                    break;
                }else{
                    aux = aux->esquerdo;
                }
            }else if(aux->chave <= chave){
                if(aux->direito == NULL){
                    aux->direito = (No*) malloc(sizeof(No)) ;
                    aux->direito->chave = chave;
                    aux->direito->direito = NULL;
                    aux->direito->esquerdo = NULL;
                    break;
                }else{
                    aux = aux->direito;
                }
            }
        }
    }
}
 
  
int main(){
    ios::sync_with_stdio(false);
	int t, n, v, c = 1;
	read( t );
	while( t-- ){
		AB arvore;
        inicializa(&arvore);
		read( n );
		REP(i,n){
			read(v);
			inserir(&arvore,v);
		}
		nivel.resize( n );
		in(arvore.raiz, 0);
		printf("Case %d:\n", c++);
		REP(i,mxNivel+1){
			REP(j,nivel[i].size()){
				if( j || i ) printf(" ");
				printf("%d",nivel[i][j]);
			}
		}
		printf("\n\n");
		mxNivel = 0;
		nivel.clear();
	}
	return 0;
}
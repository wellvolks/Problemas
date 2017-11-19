//#include <tr1/unordered_map>
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
//using namespace tr1;
  
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define RFOR(i, b, a) for(int i = b; i >= a; --i)
#define REP(i, N) for(int i = 0; i < N; ++i)
#define RREP(i, N) for(int i = N-1; i >= 0; --i)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )
#define MAXN 10000
#define INF 0x3F3F3F3
#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) __typeof((X).begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) int((V).size())
#define pb push_back
#define mp make_pair


typedef long long int64;
typedef unsigned long long uint64;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef deque<int> di;

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

int  zona, transp, estacao[130], dist[130], t , b, resp, n, qt;
bool visited[130];
struct estado{
	int custo, linha, tipo, zona, veio;
	estado(int custo = 0, int linha = 0, int tipo = 0, int zona = 0, int veio = 0) : custo(custo), linha(linha), tipo(tipo) , zona(zona), veio(veio) {}
	bool operator < (const estado& e) const{
	    return custo >= e.custo;
	}
};

class gg{
  public:
	int para, linha;
	gg(int para = 0, int linha = 0 ) : para(para), linha(linha) {}
};

vector< vector < gg > > grafo;

int dijkstra(int s) {   
   for (int i = 0; i <= n+10; ++i) {
		dist[i] = INF;
		visited[i] = false;
	}
	dist[s] = 2;
	priority_queue< estado > pq;
	for(int i = 0; i < grafo[s].size(); i++){
		register int custoAt = 2;
		register int zona = estacao[grafo[s][i].para];
		if(grafo[s][i].linha < 0){
		    if(estacao[s] != estacao[grafo[s][i].para]) custoAt += 4;
		}
		else custoAt++;
		pq.push(estado(custoAt,grafo[s][i].linha,0,estacao[grafo[s][i].para],grafo[s][i].para));
		dist[grafo[s][i].para] = min(custoAt,dist[grafo[s][i].para]);
	}
	estado atual;
	visited[s] = true;
	while (!pq.empty()) {
		atual = pq.top();
		pq.pop();
		register int custo = atual.custo; 
		register int v = atual.veio;
		register int linha = atual.linha;
		register int zona = atual.zona;
		if (!visited[v]){ 
			visited[v] = true; 
			for (int i = 0; i < grafo[v].size(); i++){
				register int custoAt = 0;
				if(linha == grafo[v][i].linha){
					if((linha < 0 || grafo[v][i].linha < 0)&& zona != estacao[grafo[v][i].para]) custoAt += 4;
				}
				else if(grafo[v][i].linha > 0 && linha < 0) custoAt++;
				else if(grafo[v][i].linha  > 0 && linha >= 0) custoAt++;
				else if(grafo[v][i].linha < 0 || linha < 0){
					if(zona != estacao[grafo[v][i].para]) custoAt += 4;
				}	
			//	cout << "de " << v << " linha " << linha << " para " << grafo[v][i].para << " linha " << grafo[v][i].linha <<" com custo " << custoAt << " custo ant " << custo << " total " << custo + custoAt << " dist " << dist[v] <<" \n";
				if (dist[grafo[v][i].para] >= custo + custoAt) {
					dist[grafo[v][i].para] = custo + custoAt; 
					pq.push(estado(dist[grafo[v][i].para], grafo[v][i].linha, 0, estacao[grafo[v][i].para],grafo[v][i].para));				
				}
			}
		}
	}
	return 0;
}

void entrada(){
	register int ponto, aux, ant, de, para;
	for(int i = 1; i <= zona; i++){
		cin >> qt;
		for(int j = 0; j < qt; j++){
			cin >> ponto;
			estacao[ponto] = i;
		}
	}
	cin >> t >> b;
	for(int i = 1; i <= t; i++){
		cin >> qt;
		for(int j = 0; j < qt; j++){
			cin >> aux;
			if(j >= 1){
				grafo[ant].push_back(gg(aux,-(i)));
				grafo[aux].push_back(gg(ant,-(i)));
				ant = aux;
			}
			else ant= aux;
		}
	}
	for(int i = 1; i <= b; i++){
		cin >> qt;
		for(int j = 0; j < qt; j++){
			cin >> aux;
		if(j >= 1){
				grafo[ant].push_back(gg(aux,(i)));
				grafo[aux].push_back(gg(ant,(i)));
				ant = aux;
			}
			else ant= aux;
		}
	}
	n = transp;
	read(de); read(para);
	dijkstra(de);
	fprintf(stdout,"%d\n",dist[para]);
}
int main(){
	while(true){
		read(zona); read(transp);
		if( !(zona && transp) ) break;
		grafo.resize(transp+10);
		entrada();
		grafo.clear();
	}
	return 0;
}

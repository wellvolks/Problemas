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
#define mk make_pair
 
struct tri{
	int atual, custo;
	tri ( int atual = 0, int custo = 0) : atual(atual), custo(custo) { }
};
 
struct reta{
	int x1, y1, x2, y2;
	reta(int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0) : x1(x1) , y1(y1) , x2(x2) , y2(y2) { }
};
 
struct ponto{
	int x, y;
	ponto(int x = 0, int y = 0) : x(x) , y(y) { }
};
 
struct estado{
	int atual, used, tipo;
	double dist;
	estado(int atual = 0, int used = 0, int tipo = 0, double dist = 0. ) : atual(atual), used(used), tipo(tipo), dist(dist) { }
	bool operator < (const estado& e) const{
		if(dist != e.dist) return dist >= e.dist;
		if(used != e.used) return used >= e.used;
		return atual > e.atual;
	}
};
 
typedef vector < int > vi;
typedef vector < vi > vii;
typedef vector < tri > vtri;
typedef vector < vtri > vvtri;
typedef long long int64;
typedef unsigned long long uint64;
 
reta muros[60];
ponto cabines[60];
ponto cordenadas[400];
vector < vector < estado > > grafo;
static int n = 0;
double dist[5001];
int visited[5001];
 
ponto ori, dest;
 
bool intercepta(ponto px, ponto py, int qt){
	double a, b, c, d, ua, ub;
	reta m;
	REP(i, qt){
		m = muros[i];
		if((py.x == m.x1 && py.y == m.y1) || (py.x == m.x2 && py.y == m.y2)) continue;
		a = b = c = d = 0;
		a = ( (m.x2 - m.x1) * (px.y - m.y1) - (m.y2 - m.y1) * (px.x - m.x1) );
		b = ( (m.y2 - m.y1) * (py.x - px.x) - (m.x2 - m.x1) * (py.y - px.y) );
		c = ( (py.x - px.x) * (px.y - m.y1) - (py.y - px.y) * (px.x - m.x1) );
		d = ( (m.y2 - m.y1) * (py.x - px.x) - (m.x2 - m.x1) * (py.y - px.y) );
		if(!(b + d + a + c)) return true;
		ua = a / b;
		ub = c / d;
		if(ua >= 0. && ua <= 1. && ub >= 0. && ub <= 1.) return true;
	}
	return false;
}
 
double distancia(ponto a, ponto b){
	return sqrt(powl((a.x - b.x),2) + powl((a.y - b.y),2));
}
 
double dijkstra(int s, int c, int qt) {   
	REP(i,n){ dist[i] = INF; visited[i] = false; }
	priority_queue< estado > pq;
	estado atual, at;
	dist[s] = 0;
	REP(i,grafo[s].size()){
		atual = grafo[s][i];
		if(atual.tipo)
			pq.push(estado(atual.atual, 0, 1, atual.dist));
		else
			pq.push(estado(atual.atual, 0, 0, atual.dist));
		dist[atual.atual] = atual.dist;
	}
	visited[s] = true;
	while (!pq.empty()) {
		atual = pq.top();
		pq.pop();
		double custo = atual.dist; 
		int v = atual.atual;
		if (visited[v]) continue;
		visited[v] = true; 
		int tam = grafo[v].size();
		REP(i,tam){
			at = grafo[v][i];
			if (dist[at.atual] >= custo + at.dist) {
				dist[at.atual] = custo + at.dist; 
				if(atual.used < qt){
					if((!at.tipo && !atual.tipo) || (atual.tipo && !at.tipo))
						pq.push(estado(at.atual, atual.used + 1, 1, dist[at.atual]));
					else
						pq.push(estado(at.atual, atual.used, 0, dist[at.atual]));
				}
				else if(at.tipo) pq.push(estado(at.atual, atual.used, 1, dist[at.atual]));
			}
		}
	}
	return dist[c];
}
 
int main(){
	int t, m, c, pos = 0;
	double dis;
	reta at; ponto pt;
	ios::sync_with_stdio(false);
	while(cin >> t >> m >> c && !(t == 0 && m == 0 && c == 0)){
		REP(i,m){
			cin >> at.x1 >> at.y1 >> at.x2 >> at.y2;
			muros[i] = at;
			cordenadas[pos].x = at.x1, cordenadas[pos++].y = at.y1;
			cordenadas[pos].x = at.x2, cordenadas[pos++].y = at.y2;
		}
		REP(i,c){
			cin >> pt.x >> pt.y;
			cabines[i+1] = pt;
		}
		cin >> ori.x >> ori.y >> dest.x >> dest.y;
		bool caseSpecial = false;
		REP(i,c){
			if( cabines[i+1].x == ori.x && cabines[i+1].y == ori.y ){ caseSpecial = true; break; }
		}
		cabines[0] = ori;
		cabines[c+1] = dest;
		ponto muro;
		n = c + 2 + pos;
		grafo.resize(n+10);
		REP(i,c+2){
			FOR(j, i+1, c+1){
				if(!intercepta(cabines[i], cabines[j], m)){
					if(!caseSpecial && (!i)|| j+1 == c+2){
						dis = distancia(cabines[i], cabines[j]);
 						grafo[i].pb(estado(j,0,0,dis));
						grafo[j].pb(estado(i,0,0,dis));
					}
					else{
						caseSpecial = false;
						grafo[i].pb(estado(j,0,0,0));
						grafo[j].pb(estado(i,0,0,0));
					}
				}
			}
			
		}
		REP(i,c+2){
			REP(j,pos){
				if(!intercepta(cabines[i], cordenadas[j], m)){
					dis = distancia(cabines[i], cordenadas[j]);
					grafo[i].pb(estado(c+2+j, 0, 1, dis));
					grafo[c+2+j].pb(estado(i, 0, 1, dis));
				}
			}
		}
		printf("%.0lf\n",dijkstra(0,c+1, t));
		pos = 0;
		grafo.clear();
	}
	return 0;
}
 
 
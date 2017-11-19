#include <set>
#include <tr1/unordered_map>
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
#define N 10000
#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFFLL
#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) __typeof((X).begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) int((V).size())
#define pb push_back
#define mp make_pair

struct tri{
	int atual;
	string custo;
	tri ( int atual = 0, string custo = "") : atual(atual), custo(custo) { }
};

struct estado{
	int atual;
	int dist;
	char ant;
	estado(int atual = 0, int dist = 0, char ant = 0 ) : atual(atual), dist(dist), ant(ant) { }
	bool operator < (const estado& e) const{
		return dist > e.dist;
	}
};

typedef vector < int > vi;
typedef vector < vi > vii;
typedef vector < tri > vtri;
typedef vector < vtri > vvtri;
typedef long long int64;
typedef unsigned long long uint64;

unordered_map < string, int > mapa;
unordered_map < string, int > :: iterator it;

vector < vector < tri > > grafo;
vi dist;
int visited[5001][30], vis = 1;
int converte[300];

int dijkstra(int de, int para, int opa) {   
	priority_queue< estado > pq;
	tri at;
	dist.clear();
	dist.assign(mapa.size(), INF);
	visited[de][grafo[de][opa].custo[0]] = vis;
	pq.push(estado(grafo[de][opa].atual,grafo[de][opa].custo.size(),grafo[de][opa].custo[0]));
	estado atual;
	while (!pq.empty()) {
		atual = pq.top();
		pq.pop();
		register int custo = atual.dist; 
		register int v = atual.atual;
		if(v == para) return custo;
		if (visited[v][converte[atual.ant]] == vis) continue;
		visited[v][converte[atual.ant]] = vis; 
		register int tam = grafo[v].size();
		register int ant = -1;
		REP(i,tam){
			at = grafo[v][i];
			if(at.custo[0] == atual.ant) continue;
			if (dist[at.atual] > custo + at.custo.size()) {
				dist[at.atual] = custo + at.custo.size(); 
				pq.push(estado(at.atual,dist[at.atual],at.custo[0]));
				visited[v][converte[atual.ant]] = vis; 
			}
			else if(ant == at.atual) pq.push(estado(at.atual,custo + at.custo.size(),at.custo[0]));
			ant = at.atual;
		}
	}
	return -1;
}


int main(){
	register int t, id, dd, pp, aux = 97;
	char de[100], para[100], d[100], p[100], c[100];
	REP(i,26) converte[aux++] = i;
	ios::sync_with_stdio(false);
	while(cin >> t){
		if(!t) return 0;
		id = 0;
		cin >> de >> para;
		mapa[de] = 0; mapa[para] = 1;
		id = 2;
		grafo.resize(t*3 + 1);
		REP(i,t){
			cin >> d >> p >> c;
			it = mapa.find(d);
			if(it == mapa.end()){ dd = id++; mapa[d] = dd; }
			else dd = it->second;
			it = mapa.find(p);
			if(it == mapa.end()){ pp = id++; mapa[p] = pp; }
			else pp = it->second;
			grafo[dd].pb(tri(pp,c));
			grafo[pp].pb(tri(dd,c));
		}
		register int ans = INF, ret;
		bool ok = false;
		REP(i,SIZE(grafo[0])){
			ret = dijkstra(0,1,i);
			vis++;
			if(ret != -1){ 
				ok = true;
				ans = min(ans,ret);
			}
		}
		if(ok) printf("%d\n",ans);
		else printf("impossivel\n");
		grafo.clear();
		mapa.clear();
	}
	return 0;
}

#include <set>
#include <map>
#include <tr1/unordered_map>
#include <list>
#include <stack>
#include <sys/timeb.h>
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
#define MAXN 10010
#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFFLL
#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) __typeof((X).begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) int((V).size())
#define pb push_back
#define mp make_pair
const  double EPS = 1e-9;

struct tri{
	int atual, custo;
	tri ( int atual = 0, int custo = 0) : atual(atual), custo(custo) { }
};
struct timeb ini, fim;
typedef vector < int > vi;
typedef vector < vi > vii;
typedef vector < tri > vtri;
typedef vector < vtri > vvtri;


struct bloco{
	int espaco; int id;
	bool livre;
	bloco ( int espaco = 0, int id = 0, bool livre = false ) : espaco(espaco), id(id), livre(livre) { }
};

char str[100];

unordered_map < string, int > pertence;
unordered_map < string, int > :: iterator it2;

int chave = 0;
list < bloco > hd;
list < bloco > :: iterator ithd, ithd2, ant, prox;
int hdSize;

int verificaTamanho(){
	int tam = strlen(str), valor;
	char c = str[tam-2];
	str[tam - 2] = '\0';
	sscanf(str, "%d", &valor);
	switch (c){
		case 'K': return valor;
		case 'M': return (valor << 10);
		case 'G': return (valor << 20);
	}
}

bool insere(int id, int tamanho, int ver){
	int menor = INF;
	ithd2 = hd.end();
	for(ithd = hd.begin(); ithd != hd.end(); ithd++){
		if(ithd->espaco >= tamanho && ithd->livre){
			if(ithd->espaco < menor){
				menor = ithd->espaco;
				ithd2 = ithd;
			}
		}
	}
	if(ithd2 != hd.end()){
		int sobra = ithd2->espaco - tamanho;
		ithd2->livre = false;
		ithd2->id = id;
		ithd2->espaco = tamanho;
		if(sobra){ hd.insert(++ithd2,bloco(sobra,-1,true)); }
		return true;
	}
	return false;
}

void remove(int id){
	for(ithd = hd.begin(); ithd != hd.end(); ithd++){
		if(ithd->id == id){
			if(ithd != hd.begin()){
				ant = ithd;
				ant--;
				if(ant->livre){
					ant->espaco += ithd->espaco;
					ithd = hd.erase(ithd);
					ithd--;
				}
			}
			if(ithd != hd.end()){
				prox = ithd;
				prox++;
				if(prox != hd.end() && prox->livre){
					prox->espaco += ithd->espaco;
					ithd = hd.erase(ithd);
				}
			}
			ithd->livre = true;
			ithd->id = -1;
			break;
		}
	}
}

bool otimiza(int tamanho, int id, bool op){
	int livre = 0;
	if(op){
		ithd = hd.begin();
		while(ithd != hd.end()){
			if(ithd->livre){
				livre += ithd->espaco;
				ithd = hd.erase(ithd);
			}
			else ithd++;
		}
		if(livre){
			ithd = hd.end();
			if(livre >= tamanho){
				int sobra = livre - tamanho;
				hd.insert(ithd,bloco(tamanho,id,false));
				ithd = hd.end();
				if(sobra){ hd.insert(ithd,bloco(sobra,-1,true)); }
				return false;
			}
		}
	}
	else{
		ithd = hd.begin();
		while(ithd != hd.end()){
			if(ithd->livre){
				livre += ithd->espaco;
				ithd = hd.erase(ithd);
			}
			else ithd++;
		}
		if(!livre) return true;
		ithd = hd.end();
		hd.insert(ithd,bloco(livre,-1,true));
	}
	return true;
}

void printResp(int ans){
	if(ans <= 100 && ans > 75) printf("[ ]");
	else if(ans <= 75 && ans > 25) printf("[-]");
	else  printf("[#]");
}

void printStatus(){
	int limite = hdSize >> 3, livre = 0, ocupado = 0, total = 0, b = 0;
	double ans = 0.;
	ithd = hd.begin();
	while(true){
		if(ithd->livre) livre += ithd->espaco;
		else ocupado += ithd->espaco;
		if(livre + ocupado  >= limite){
			b++;
			if(ithd->livre){
				total = abs(ocupado - limite);
				ans = (double)total/(double)limite;
				printResp((int)ceil(ans * 100.));
				ocupado = 0;
				livre = abs(total-livre);
				if(livre >= limite){ithd->espaco = 0; continue; }
				ithd++;
			}
			else{
				ans = (double)livre/(double)limite;
				printResp((int)ceil(ans * 100.));
				if(ocupado > limite) ocupado -= limite;
				else ocupado = abs ( abs(livre - limite) - ocupado);
				livre = 0;
				if(ocupado >= limite){ithd->espaco = 0; continue; }
				ithd++;
			}
		}
		else ithd++;
		if( ithd == hd.end()) break;
	}
	if(b < 8) printResp(0.);
	printf("\n");
}

int main(){
	int n, id = 0;
	int valor;
	bool erro;
	char nome[100], operacao[100];
	int opa = 0;
//	ftime(&ini);
	while(scanf("%d",&n) && n){
		erro = 0;
		scanf(" %[^\n]s", &str);
		hdSize = verificaTamanho();
		hd.insert(hd.end(),bloco(hdSize,-1,true));
		REP(i,n){
			scanf(" %s",&operacao);
			if(operacao[0] == 'i'){
				scanf(" %s %s", &nome, &str);
				if(erro) continue;
				valor = verificaTamanho();
				if(insere(id, valor, 0)){
					pertence[nome] = id++;
				}
				else{
					erro = otimiza(valor, id, true);
					if(!erro) pertence[nome] = id++;
				}
			}
			else if(operacao[0] == 'r'){
				scanf(" %s",&nome);
				if(erro) continue;
				if(pertence.count(nome)){
					remove(pertence[nome]);
					pertence.erase(nome);
				}
			}
			else otimiza(0,0,false);
			id++;
		}
		if(erro) printf("ERRO: disco cheio\n");
		else printStatus();
		hd.clear(); pertence.clear() ;
	}
//	ftime(&fim);
//	cout << "Tempo : "<< ((double) fim.time + ((double) fim.millitm * 0.001)) - ((double) ini.time + ((double) ini.millitm * 0.001)) << "\n";
	return 0;
}

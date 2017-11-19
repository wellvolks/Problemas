#include <bits/stdc++.h>
#define MAX_VERTICES 120
#define MAX_QTD_CUSTOS 120
#define FATOR_DE_ATRITO 1
#define INF 0x7FFFFFFF

using namespace std;

struct par_no;
struct solucao;
struct resp;
int num_vertices, num_arestas, vertice_fonte, num_diametros, vertice_fonte_funcao_2;
int pai_vertice[MAX_VERTICES];
int pai[MAX_VERTICES], posicao[MAX_VERTICES];
int custo[MAX_VERTICES][MAX_VERTICES];
double pressao[MAX_VERTICES];
double demandas[MAX_VERTICES];
double ofertas[MAX_VERTICES];
double vazao[MAX_VERTICES][MAX_VERTICES];
double diametroAtual[MAX_VERTICES][MAX_VERTICES];
double comprimentos[MAX_VERTICES][MAX_VERTICES];
double pressaoMinima[MAX_VERTICES];
double pMax;
int dominado[MAX_VERTICES];
int diametros_possiveis[MAX_QTD_CUSTOS];
int grauVertice[MAX_VERTICES];

int pre[MAX_VERTICES];
double graph[MAX_VERTICES][MAX_VERTICES], ans;
double grafo_atual[MAX_VERTICES][MAX_VERTICES];
bool visit[MAX_VERTICES], circle[MAX_VERTICES];
int root;

vector < resp > resposta;
vector < solucao > solucoes;
vector < par_no > arestas;
vector < int > grafo[MAX_VERTICES];
vector < int > grafo_para_funcao2[MAX_VERTICES];

struct par_no{
	int origem, destino;
	par_no(int origem = 0, int destino = 0) : origem(origem), destino(destino) { }
	bool operator < (const par_no &at) const{
		if (custo[at.origem][at.destino] != custo[origem][destino]){
			return custo[at.origem][at.destino] < custo[origem][destino];
		}
		if (at.origem != origem) return at.origem < origem;
		return at.destino < destino;
	}
};

struct resp{
	vector < pair <int, int> > arvore;
	double diametros[MAX_VERTICES][MAX_VERTICES];
	double pressao[MAX_VERTICES];
	double vazao[MAX_VERTICES][MAX_VERTICES];
};

struct estado{
	int no_atual, no_anterior;
	double total;
	estado(int no_atual = 0, int no_anterior = 0, double total = 0.) : no_atual(no_atual), no_anterior(no_anterior), total(total) { }
};

struct solucao{
	int funcao_1;
	double funcao_2;
	solucao(int funcao_1 = 0, double funcao_2 = 0.) : funcao_1(funcao_1), funcao_2(funcao_2) { }
	bool operator < (const solucao &at) const{
		if (funcao_1 != at.funcao_1) return funcao_1 < at.funcao_1;
		return funcao_2 > at.funcao_2;
	}
};

solucao arvoreGeradora(bool &valido);

// Calcula o valor da perda e armazena em vazaoTotal
// vazaoTotal = somatório das diferenças entre as pressões ao longo do caminho, partindo do vértice fonte
void calculaFuncao2(double &vazaoTotal){
	queue < int > fila;
	fila.push(vertice_fonte);

	while (!fila.empty()){
		int at = fila.front();
		fila.pop();

		for (int i = 0, sz = grafo_para_funcao2[at].size(); i < sz; i++){
			vazaoTotal += pressao[at] - pressao[grafo_para_funcao2[at][i]];
			fila.push(grafo_para_funcao2[at][i]);
		}
	}
}

//Podem haver varias soluções, calculaSolucao encontra o Pareto delas
void calculaSolucao(){
	sort(solucoes.begin(), solucoes.end());
	solucao atual = solucoes[0];
	dominado[0] = 1;
	for (int i = 1, sz = solucoes.size(); i < sz; i++){
		if (!(solucoes[i].funcao_2 < atual.funcao_2)) continue;
		atual = solucoes[i];
		dominado[i] = 1;
	}
}

//Antes do cálculo da funcao2 precisamos verificar as pressões em cada nó. 
//calculaPressoes calcula a pressão de cada nó partindo do vértice com o pMin máximo
bool calculaPressoes(){
	int no_atual = vertice_fonte_funcao_2, no_anterior = -1;
	pressao[no_atual] = pressaoMinima[no_atual];

	while (no_atual != -1){

		queue < estado > fila;
		for (int i = 0; i < grafo_para_funcao2[no_atual].size(); i++){
			if (grafo_para_funcao2[no_atual][i] != no_anterior){
				fila.push(estado(grafo_para_funcao2[no_atual][i], no_atual, 0));
			}
		}

		while (!fila.empty()){
			estado at = fila.front();
			fila.pop();
			int no_ant = at.no_anterior;
			int no_at = at.no_atual;
			pressao[no_at] = pressao[no_ant] - (pow(vazao[no_ant][no_at], 2) / pow(diametroAtual[no_ant][no_at], 5) * comprimentos[no_ant][no_at] * FATOR_DE_ATRITO);
			if ((pressao[no_at] < pressaoMinima[no_at]) || !(pressao[no_at] < pMax)) return false;

			for (int i = 0, sz = grafo_para_funcao2[no_at].size(); i < sz; i++){
				fila.push(estado(grafo_para_funcao2[no_at][i], no_at, 0));
			}
		}

		no_anterior = no_atual;
		no_atual = pai_vertice[no_atual];
		if (no_atual != -1){
			pressao[no_atual] = pressao[no_anterior] + (pow(vazao[no_atual][no_anterior], 2) / pow(diametroAtual[no_atual][no_anterior], 5) * comprimentos[no_atual][no_anterior] * FATOR_DE_ATRITO);
			if ((pressao[no_atual] < pressaoMinima[no_atual]) || !(pressao[no_atual] < pMax)) return false;
		}
	}

	return true;
}

// K * Q^2/D * L 
// calculaVazoes calcula os valores de Q para que seja possível computar a função 2 ( Perda )
double calculaVazoes(int no_atual, int no_anterior){
	pai_vertice[no_atual] = no_anterior;

	double vazaoAtual = demandas[no_atual];
	for (int i = 0, sz = grafo[no_atual].size(); i < sz; i++){
		if (grafo[no_atual][i] != no_anterior){
			grafo_para_funcao2[no_atual].push_back(grafo[no_atual][i]);
			vazaoAtual += calculaVazoes(grafo[no_atual][i], no_atual);
		}
	}

	vazao[no_atual][no_anterior] = vazao[no_anterior][no_atual] = vazaoAtual - ofertas[no_atual];

	return vazao[no_atual][no_anterior];
}

vector < pair < int, int > > total;
//verificaPossiblidade verifica todas as árvores geradoras mínimas possíveis e, caso a árvore atual seja válida, armazena o valor
bool verificaPossibilidades(int aresta_atual){
	bool valido = true;
	if (aresta_atual >= num_arestas){
		total.clear();
		solucao solucao_nova = arvoreGeradora(valido);
		if (solucao_nova.funcao_1 < diametros_possiveis[num_diametros-1] && total.size() == num_vertices-1){
			calculaVazoes(vertice_fonte, -1);
			valido = calculaPressoes();
			if (valido) calculaFuncao2(solucao_nova.funcao_2);
			if (valido){
				//imprimeSolucao();
				solucoes.push_back(solucao_nova);
				resp ans;
				ans.arvore = total;
				memcpy(ans.vazao, vazao, sizeof(vazao));
				memcpy(ans.pressao, pressao, sizeof(pressao));
				memcpy(ans.diametros, diametroAtual, sizeof(diametroAtual));
				resposta.push_back(ans);
				return true;
			}
		}
		return false;
	}

	bool ha_solucao = false;
	for (int i = 0; i < num_diametros; i++){
		int no_u = arestas[aresta_atual].origem;
		int no_v = arestas[aresta_atual].destino;

		grafo_atual[no_u + 1][no_v + 1] = custo[no_u][no_v] = diametros_possiveis[i] * comprimentos[no_u][no_v];
		diametroAtual[no_u][no_v] = diametros_possiveis[i];

		if (verificaPossibilidades(aresta_atual + 1)) ha_solucao = true;
	}

	return ha_solucao;
}

void dfs(int t){
	int i;
	visit[t] = true;
	for (i = 1; i <= num_vertices; ++i){
		if (!visit[i] && graph[t][i] != INF)
			dfs(i);
	}
}

bool check(){
	memset(visit, false, sizeof(visit));
	dfs(root);

	for (int i = 1; i <= num_vertices; ++i){
		if (!visit[i])
			return false;
	}
	return true;
}

int exist_circle(){
	int i, j;
	root = 1; pre[root] = root;
	for (i = 1; i <= num_vertices; i++){
		if (!circle[i] && i != root){
			pre[i] = i; 
			graph[i][i] = INF;
			for (j = 1; j <= num_vertices; ++j){
				if (!circle[j] && graph[j][i] < graph[pre[i]][i]){
					pre[i] = j;
				}
			}
		}
	}

	for (i = 1; i <= num_vertices; i++){
		if (circle[i]) continue;
		memset(visit, false, sizeof(visit));
		
		int j = i;
		while (!visit[j]){
			visit[j] = true;
			j = pre[j];
		}

		if (j == root) continue;
		return j;
	}

	return -1;
}


void  update(int t){
	int i;
	int j;
	ans += graph[pre[t]][t];
	for (i = pre[t]; i != t; i = pre[i]){
		ans += graph[pre[i]][i];
		circle[i] = true;
	}

	for (i = 1; i <= num_vertices; ++i){
		if (!circle[i] && graph[i][t] != INF){
			graph[i][t] -= graph[pre[t]][t];
		}
	}

	for (j = pre[t]; j != t; j = pre[j]){
		for (int i = 1; i <= num_vertices; ++i){
			if (circle[i]) continue;
			if (graph[i][j] != INF){
				graph[i][t] = min(graph[i][t], graph[i][j] - graph[pre[j]][j]);
			}
			graph[t][i] = min(graph[j][i], graph[t][i]);
		}
	}
}

//Setado os valores para as arestas podemos então calcular a árvore geradora de fato
solucao arvoreGeradora(bool &valido){
	solucao solucao_atual;
	for (int i = 0; i < num_vertices; i++){
		grafo[i].clear();
		grafo_para_funcao2[i].clear();
	}

	for (int i = 0; i <= num_vertices; i++){
		for (int j = 0; j <= num_vertices; j++){
			graph[i][j] = grafo_atual[i][j];
		}
	}

	int j;
	ans = 0;
	root = 1;
	memset(circle, false, sizeof(circle));
	while ((j = exist_circle()) != -1){
		update(j);
	}

	for (j = 1; j <= num_vertices; ++j){
		if (j != root && !circle[j]){
			int no_u = pre[j] - 1;
			int no_v = j - 1;
			grafo[no_u].push_back(no_v);
			grafo[no_v].push_back(no_u);
			solucao_atual.funcao_1 += custo[no_u][no_v];
			total.push_back(make_pair(no_u, no_v));
		}
	}
	
	return solucao_atual;
}

int main(){
	ios::sync_with_stdio(false);

	int origem, destino, comprimento;
	int verifica_paleto = 0;
	vertice_fonte = 0;
	cin >> num_vertices >> num_arestas >> pMax >> verifica_paleto;

	for( int i = 0; i <= num_vertices; i++ ){
		for( int j = 0; j <= num_vertices; j++ ){
			custo[i][j] = INF;
		}
	}
	for (int i = 0; i < num_arestas; i++){
		cin >> origem >> destino >> comprimento;
		comprimentos[origem][destino] = comprimento;
		arestas.push_back(par_no(origem, destino));
	}

	cin >> num_diametros;

	for (int i = 0; i < num_diametros; i++){
		cin >> diametros_possiveis[i];
	}

	double pressaoMax = -INF;
	for (int i = 0; i < num_vertices; i++){
		cin >> ofertas[i] >> demandas[i] >> pressaoMinima[i];
		if (pressaoMinima[i] > pressaoMax){
			pressaoMax = pressaoMinima[i];
			vertice_fonte_funcao_2 = i;
		}
	}

	diametros_possiveis[num_diametros] = (10000000);
	num_diametros++;
	sort(diametros_possiveis, diametros_possiveis + num_diametros);

	for (int i = 0; i <= num_vertices; i++){
		for (int j = 0; j <= num_vertices; j++){
			grafo_atual[i][j] = INF;
		}
	}

	verificaPossibilidades(0);
	calculaSolucao();

	for (int i = 0, sz = solucoes.size(); i < sz; i++){
		if(dominado[i] || verifica_paleto){
			cout << fixed << setprecision(2) << solucoes[i].funcao_1 << " " << solucoes[i].funcao_2 << '\n';
			cout << "Arvore: (vertice u --- vertice v ( vazao ) ( diamentro ) )\n";
			for( int j = 0, tz = resposta[i].arvore.size(); j < tz; j++ ){
				int u = resposta[i].arvore[j].first;
				int v = resposta[i].arvore[j].second;
				cout << u+1 << " --- " << v+1 << " ( " << resposta[i].vazao[u][v] << " ) ( " << resposta[i].diametros[u][v] << " )\n";
			}
			cout << "Pressao:\n";
			for( int j = 0; j < num_vertices; j++ ){
				cout << "Vertice " << j+1 << ": " << resposta[i].pressao[j] << "\n";
			}
			cout << '\n';
		}
	}
	
	return 0;
}
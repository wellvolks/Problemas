#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <iomanip>
#include <string.h>
#define For(i, x) for(int i = 0; i < x; i++)
#define FOR(i, x, y) for(int i = y; i <= x; i++)
#define INF 0x3f3f3f
using namespace std;

double mem[15][15][300];
int visit[15][15][300], vis = 1;
double dist[15][15];
string str;

struct calc{
	double custo;
	int num;
	calc(double custo = 0, int num = 0) : custo(custo), num(num){}
};

calc tecla[200];

struct point{
	int x, y;
	point(int x = 0, int y = 0) : x(x), y(y){}
};

point ponto[11];

void distancia(){
	for(int i = 0; i <= 10; i++){
    for(int j = i+1; j <= 10; j++){
    	dist[i][j] = dist[j][i] = sqrt(powl(ponto[i].x - ponto[j].x, 2) + powl(ponto[i].y - ponto[j].y,2))/30;
    }
    dist[i][i] = 0;
	}
}

#ifdef _WIN32 
    #define getchar_unlocked getchar
#endif
 

double solve(int e, int d, int pos){
	if(pos >= str.size()) return 0;
	if(visit[e][d][pos] == vis) return mem[e][d][pos];
	visit[e][d][pos] = vis;
	return mem[e][d][pos] = min(solve(tecla[str[pos]].num, d, pos + 1) + dist[e][tecla[str[pos]].num] + tecla[str[pos]].custo, solve(e,tecla[str[pos]].num, pos + 1) + dist[d][tecla[str[pos]].num] + tecla[str[pos]].custo);
}

int main(){
	ios::sync_with_stdio(false);
	string aux;
	tecla['a'].custo = 0.2; tecla['e'].custo = 0.4; tecla['i'].custo = 0.6; tecla['m'].custo = 0.2; tecla['q'].custo = 0.4; tecla['u'].custo = 0.4;
	tecla['b'].custo = 0.4; tecla['f'].custo = 0.6; tecla['j'].custo = 0.2; tecla['n'].custo = 0.4; tecla['r'].custo = 0.6; tecla['v'].custo = 0.6;
	tecla['c'].custo = 0.6; tecla['g'].custo = 0.2; tecla['k'].custo = 0.4; tecla['o'].custo = 0.6; tecla['s'].custo = 0.8; tecla['x'].custo = 0.4;
	tecla['d'].custo = 0.2; tecla['h'].custo = 0.4; tecla['l'].custo = 0.6; tecla['p'].custo = 0.2; tecla['t'].custo = 0.2; tecla['z'].custo = 0.8;
	tecla['y'].custo = 0.6; tecla['w'].custo = 0.2;    
	tecla['a'].num = 2; tecla['e'].num = 3; tecla['i'].num = 4; tecla['m'].num = 6; tecla['q'].num = 7; tecla['u'].num = 8;
	tecla['b'].num = 2; tecla['f'].num = 3; tecla['j'].num = 5; tecla['n'].num = 6; tecla['r'].num = 7; tecla['v'].num = 8;
	tecla['c'].num = 2; tecla['g'].num = 4; tecla['k'].num = 5; tecla['o'].num = 6; tecla['s'].num = 7; tecla['x'].num = 9;
	tecla['d'].num = 3; tecla['h'].num = 4; tecla['l'].num = 5; tecla['p'].num = 7; tecla['t'].num = 8; tecla['z'].num = 9;
	tecla['y'].num = 9; tecla['w'].num = 9;
	tecla['#'].num = 10; tecla['#'].custo = 0.2;
	tecla[' '].num = 0; tecla[' '].custo = 0.2;
	ponto[2].x = 1; ponto[2].y = 3;
	ponto[3].x = 2; ponto[3].y = 3;
	ponto[4].x = 0; ponto[4].y = 2;
	ponto[5].x = 1; ponto[5].y = 2;
	ponto[6].x = 2; ponto[6].y = 2;
	ponto[7].x = 0; ponto[7].y = 1;
	ponto[8].x = 1; ponto[8].y = 1;
	ponto[9].x = 2; ponto[9].y = 1;
	ponto[10].x = 2; ponto[10].y = 0;
	ponto[0].x = 1; ponto[0].y = 0;
	distancia();
	while(true){
		aux = "";
		char c = getchar_unlocked();
		if( c == EOF ) break;
		while( c != '\n' && c != EOF){ aux += c; c = getchar_unlocked(); }
		For(i, aux.size() - 1){
			str.push_back(aux[i]);
			if(tecla[aux[i]].num == tecla[aux[i + 1]].num)str.push_back('#');
		}
		str.push_back(aux[aux.size() - 1]);
		printf("%.2lf\n",solve(4, 6, 0));
		str = "";
		vis++;
		if( c == EOF ) break;
	}
	return 0;
}


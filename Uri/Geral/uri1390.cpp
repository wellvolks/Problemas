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
#define MAXN 100010 
#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFFLL
#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) __typeof((X).begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) int((V).size())
#define pb push_back
#define mp make_pair
#define check(c) ( (c == '+' || c== '*' || c == '/' || c == '=' ) ? ( 1 ) : ( 0 ) ) 
#ifdef _WIN32 
    #define getchar_unlocked getchar
#endif

typedef unsigned long long uint64;
struct aresta{
    int atual, valor;
    aresta ( int atual = 0, int valor = 0) : atual(atual), valor(valor) { }
};
 
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


char str[10000], p[10000];
vector < string > vet, ans, A, B;

uint64 convertToBase(int base, string number){
    register unsigned int  aux = 0, p = 0, s;
	if( number == "0" ) return 0;
	int i, q = 0;
	string wellvolks = "";
	char st[10000];
	uint64 valor = 0;
	sscanf((char*)number.c_str(),"%lld", &valor);
    while(valor > 0){
        aux = ( valor % base );
		sprintf(st, "%d", aux);
        wellvolks += st; 
        valor /= base;
    }
    reverse(ALL(wellvolks));
	uint64 resp = 0;
	sscanf((char*)wellvolks.c_str(), "%lld", &resp);
    return resp;
}

/*
uint64 convertToBase(int base, string number){
	uint64 ret = 0;
	int tamanho = number.size();
	if ( tamanho == 1 ) ret = number[0]-'0';
	for ( register int i = tamanho-1, j = 0; i >= 1; --i, ++j ){
		if ( i == tamanho-1 ) ret = (number[j]-'0')*base + (number[j+1]-'0');
		else ret = ((ret)*base) + (number[j+1]-'0');
	}
	return ret;
}
*/
bool solveExpr(int base){
	int i = 0, tam;
	uint64 a, b;
	tam = A.size();
	stack < uint64 > pilha;
	char eita[10000];
	for( i = 0; i < tam; i++ ){
		if( check(A[i][0]) ){
			uint64 res = pilha.top();
			pilha.pop();
			switch ( A[i][0] ){
				case '+': res += pilha.top(); break;
				case '*': res *= pilha.top(); break;
				case '-': res -= pilha.top(); break;
			}
			pilha.pop();
			sprintf(eita, "%lld", res);
			pilha.push(convertToBase(base, eita));
		}
		else pilha.push(convertToBase(base, A[i]));
	}
	a = pilha.top();
	pilha.pop();
	cout << pilha.size() << "\n";
	tam = B.size();
	for( i = 0; i < tam; i++ ){
		if( check(B[i][0]) ){
			uint64 res = pilha.top();
			pilha.pop();
			switch ( B[i][0] ){
				case '+': res += pilha.top(); break;
				case '*': res *= pilha.top(); break;
				case '-': res -= pilha.top(); break;
			}
			pilha.pop();
			sprintf(eita, "%lld", res);
			pilha.push(convertToBase(base, eita));
		}
		else pilha.push(convertToBase(base, B[i]));
	}
	b = pilha.top();
	cout << a << " " << b << "\n";
	return (a == b);
}
 
int qual(char  c){
    if((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) return 1;
    else if( c == '(' ) return 2;
    else if( c == ')' ) return 3;
    else if( c == '+' || c == '-') return 4;
    else if( c == '*' || c == '/') return 5;
    else return 6;
}
 
void inToPos(bool flag){
    int i = 0, j = 0, pp = 0, tam = vet.size();
	p[0] = '\0';
	ans.clear();
	string af = "";
    REP(i,tam){
        switch (qual(vet[i][0])){
            case 1: ans.pb( vet[i] ); break;
            case 2: p[pp++] = vet[i][0]; break;
            case 3:
                    while(pp && p[pp-1] != '('){
						af = "";
						af += p[--pp];
						ans.pb(af);
					}
                    pp--;
                break;
            case 4:
                    while(pp && p[pp-1] != '('){
						af = "";
						af += p[--pp];
						ans.pb(af);
					}
                    p[pp++] = vet[i][0];
                break;
            case 5:
                    while(pp && p[pp-1] != '(' && qual(p[pp-1]) != 4){ 
						af = "";
						af += p[--pp];
						ans.pb(af);
					}
                    p[pp++] = vet[i][0];
                break;
            case 6:
                    p[pp++] = vet[i][0]; break;
                break;  
        }
    }
    while(pp){
		af = "";
		af += p[--pp];
		ans.pb(af);
	}
	tam = ans.size();
	if( flag ) REP(i,tam) A.pb(ans[i]);
	else REP(i,tam) B.pb(ans[i]);
}

int main(){
	int i, j = 0;
	string aux = "";
	vector < int > resp;
	while( gets(str) && str[0] != '=' ){
		for( i = 0; str[i] != '\0'; i++ ){
			if( check(str[i]) ){
				vet.pb(aux);
				j++;
				aux = "";
				if( str[i] == '=' ){
					inToPos( true );
					vet.clear();
					j = 0;
					continue;
				}
				vet.pb("");
				vet[j++] += str[i];
			}
			else aux += str[i];
		}
		if( aux.size() ) vet.pb(aux);
		inToPos( false );
		FOR(i,6,20){ 
			if( solveExpr(i) ) resp.pb(i);
		}
		if( !resp.size() ) puts("*");
		else{
			int tam = resp.size();
			if( resp[tam-1] == 10000 ) printf("%d+\n",resp[0]);
			else{
				REP(i,tam){ 
					if( i ) printf(" ");
					printf("%d",resp[i]); 
				}
				printf("\n");
			}
		}
		resp.clear();
		ans.clear();
		A.clear();
		B.clear();
		j = 0;
	}
	return 0;
}

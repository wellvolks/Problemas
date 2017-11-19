/*///////////////////////////////////////////////////////////////////////////////*/
//						   Universidade Federal de Goias                         //
//							 Prof. Eduardo Albuquerque							 //
//					   Aluno: Welton Cardoso do Carmo  107755					 //
//																				 //
//							   Sistema Operacional I                             //
/*///////////////////////////////////////////////////////////////////////////////*/

#include <stdio.h>
#include <stdlib.h>
#define bool int
#define true 1
#define false 0
#define MAX 1000

typedef struct no{
	struct no *pai;
	char *chave;
	struct no *esquerdo;
	struct no* direito;
}No;

typedef struct ab{
	No* raiz;
	int quantidade;
}AB;

int op[300], pos = 0;
char *str, ans[MAX];
No *ant;
bool tipoAnt;

void inserir(AB *arv, char chave[]){
	int i;
	if(arv->raiz==NULL){
		arv->raiz= (No*) malloc(sizeof(No));
		arv->raiz->_key = (char*) malloc(sizeof(char));
		for(i = 0; i < sizeof(chave); i++) arv->raiz->chave[i] = chave[i];
		arv->raiz->_key[sizeof(chave)] = '\0';
		arv->raiz->direito = NULL;
		arv->raiz->esquerdo = NULL;
		arv->raiz->pai = NULL;
		arv->quantidade++;
		tipoAnt = op[chave[0]];
		ant = arv->raiz;
		return ;
	}
	if(tipoAnt){
		ant->esquerdo = (No*) malloc(sizeof(No)) ;
		ant->esquerdo->chave = (char*) malloc(sizeof(char));
		for(i = 0; i < sizeof(chave); i++) ant->esquerdo->chave[i] = chave[i];
		ant->esquerdo->chave[sizeof(chave)] = '\0';
		ant->esquerdo->direito = NULL;
		ant->esquerdo->esquerdo = NULL;
		ant->esquerdo->pai = ant;
		arv->quantidade++;
		tipoAnt = op[chave[0]];
		ant = ant->esquerdo;
	}
	else{
		No *aux = ant->pai;
		if(aux == NULL){
			aux = ant;
			aux->direito = (No*) malloc(sizeof(No)) ;
			aux->direito->chave = (char*) malloc(sizeof(char));
			for(i = 0; i < sizeof(chave); i++) aux->direito->chave[i] = chave[i];
			aux->direito->chave[sizeof(chave)] = '\0';
			aux->direito->direito = NULL;
			aux->direito->esquerdo = NULL;
			aux->direito->pai = aux;
			arv->quantidade++;
			tipoAnt = op[chave[0]];
			ant = aux->direito;
			return ;
		}
		while(1){
			if(aux->direito == NULL){
				aux->direito = (No*) malloc(sizeof(No)) ;
				aux->direito->chave = (char*) malloc(sizeof(char));
				for(i = 0; i < sizeof(chave); i++) aux->direito->chave[i] = chave[i];
				aux->direito->chave[sizeof(chave)] = '\0';
				aux->direito->direito = NULL;
				aux->direito->esquerdo = NULL;
				aux->direito->pai = aux;
				arv->quantidade++;
				tipoAnt = op[chave[0]];
				ant = aux->direito;
				return ;
			}
			else aux = aux->pai;
			if(aux == NULL) break;
		}
		aux = arv->raiz;
		while(1){
			if(aux->direito == NULL){
				aux->direito = (No*) malloc(sizeof(No)) ;
				aux->direito->chave = (char*) malloc(sizeof(char));
				for(i = 0; i < sizeof(chave); i++) aux->direito->chave[i] = chave[i];
				aux->direito->chave[sizeof(chave)] = '\0';
				aux->direito->direito = NULL;
				aux->direito->esquerdo = NULL;
				aux->direito->pai = aux;
				arv->quantidade++;
				tipoAnt = op[chave[0]];
				ant = aux->direito;
				return ;
			}
			else aux = aux->direito;
		}
	}
}

char InfixoExpressao[MAX], AnsExpressao[MAX];
int p1 = 0, p2 = 0, p3 = 0;


void infixo(No *p){
	if(p->direito == NULL && p->esquerdo == NULL){ 
		int i = 0;
		if(p1) InfixoExpressao[p1++] = ' ';
		while(p->chave[i] != '\0') InfixoExpressao[p1++] = p->chave[i++]; 
		return ;  
	}
	if(p1) InfixoExpressao[p1++] = ' ';
	InfixoExpressao[p1++] = p->chave[0];
	if(p->esquerdo != NULL) infixo(p->esquerdo);
	if(p->direito != NULL) infixo(p->direito);
}

void tranforma(){
	bool ok = false;
	if(!p2) ok = true;
	if(p2 != p1){
		char aux[MAX];
		int i = 0;
		while(InfixoExpressao[p2] != '\0' && InfixoExpressao[p2] == ' ') p2++;
		while(InfixoExpressao[p2] != '\0' && InfixoExpressao[p2] != ' ') aux[i++] = InfixoExpressao[p2++];
		aux[i] = '\0';
		if(op[aux[0]]){
			if(ok);
			else AnsExpressao[p3++] = '('; // printf("(");
			tranforma();
			i = 0;
			while(aux[i] != '\0') AnsExpressao[p3++] = aux[i++];  //printf("%s",aux);
			tranforma();
			if(ok);
			else AnsExpressao[p3++] = ')'; //printf(")");
		}
		else{ i = 0; while(aux[i] != '\0') AnsExpressao[p3++] = aux[i++]; } //printf("%s",aux);
	}
}

void expressao(AB *arvore){
	if(arvore->raiz == NULL) return ;
	infixo(arvore->raiz);
	tranforma();
}

char * strtok(char comp){
	while((*str == comp) && *str != '\0') str++;
	if(*str == '\0') return NULL;
	int tam = 0;
	char *cpy = str, *ret;
	while((*str != comp) && *str != '\0'){ str++; tam++; }
	ret = (char*) malloc(tam * sizeof(char));
	tam = 0;
	while((*cpy != comp) && *cpy != '\0'){ 
		ret[tam++] = *cpy; 
		cpy++; 
	}
	ret[tam] = '\0';
	return ret;
}

int main(){
	int i;
	AB arvore;
	op['+'] = op['-'] = op['*'] = op['/'] = op[' '] = 1;
	char *p;
	str = (char*) malloc(100*sizeof(char));
	gets(str);
	arvore.raiz = NULL;
	p = strtok(' ');
	while(p != NULL){ 
		inserir(&arvore,p); 
		p = strtok(' '); 
	}
	expressao(&arvore);
	AnsExpressao[p3] = '\0';
	if(!p3) printf("\n");
	else printf("%s\n",AnsExpressao);
	return 0;
}

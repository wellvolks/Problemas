#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int t, tam, tam2, pos = 0;
	scanf("%d",&t);
	char c, resp[4000];;
	c = getchar();
	while(t--){
		char frase[200];
		gets(frase);
		tam2 = tam = strlen(frase);
		pos = 0;
		tam >>= 1;
		for(int i = tam-1; i >= 0; i--) resp[pos++] = frase[i];
		for(int i = tam2-1; i >= tam; i--) resp[pos++] = frase[i];
		resp[pos] = '\0';
		printf("%s\n",resp);
	}
	return 0;
}

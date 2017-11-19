#include <stdio.h>
#include <string.h>

int main(){
	int n,resp, pos, i, tm;
	scanf("%d",&n);
	while(n--){
		char str[10001];
		char pilha[10001];
		scanf("%s",&str);
		resp = 0, pos = 0;
		tm = strlen(str);
		for(i = 0; i < tm; i++){
			if(pos == 0 && str[i] != '.'){
				pilha[pos++] = str[i];
			}
			else{
				if(str[i] == '>' && pilha[pos-1] == '<'){
					resp++;
					pos--;
				}
				else if(str[i] != '.') pilha[pos++] = str[i];
			}
		}
		printf("%d\n",resp);
	}
	return 0;
}
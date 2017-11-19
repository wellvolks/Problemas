#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
using namespace std;

int mem = sizeof(int)*100001;
int vet[100001];
int valor[100001];
int main(){

	int n, m;
	int x=0, y=0, H=0, E=0, R=0, i=0, j=0;
	char str[2];
	
	while(scanf("%d %d",&n,&m)!=EOF){
		memcpy (vet,valor,mem);
	for(i=0; i<m; i++){
			scanf("%s %d %d",str,&x,&y);
			x--;
			y--;
			if(str[0] == 'C'){
				for(j=x; j<y+1; j++){
					switch (vet[j]){
									case 0:
										H++;
										break;
									case 1:
										E++;
										break;
									case 2:
										R++;
										break;
					}
				}
				printf("%d %d %d\n",H,E,R);
			//	cout<<H<<" "<<E<<" "<<R<<endl;
				H=0;
				E=0;
				R=0;
			}
			else{
				for(j=x; j<y+1; j++){
				if((vet[j]+1)>2){
					vet[j] = 0;
				}
				else
					vet[j]++;
				}
			}
        }
        printf("\n");
	}
	return 0;
}

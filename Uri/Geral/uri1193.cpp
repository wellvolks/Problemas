#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
 
unsigned int pot[64];
 
void processa(){
    pot[0] = 1;
	int i;
    for(i = 0; i < 32; i++) pot[i+1] = (pot[i] << 1);
}

char ans[100000];
  
void bin(unsigned int  valor){
    register unsigned int  aux = 0, p = 0, s, i, q = 0;
    while(valor > 0){
        aux = (valor & 1);
        ans[q++] = ((aux == 1) ? '1' : '0');
        valor >>= 1;
    }
    for(i = q-1; i >= 0; i--) putchar(ans[i]);
    puts(" bin");
}
 
int dec(char str[]){
    register unsigned int  ret = 0, p = 0;
   register  int i = 0;
    for( i = strlen(str)-1; i >= 0; p++, i--){
        if( str[i] == '1' ) ret += pot[p];
    }
    return ret;
}
 
int hexa(char *str){
    register unsigned int  ans = 0;
    sscanf(str, "%x", &ans);
    return ans;
}
char in[10000];
char *p1, *p2;

void solve(int c){
	printf("Case %d:\n", c++);
	if(p2[0] == 'b'){
		register unsigned int  ans = dec(p1);
		printf("%d dec\n%x hex\n",ans,ans);
	}
	else if(p2[0] == 'd'){
		register unsigned int  ans;
		sscanf(p1, "%d", &ans);
		printf("%x hex\n",ans);
		bin(ans);
	}
	else{
		register unsigned int ans;
		sscanf(p1, "%x", &ans);
		printf("%d dec\n",ans);
		bin(ans);
	}
	printf("\n");
}

int main(){
    register int t, c = 1;
    processa();
    scanf("%d",&t);
    getchar();
    while(t--){
        gets(in);
        p1 = strtok(in, " ");
        p2 = strtok(NULL, " ");
		solve(c);
    }
    return 0;
}
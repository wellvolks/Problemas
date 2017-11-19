#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
char str[10000];
int v[300];
int main(){
	int t;
	int qt = 0;
	v['0'] = 6, v['1'] = 2, v['2'] = 5, v['3'] = 5, v['4'] = 4, 
	v['5'] = 5, v['6'] = 6, v['7'] = 3, v['8'] = 7, v['9'] = 6;
	scanf("%d",&t);
	while(t--){
		scanf(" %s",&str);
		for(int i = 0; i < strlen(str); i++) qt += v[str[i]];
		printf("%d leds\n",qt);
		qt = 0;
	}
	return 0;
}
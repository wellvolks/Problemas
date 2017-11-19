#include <math.h>
#include <stdio.h>
#include <stdlib.h>
 
const double pi = acos(-1.0);
const double EPS = 1e-9;
 
int cmp(double a, double b = 0.0){
    if(fabs(a-b) < EPS) return 0;
    return a > b ? 1 : -1;
}
 
int main(){
    double valor;
    char str[10000];
	//printf("%.*lf\n",((fabs(d) - abs((int)d) > EPS))?1:0,d);
    for(int i = 0; i < 100; i++){
        scanf("%lf",&valor);
        if(valor <= 10.000){
            printf("A[%d] = %.*lf\n", i, ((fabs(valor) - abs((int)valor) > EPS))?1:0,valor);
            //else printf("A[%d] = %.1lf\n", i, valor);
        }
		//break;
    }
    return 0;
}

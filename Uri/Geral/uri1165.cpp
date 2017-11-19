#include <stdio.h>
main()
{
   int N,num, total,j, i;

   scanf("%d",&N);
 

   for(i=1;i<=N;i++)
   {
     total=0;
     scanf("%d",&num);
    for(j=1;j<=num;j++)
      {
        if(num%j==0)
        {
          total++;
		  if( total > 2 ) break;
        }
     }
     if(total==2){printf("%d eh primo\n",num);}
      
     else{ printf("%d nao eh primo\n",num);}
   }
}
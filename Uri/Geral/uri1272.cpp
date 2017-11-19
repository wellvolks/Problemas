#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
//Crescimento Populacional 1160
int main() {
   
   int n;
   cin >> n;
   
   for(int i=0; i<n; i++){
      double taxaA,taxaB;
      int j,popul_a,popul_b;
      cin >> popul_a >> popul_b >> taxaA >> taxaB;
      
      for(j=0 ; popul_a<popul_b; j++){
         popul_a = (taxaA/100*popul_a)+popul_a;
         popul_b = (taxaB/100*popul_b)+popul_b;
      }
      
      if(j<=100)
         cout << j << " anos." << endl;
      else
         cout << "Mais de 1 seculo." << endl;
   }


   return 0;
} 

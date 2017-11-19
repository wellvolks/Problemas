#include <iostream>
#include <string>
 #include <vector>
using namespace std;
 
int main(){        
	int t, j, cr[100], flag, soma, cont, ult;
	string p;
	vector < string > pos;
	while(cin >> t){
		j = 0;
		cont = 0;
		pos.resize(t+10);
		for(int i = 0; i < t; i ++){ cr[j] = 0; pos[i] = ""; }
		while(t--){
			cin >> p;
			flag = -1;
			soma = 0;
			if(j == 0){
				cr[j] = 1;
				pos[j] += p;
				j++;
			}else{	
				for(int i = 0; i < j; i++){
					if(!p.compare(pos[i])){
						flag = i;
					}
					else soma += cr[i];
				}
				if(flag == -1){
					pos[j] += p;
					flag = j;
					cr[flag] = 0;
					j++;
				}
				else if( cr[flag] > soma ) cont++;         
				cr[flag]++;
			}		
		}
		cout << cont << "\n";
	}
	return 0;    
}
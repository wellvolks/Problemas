#include <iostream>
#include <string>
 
using namespace std;
 
int main(){
    //ios::sync_with_stdio(false);
 
        int t, j, y;
        cin >> t;
        string frase, pal, fro;
        
        while(t--){
                frase = " ";
                fro = "";
                
                cin >> pal;
                cin.ignore();
                getline(cin, frase);
                y = 0;
                for(int i = 0; i < frase.size(); i ++){
                        if(frase[i] >= 65 && frase[i] <= 90){
                                fro += frase[i];
                                y++;
                        }
                }
                j = 0;
                for(int i = 0; i < y; i++){
        
                        if(fro[i] + (pal[j] - 65) <= 90){
                                fro[i] = (pal[j] - 65) + fro[i];
                        }else{
                                fro[i] = ((pal[j] - 65) - (90 - fro[i])) + 64;
                                if(fro[i] > 90){
                                        fro[i] = (fro[i] - 90) + 65;
                                }
                        }
                        j ++;
                        if(j == pal.size()) j = 0;
                }
                
                for(int i = 0; i < y; i++){
                        cout << fro[i];
                }
                cout << "\n";
        }
 
        return 0;
}
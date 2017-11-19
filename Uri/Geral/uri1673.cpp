#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    
    string str;
    while( getline(cin, str) ){
    	string aux = "";
    	int cnt = 0;
    	for( int i = 0; i < str.size(); i++ ){
    		int tam = aux.size();
    		if( tam == 0 ){ aux += str[i]; cnt = 1; }
    		else if( aux[tam-1] == str[i] && cnt != 9){
    			if( cnt == 1 ){
    				if( aux.size() > 1 ){ aux.erase(aux.begin()+tam-1); cout << "1" << aux << "1"; aux = ""; aux += str[i]; }
    			}
    			cnt++;
    		}
    		else if( cnt > 1 || cnt == 9){
    			cout << cnt << aux;
    			aux = ""; aux += str[i];
    			cnt = 1;
    		}
    		else{
    			if( aux[tam-1] == '1') aux += '1';
    			aux += str[i];
    		}
    		if( i+1 == str.size() ){
    			if( cnt > 1 ) cout << cnt << aux;
    			else if( cnt == 1 ){
    				if( aux[aux.size()-1] == '1' ) cout << "1" << aux << "11";
    				else cout << "1" << aux << "1";
    			}
    		}
    	}
    	cout << "\n";
    }
  	return 0;
}
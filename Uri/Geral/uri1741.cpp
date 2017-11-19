#include <bits/stdc++.h>
#define INF 4294967297LL 
#define LINF 0x3F3F3F3FFFFFFFFFLL 
   
using namespace std;
   
typedef long long int64; 
typedef unsigned long long uint64; 
   
string str;
int ans;
 
bool checkSintaxe(){
    int tam = str.size();
    stack < int64 > pilha;
    for( int i = 0; i < tam; i++ ){
        if( isdigit(str[i]) ){
            if( pilha.empty() && tam > 1 ) return false;
            pilha.push(str[i]-'0');
            if( pilha.size() > 2 ){
                while( pilha.size() > 2 ){
                    int64 a = pilha.top();
                    pilha.pop();
                    int64 b = pilha.top();
                    pilha.pop();
                    int64 c = pilha.top();
                    pilha.pop();
                    if( a > INF || b > INF || c < INF ){
                        pilha.push(c);
                        pilha.push(b);
                        pilha.push(a);
                        break;
                    }
                    pilha.push(1);
                }
            }
        }
        else pilha.push(INF + int64(str[i]));
    }
    if( pilha.size() != 1 ) return false;
    return true;
}
 
int solve(){
    int tam = str.size();
    stack < int64 > pilha;
    for( int i = 0; i < tam; i++ ){
        if( isdigit(str[i]) ){
            pilha.push(str[i]-'0');
            if( pilha.size() > 2 ){
                while( pilha.size() > 2 ){
                    int64 a = pilha.top();
                    pilha.pop();
                    int64 b = pilha.top();
                    pilha.pop();
                    int64 c = pilha.top();
                    pilha.pop();
                    if( a > INF || b > INF || c < INF ){
                        pilha.push(c);
                        pilha.push(b);
                        pilha.push(a);
                        break;
                    }
                    c -= INF;
                    int64 tot = 0;
                    if( c == '*' ) tot = a * b;
                    else if( c == '+' ) tot = a + b;
                    else if( c == '-' ) tot = a - b;
                    else if( c == '/' ){
                        if( b == 0LL ){ ans = 2; return 0; }
                        tot = a/b;
                    }
                    pilha.push(tot);
                }
            }
        }
        else pilha.push(INF + int64(str[i]));
    }
    return pilha.top();
}
  
int main(){
    ios::sync_with_stdio(false);
    string aux;
    while( getline(cin, aux) ){
        int tam = aux.size();
        str = "";
        for( int i = 0; i < tam; i++ ) if( aux[i] != ' ' ) str += (aux[i]);
        if( str == "" || !checkSintaxe() ) cout << "Invalid expression.\n";
        else{
            ans = 0;
            int64 ret = solve();
            if( ans == 2 ) cout << "Division by zero.\n";
            else cout << "The answer is " << ret << ".\n"; 
        }
    }
    return 0;
}
#include <bits/stdc++.h>
#include <tr1/unordered_map>

using namespace std;
using namespace tr1;


#ifdef _WIN32  
    #define getchar_unlocked getchar 
    #define putchar_unlocked putchar 
#endif 
   
bool read( int &n ) { 
    n = 0; 
    register bool neg = false; 
    register char c = getchar_unlocked(); 
    if( c == EOF) { n = -1; return false; } 
    while (!('0' <= c && c <= '9')) { 
        if( c == '-' ) neg = true; 
        c = getchar_unlocked(); 
    } 
    while ('0' <= c && c <= '9') { 
        n = n * 10 + c - '0'; 
        c = getchar_unlocked(); 
    } 
    n = (neg ? (-n) : (n)); 
    return true;
} 
   
inline void writeInt(int n){ 
    register int idx = 30; 
    char out[31]; 
    out[30] = ' '; 
    do{ 
        idx--; 
        out[idx] = n % 10 + '0'; 
        n/= 10; 
    }while(n); 
    do{ putchar_unlocked(out[idx++]); } while (out[idx] != ' '); 
} 

int n, m;

int main(){
	ios::sync_with_stdio(false);
	int t;
    cin >> t;
    while( t-- ){
        n = 0;
        int ini, fim;
        string de, para;
        unordered_map < string, int > mapa;
        cin >> m;
        for( int i = 0; i < m; i++ ){
            cin >> de >> para >> ini >> fim;
            if( (ini >= 18 && (ini+him) <= 30) || (ini+fim) <= 6 ){
                int lo, hi;
                if( mapa.count(de) ) lo = mapa[de];
                else{ mapa[de] = n; lo = n++; }
                if( mapa.count(para) ) hi = mapa[para];
                else{ mapa[para] = n; para = n++; }
                grafo[de].push_back(tri(para,))      
            }
        }
    }
	return 0;
}
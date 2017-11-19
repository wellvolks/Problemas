#include <bits/stdc++.h>

using namespace std;

#ifdef _WIN32  
    #define getchar_unlocked getchar 
    #define putchar_unlocked putchar 
#endif 
  
inline bool read( int &n ) {
    n = 0;
    register bool neg = false;
    register char c = getchar_unlocked();
    if( c == EOF) { n = -1; return false; }
    while (!('0' <= c && c <= '9')) {
        if( c == '-' ) neg = true;
        c = getchar_unlocked();
        if( c == EOF ) return false;
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
    if( n < 0 ) putchar_unlocked('-'); 
    char out[31]; 
    out[30] = ' '; 
    do{ 
        idx--; 
        out[idx] = n % 10 + '0'; 
        n/= 10; 
    }while(n); 
    do{ putchar_unlocked(out[idx++]); } while (out[idx] != ' '); 
}

void writeString( string str ){
    for(int i = 0; i < str.size(); i++) putchar_unlocked(str[i]);
}

int main(){
    ios::sync_with_stdio(false);
    int n, k = 1, w;
    while(read(n)){
        writeString("Caso ");
        writeInt(k++);
        writeString(": ");
        w = ((n*(n+1))/2)+1;
        writeInt(w);
        writeString(" numero");
    	
        writeString(((w>1) ? ("s\n") : ("\n")));
    	writeInt(0);

        for( int i = 1; i <= n; i++){
    		for( int j = 0; j < i; j++ ){
                putchar_unlocked(' ');
                writeInt(i);
    		}
    	}
        writeString("\n\n");
    }

    return 0;
}
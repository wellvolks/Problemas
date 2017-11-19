#include <bits/stdc++.h>
  
using namespace std;
  
typedef long long int64;
typedef unsigned long long uint64;

#ifdef _WIN32
    #define getchar_unlocked getchar
    #define putchar_unlocked putchar
#endif
   
   
bool read( int &n ) {
    n = 0LL;
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
    register int idx = 20;
    if( n < 0 ) putchar_unlocked('-');
    n = abs(n);
    char out[21];
    out[20] = ' ';
    do{
        idx--;
        out[idx] = n % 10 + '0';
        n/= 10;
    }while(n);
    do{ putchar_unlocked(out[idx++]); } while (out[idx] != ' ');
}

int main(){
    //ios::sync_with_stdio(false);
    int at;
    int64 a, b;
    string str;
    while( getline(cin,str) ){
    	char *p = strtok((char*)str.data()," ");
    	sscanf(p,"%llu",&a);
    	at = 1;
    	p = strtok(NULL," ");
    	if( p != NULL ){
    		at++;
    		sscanf(p,"%llu",&b);
    	}
    	int64 ans = 0LL, f = 0;
    	if( at == 1 ){
    		for( int64 i = 1; i <= sqrt(a)+2LL; i++ ){
    			int64 j = labs(a - (i*i));
    			if( (int64(sqrt(j)) * int64(sqrt(j))) == j && j >= 1 ){
					cout << max(i,int64(sqrt(j))) << " " << min(i,int64(sqrt(j))) << '\n';
					f = 1;
					break;
    			}
    		}
    		if( !f ) cout << ((a & 1LL) ? ("Spinster Number.\n") : ("Bachelor Number.\n"));
    	}
    	else{
    		for( int64 i = 1; i <= sqrt(b)+2LL; i++ ){
    			int64 j = labs(b - (i*i));
    			if( (int64(sqrt(j)) * int64(sqrt(j))) == j && j >= 1 ) ans++;
    			//if( i <a ){
    			//	j = labs(a - (i*i));
    			//	if((int64(sqrt(j)) * int64(sqrt(j))) == j && j >= 1 ) ans--;
    			//}
    		}
    		cout << ans << '\n';	
    	}
    }
    return 0;
}
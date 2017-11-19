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

string str, in;
char fita[3000010];
int used[3000010], vis = 1;
int cabeca, pos, entrada;

bool solve( ){
    int lo = 0;
    if( pos >= in.size() ) return true;
    switch ( in[pos] ){
        case '>': cabeca++; cabeca = min(cabeca,30000-1);if(used[cabeca] == vis) return true; pos++; return solve(); break;
        case '<': cabeca--; cabeca = max(cabeca,0); if(used[cabeca] == vis) return true; pos++; return solve(); break;
        case '-': fita[cabeca]--; if(fita[cabeca]<=0) used[cabeca] = vis; if(used[cabeca] == vis) return true; pos++; return solve(); break;
        case '+': fita[cabeca]++; if(fita[cabeca]==0) used[cabeca] = vis; if(used[cabeca] == vis) return true; pos++; return solve(); break;
        case '.': cout << fita[cabeca]; pos++; if(used[cabeca] == vis) return true; return solve(); break;
        case ',': 
            if( entrada < str.size() ){
                fita[cabeca] = str[entrada];
                pos++;
                entrada++;
                if(used[cabeca] == vis) return true; 
                return solve();
            }
            else{
                fita[cabeca] = 0;
                used[cabeca] = vis;
                pos++;
                if(used[cabeca] == vis) return true; 
                return solve();
            }
        break;
        case '[': 
            lo = pos;
            pos++;
   			while( !solve() ) pos = lo+1;
            for( ; in[pos] != ']'; pos++);
            pos++;
            return solve();
        break;
        case ']':
            return false;
        break;
        default:
            pos++;
            if(used[cabeca] == vis) return true; 
            return solve();
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    int t, k = 1;
    //read(t);
    cin >> t;
    cin.ignore();
    while( t-- ){
        cin.ignore();
        getline(cin, str);
        getline(cin, in);
        cout << "Instancia " << k++ << '\n';
        pos = cabeca = entrada = 0;
        memset(fita,0,sizeof(fita));
        if(in[0] == '+'){
        	solve();
    	}
        vis++;
        cout << "\n\n";
    }
    return 0;
}
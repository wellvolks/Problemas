#include <bits/stdc++.h>

using namespace std;

#ifdef _WIN32  
    #define getchar_unlocked getchar 
    #define putchar_unlocked putchar 
#endif 
   
inline void read( int &n ) { 
    n = 0; 
    register bool neg = false; 
    register char c = getchar_unlocked(); 
    if( c == EOF) { n = -1; return; } 
    while (!('0' <= c && c <= '9')) { 
        if( c == '-' ) neg = true; 
        c = getchar_unlocked(); 
    } 
    while ('0' <= c && c <= '9') { 
        n = n * 10 + c - '0'; 
        c = getchar_unlocked(); 
    } 
    n = (neg ? (-n) : (n)); 
} 
   
inline void writeInt(int n){ 
    register int idx = 20; 
    char out[21]; 
    out[20] = ' '; 
    do{ 
        idx--; 
        out[idx] = n % 10 + '0'; 
        n/= 10; 
    }while(n); 
    do{ putchar_unlocked(out[idx++]); } while (out[idx] != ' '); 
} 

void writeString( string at ){
	int t = at.size();
	for( int i = 0; i < t; i++ ) putchar_unlocked(at[i]);
}

bool ehVogal[300];

int main(){
	ios::sync_with_stdio(false);
	int t, q, op, x, k = 1;
	read(t);
	ehVogal['a'] = ehVogal['e'] = ehVogal['u'] =
	ehVogal['i'] = ehVogal['o'] = true;
	string vg = "", cs = "";
	
	while( t-- ){
		char c;
		int vog = 0, cons = 0, tot = 0;
		string str = "";
		c = getchar_unlocked();
		vg = cs = "";
		while( c != '\n' ){
			str += c;
			if( ehVogal[c] ) vg += c; 
			else cs += c;
			tot++;
			c = getchar_unlocked();
		}
		read(q);
		writeString("Caso #");
		writeInt(k); k++;
		writeString(":\n");
		int mg = vg.size();
		int mc = cs.size();
		while(q--){
			read(op);
			switch( op ){
				case 0: read(x); vog += x; break;
				case 1: read(x); cons += x; break;
				case 2:
					int a = 0, b = 0;
					string nvg = "", nvc = "";
					for( int i = 0; i < tot; i++ ){
						if( ehVogal[str[i]] ){
							vog %= mg;
							str[i] = vg[((a-vog)+mg) % mg];
							a++;
							nvg += str[i];
						}
						else{
							cons %= cs.size();
							str[i] = cs[((b-cons)+mc) % mc];
							b++;
							nvc += str[i];
						}
					}
					vog = cons = 0;
					vg = nvg;
					cs = nvc;
					writeString(str);
					putchar_unlocked('\n');
				break;
			}
		}
	}
	return 0;
}
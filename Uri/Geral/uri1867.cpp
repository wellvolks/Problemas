#include <bits/stdc++.h>

using namespace std;
 
#ifdef _WIN32 
    #define getchar_unlocked getchar
#endif

inline bool read( int &n ) {
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

int getVal(string a){
	while(a.size() > 1){
		int novo = 0;
		for( int i = 0, sz = a.size(); i < sz; i++ ){
			novo += a[i] - '0';
		}
		char str[100];
		sprintf(str, "%d", novo);
		a = "";
		a += str;
	}
	return a[0]-'0';
}

int main(){
	ios::sync_with_stdio(false);
	string a, b;
	while( cin >> a >> b && !(a == "0" && b == "0") ){
		int vala = getVal(a);
		int valb = getVal(b);
		if( vala > valb ) cout << "1\n";
		else if( vala < valb ) cout << "2\n";
		else cout << "0\n";
	}
	return 0;
}
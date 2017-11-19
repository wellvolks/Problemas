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

int main(){
	ios::sync_with_stdio(false);
	int t, l, k = 1;
	string nome;
	double bs, iv, ev;
	string at[] = {"HP","AT","DF","SP"};
	cin >> t;
	while( t-- ){
		cin >> nome >> l;
		cout << "Caso #" << k++ << ": " << nome << " nivel " << l << "\n";
		for( int i = 0; i < 4; i++ ){
			cin >> bs >> iv >> ev;
			int tot = (((iv + bs + sqrt(ev)/8. + ((!i)?(50.):(0.)))*l)/50.) + (5.+((!i)?(5.):(0.)));
			cout << at[i] << ": " << (int)tot << "\n";
		}
	}

	return 0;
}
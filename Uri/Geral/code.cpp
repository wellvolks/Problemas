#include <bits/stdc++.h> 
 
typedef long long int64;
typedef unsigned long long uint64;
 
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

int n;
int vet1[100002], vet2[100002];
vector < pair < int, int > > sum;

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
    int t;
    read(t);
    while( t-- ){
        read(n);
        sum.resize(n-2);
        for( int i = 0; i < n-2; i++ ){
            read(vet1[i]);
            sum[vet1[i]].first++;
            sum[vet1[i]].second = vet1[i];
        }
        for( int i = 0; i < n-2; i++ ){
            read(vet2[i]);
            sum[vet2[i]].first++;
            sum[vet2[i]].second = vet2[i];
        }
        sort(sum.begin(), sum.end());
        pair < int, int > p1 = sum[0];
        pair < int, int > p2 = sum.back();
        bool ok1 = false, ok2 = false;
        for( int i = 1; i < sum.size()-1; i++ ){
            if( sum[i].second == n ) ok1 = true;
            if( sum[i].second == n-1 ) ok2 = true;
        }
        if( ok1 && ok2 ){
            cout << "none\n";
            cout << p2.second << " " << n << '\n';
            cout << p2.second << " " << n-1 << '\n'; 
        }
        else if( ok1 ){
            if( p1.second == n-1 ){
                cout << "one\n";
                cout << p2.second << " " << n << '\n';
                cout << p2.second << " " << n-1 << '\n';
            }
        }
        else if( ok2 ){

        }
        else{

        }
    }    
	return 0;
}
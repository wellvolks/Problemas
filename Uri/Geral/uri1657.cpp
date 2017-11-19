#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef unsigned long long uint64;
 
 
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

int n, q;

map < string, int > mapa;
vector < string > vet;

int check1(string str){
    int ans = 1e9;
    for( int i = 0, sz = str.size(); i < sz; i++ ){
        for( char j = 'a'; j <= 'z'; j++ ){
            str.insert(str.begin()+i,j);
            if( mapa.count(str) ) ans = min(ans, mapa[str]);
            str.erase(str.begin()+i);
            if( i+1 == sz ){
                str += j;
                if( mapa.count(str) ) ans = min(ans, mapa[str]);
                str.pop_back();
            }
        }
        char bkp = str[i];
        str.erase(str.begin()+i);
        if( mapa.count(str) ) ans = min(ans, mapa[str]);
        str.insert(str.begin()+i, bkp);
    }
    return ans;
}

int check2(string str){
    int ans = 1e9;
    for( int i = 0, sz = str.size(); i < sz; i++ ){
        for( char j = 'a'; j <= 'z'; j++ ){
            char bkp = str[i];
            str[i] = j;
            if( mapa.count(str) ) ans = min(ans, mapa[str]);
            str[i] = bkp;
        }
    }
    return ans;
}

int check3(string str){
    int ans = 1e9;
    for( int i = 0, sz = str.size(); i < sz-1; i++ ){
        swap(str[i],str[i+1]);
        if( mapa.count(str) ) ans = min(ans, mapa[str]);
        swap(str[i],str[i+1]);
    }
    return ans;
}

int solve(string str, string &ans){
    if( mapa.count(str) ){
        ans = str;
        return 1;
    }
    int pos1 = check1(str);
    int pos2 = check2(str);
    int pos3 = check3(str);
    int resp = min(pos1, min(pos2,pos3));
    if( resp < 1e9 ){ ans = vet[resp]; return 2; }
    return 3;
}

int main(){
    ios::sync_with_stdio(false);
    string str;

    cin >> n;
    for( int i = 0; i < n; i++ ){
        cin >> str;
        if( !mapa.count(str) ) mapa[str] = i;
        vet.push_back(str);
    }

    cin >> q;
    for( int i = 0; i < q; i++ ){
        cin >> str;
        string ans = "";
        switch(solve(str,ans)){
            case 1: cout << str << " is correct\n"; break;
            case 2: cout << str << " is a misspelling of " << ans << "\n"; break;
            case 3: cout << str << " is unknown\n"; break;
        }
    }

    return 0;
}

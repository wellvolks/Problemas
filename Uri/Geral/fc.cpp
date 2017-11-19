#include <bits/stdc++.h>

using namespace std;
#define MAXD 5500000

typedef long long int64;
typedef unsigned long long uint64;


int main(){
    vector < char > vet;
    int l, n, a, b, lo, hi, op, ans;
    char c;
    string str;

    cin >> l >> n;
    cin >> str;

    for(int i = 0; i < l; i++){
        vet.push_back(str[i]);
    }

    while( n-- ){
        cin >> op;
        switch(op){
            case 1:
                cin >> a >> b >> c;
                if( b < a ) swap(a,b);
                
                ans = 0;
                while( a <= b ){
                    if( vet[a-1] == c ) ans++;
                    a++;
                }

                cout << ans << '\n';
            break;
            case 2:
                cin >> a >> b >> c;
                if( b < a ) swap(a,b);
                
                lo = 1e9;
                hi = -1e9;
                while( a <= b ){
                    if( vet[a-1] == c ){
                        lo = min(lo, a);
                        hi = max(hi, a);
                    }
                    a++;
                }

                if( hi < 0 ) cout << "-1" << endl;
                else cout << lo << " " << hi << endl;
            break;
            case 3:
                cin >> a >> b;
                if( b < a ) swap(a,b);

                while( a <= b ){
                    swap(vet[a-1],vet[b-1]);
                    a++;
                    b--;
                }
            break;
            case 4:
                cin >> a >> c;

                vet.insert(vet.begin()+a-1, c);
                l++;
            break;
        }
    }

    str = "";
    for(int i = 0; i < l; i++) str += char(vet[i]);
    cout << str << endl;
    return 0;
}

#include <bits/stdc++.h>
#include <tr1/unordered_map>

using namespace std;
using namespace tr1;

typedef long long int64;
typedef unsigned long long uint64;

string str;

vector < vector < int > > pos;

int main(){
    ios::sync_with_stdio(false);
    int t, q;
    cin >> t;
    string resp[] = {"No","Yes"};
    while( t-- ){
        cin >> str;
        pos.resize(100);
        int tam = str.size();
        vector < int > :: iterator it;
        for( int i = 0; i < tam; i++ ){
            if( str[i] > 'Z' ) pos[(str[i]-'a')+26].push_back(i);
            else pos[str[i]-'A'].push_back(i);
        }
        cin >> q;
        while( q-- ){
            cin >> str;
            tam = str.size();
            int at = -1;
            bool ans = true;
            for( int i = 0; i < tam; i++ ){
                int r = ((str[i] > 'Z') ? ('a') : ('A'));
                int s = ((str[i] > 'Z') ? (26) : (0));
                it = upper_bound(pos[(str[i]-r)+s].begin(), pos[(str[i]-r)+s].end(), at);
                if( it == pos[(str[i]-r)+s].end() ){
                    ans = false;
                    break;
                }
                else at = *it;
            }
            cout << resp[ans] << '\n';
        }
        pos.clear();
    }
    return 0;
}
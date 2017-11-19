#include <bits/stdc++.h>

typedef long long int64;

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

int64 tree[4*1000000];
int64 vet[1000000];
vector < pair < int, int > > ranges;

int64 getVal( int64 lo, int64 hi, int64 val ){
    int64 a = val*((hi-lo)+1LL);
    int64 r = min((hi-lo)+1LL, val);
    int64 p = val + (r-1)*(-1LL);
    return ((val + p)*r)>>1LL;
}

void build(int no, int lo, int hi){
    if( lo == hi ){
        //cout << ranges[lo-1].first << " " << ranges[lo-1].second << endl;
        tree[no] = getVal(ranges[lo-1].first, ranges[lo-1].second, vet[ranges[lo-1].first]);
        return;
    }
 
    int mid = (lo + hi) >> 1;
    int x = (mid<<1) + 1;
    int y = x + 1;
 
    build(x, lo, mid);
    build(y, mid+1, hi);
    
    tree[no] = max(tree[x], tree[y]);
}
 
int64 query( int no, int lo, int hi, int a, int b ){
    if( lo >= a && hi <= b ){
        return tree[no];
    }
 
    int mid = (lo + hi) >> 1;
    int x = (mid<<1) + 1;
    int y = x + 1;
    int64 ans1 = 0, ans2 = 0;
 
    if( mid >= a ) ans1 = query(x, lo, mid, a, b);
    if( mid+1 <= b ) ans2 = query(y, mid+1, hi, a, b);
 
    return max(ans1, ans2);
}

int idx[1000000];

int main(){
    ios::sync_with_stdio(false);

    int n, q, a, b;
    cin >> n >> q;

    
    int lo = 0, hi = 0;

    for(int i = 0; i < n; i++){
        cin >> vet[i];
        if( i == 0 || vet[i] == vet[i-1] ){
            hi = i;
            idx[i] = ranges.size();
        }
        else{
            ranges.push_back({lo, hi});
            lo = hi = i;
            idx[i] = ranges.size();
        }
    }

    ranges.push_back({lo, hi});

    build(0, 1, ranges.size());
    cout << getVal(2, 3, 2) << endl;
    exit(0);
    while( q-- ){
        cin >> a >> b;
        a--;
        b--;

        int64 ans = 0;
        
        int lo = idx[a];
        int hi = idx[b];

        if( lo == hi ){
            ans = getVal(lo, hi, vet[a]);
        }
        else{
            ans = getVal(a, ranges[lo].second, vet[a]);
            lo++;

            if( lo == hi ){
                ans = getVal(ranges[lo].first, b, vet[ranges[lo].first]);
            }
            else{
                ans = getVal(ranges[hi].first, b, vet[ranges[hi].first]);
                ans = max(ans, query(0, 1, ranges.size(), ranges[lo].first+1, ranges[hi-1].second+1));
            }
        }

        cout << ans << '\n';

    }

    return 0;
 }
#include <set>
#include <map>
#include <list>
#include <stack>
#include <cmath>
#include <queue>
#include <ctime>
#include <cfloat>
#include <vector>
#include <string>
#include <cstdio>
#include <bitset>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <iomanip>
#include <sstream>
#include <utility>
#include <iostream>
#include <algorithm>
  
using namespace std;
 
struct pt{
    long long x, y;
    pt( long long x = 0, long long y = 0 ) : x(x), y(y) { }
};
 
struct ident{
    pt resp;
    int id;
};
 
struct seg{
    pt p1, p2;
};
 
seg vet[1000010];
 
ident ans[1000010];
 
 #ifdef _WIN32 
    #define getchar_unlocked getchar
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
 
long long cross( pt a, pt b, pt c ){
    long long dx1 = a.x - b.x, dy1 = a.y - b.y;
    long long dx2 = c.x - b.x, dy2 = c.y - b.y;
    return (dx1 * dy2 - dx2 * dy1);
}
 
bool comp( int a, int b ){
    seg sa = vet[a], sb = vet[b];
    if( sa.p1.x >= sb.p1.x ) return (cross(sb.p1,sa.p1,sb.p2) < 0);
    return (cross(sa.p1,sb.p1,sa.p2) > 0);
}
 
bool compara( pair <int, int > const &a , pair <int, int > const &b ){
    if( a.first != b.first ) return  (a.first < b.first);
    if( a.second > 0 && b.second > 0 ) return comp( a.second, b.second);
    return ( a.second > b.second );
}
 
set < int, bool(*)(int, int) > lines (comp);
vector < pair <int, int> > events;
 
int findX(int id, int x){
    if( vet[id].p1.y > vet[id].p2.y ) return vet[id].p1.x;
    else if( vet[id].p2.y > vet[id].p1.y ) return vet[id].p2.x;
    return x;
}
 
int segUp( int id ){
    if( vet[id].p1.y == vet[id].p2.y ) return -1;
    set < int, bool(*)(int,int) > :: iterator it;
    it = lines.find(id);
    it++;
    if( it == lines.end() ) return -1;
    return *it;
} 
 
 
int grafo[1000010];
 
void lineSweep( int n ){
    set < int, bool(*)(int,int) > :: iterator it;
    for( int i = 0; i < n; i++ ){
        int xAnt = events[i].first;
        for( int k = i; k < n; i = k++ ){
            if( events[k].first != xAnt ) break;
            if( events[k].second != 0 ){
                int id = abs(events[k].second)-1;
                if( events[k].second < 0 ){ 
                    if( vet[id].p2.y >= vet[id].p1.y ){
                        if( lines.empty() ) grafo[id] = -1;
                        else grafo[id] = segUp(id);
                    }
                    lines.erase(id); 
                }
                else{
                    lines.insert(events[k].second-1);
                    if( vet[id].p1.y >= vet[id].p2.y ) grafo[id] = segUp(id);
                }
            }
            else{
                if( lines.empty() )  ans[events[k].first].id = -1;
                else ans[events[k].first].id =  *lines.begin();
            }
        }
    }
}
 
pt solve(int id, int atx){
    if( id == -1 ) return pt(atx,-1);
    pt aux = pt(findX( id, atx ), ((vet[id].p1.y == vet[id].p2.y) ? (vet[id].p1.y) : (-1)));
    int p = grafo[id];
    while( p != -1 ){
        if( vet[p].p1.y == vet[p].p2.y ) return pt(aux.x, vet[p].p1.y);
        aux.x = findX( p, aux.x );
        aux.y = max( vet[p].p1.y, vet[p].p2.y );
        if( grafo[p] == -1 && (vet[p].p1.y != vet[p].p2.y)) aux.y = -1;
        p = grafo[p];
    }
    return aux;
}
 
 
int main(){
    //ios::sync_with_stdio(false);
    int n, c, p, p1x, p1y, p2x, p2y;
    seg in;
    vector < int > cons;
     
    while( true ){
        read(n);
        if( n == -1 ) break;
        read(c);
        for( int i = 0; i < n; i++ ){
            read(p1x); read(p1y); read(p2x); read(p2y);
            in.p1.x = p1x, in.p1.y = p1y, in.p2.x = p2x, in.p2.y = p2y;
            if( in.p1.x <= in.p2.x ) vet[i] = in;
            else{
                vet[i].p1 = in.p2;
                vet[i].p2 = in.p1;
            }
            events.push_back(make_pair<int,int> (vet[i].p1.x,(i+1)));
            events.push_back(make_pair<int,int> (vet[i].p2.x,-(i+1)));
        }
 
        for( int i = 0; i < c; i++ ){
            read(p);
            cons.push_back(p);
            events.push_back(make_pair((int)p, 0) );
        }
         
        sort(events.begin(), events.end(), compara);
        lineSweep( events.size() );
         
        for( int i = 0; i < c; i++ ){
            ans[cons[i]].resp = solve(ans[cons[i]].id, cons[i]);
            printf("%lld",ans[cons[i]].resp.x);
            if( ans[cons[i]].resp.y != -1 ) printf(" %lld",ans[cons[i]].resp.y);
            puts("");
        }
         
        lines.clear();
        cons.clear();
        events.clear();
    }
    return 0;
}
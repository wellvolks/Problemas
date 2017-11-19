#include <set>
#include <tr1/unordered_set>
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
using namespace tr1; 
  
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define RFOR(i, b, a) for(int i = b; i >= a; --i)
#define REP(i, N) for(int i = 0; i < N; ++i)
#define RREP(i, N) for(int i = N-1; i >= 0; --i)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )
#define MAXN 10010
#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3FFFFFFFFFLL
#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) __typeof((X).begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) int((V).size())
#define pb push_back
#define mp make_pair
  
  
struct tri{
    int atual, custo;
    tri ( int atual = 0, int custo = 0) : atual(atual), custo(custo) { }
};
  
struct aresta{
    int atual;
    string str;
    aresta( int atual = 0, string str = "" ) : atual(atual) , str(str) { }
};
  
typedef vector < int > vi;
typedef vector < vi > vii;
typedef vector < tri > vtri;
typedef vector < vtri > vvtri;
typedef long long int64;
typedef unsigned long long uint64;
  
int x[] = {-1,-1,-1, 0, 1, 1, 1, 0 };
int y[] = {-1, 0, 1, 1, 1, 0,-1,-1 };
  
#ifdef _WIN32 
    #define getchar_unlocked getchar
#endif
 
int n;

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

vector < vector < int > >  tree1, tree2;

void getCenter(vector<int>& c, const vector<vector<int> >& t, vector<int> d) {
    vector<bool> rem(n);
    int cnt = n;
    for(int rnd = 1; cnt > 2; ++rnd) {
        queue<int> q;
        REP(i, n) {
            if(!rem[i] && d[i] == 1) {
                q.push(i);
            }
        }
        
        while(!q.empty()) {
            int u = q.front(); q.pop();
            rem[u] = true;
            cnt--;
            int parent;
            REP(j, SIZE(t[u])){
                if(!rem[t[u][j]]) {
                    parent = t[u][j];
                    break;
                }
            }
            
            d[parent]--;
        }
    }
    
    REP(i, n) {
        if(!rem[i]) {
            c.pb(i);
        }
    }
}

void getLevels(map<int, set<int> >& lvls, const int& c, const vector<vector<int> >& t, vector<int>& nodeLvl) {
    vector<bool>vis(n);
    queue<pair<int, int> > q;
    
    q.push(mp(c, 0));
    vis[c] = true;
    
    while(!q.empty()) {
        int u = q.front().first, lvl = q.front().second; q.pop();
        lvls[-lvl].insert(u);
        nodeLvl[u] = lvl;
        REP(i, SIZE(t[u])) {
            int v = t[u][i];
            if(!vis[v]) {
                vis[v] = true;
                q.push(mp(v, lvl+1));
            }
        }
    }
}

void getLabels(const map<int, set<int> >& lvls, vector<int>& labels, const vector<vector<int> >& t, const vector<int>& nodeLvl, map<vector<int>, int>& id, int& lcnt){
    bool started = false;
    
    FORIT(it, lvls) {
        const set<int>& aux = it->second;
        if(!started) {
            FORIT(it2, aux) {
                vector<int> aux2;
                if(id.count(aux2)) {
                    labels[*it2] = id[aux2];
                } else {
                    id[aux2] = lcnt;
                    labels[*it2] = lcnt++;
                }
            }
            
            started = true;
        } else {
            FORIT(it2, aux) {
                int u = *it2;
                vector<int> aux2;
                REP(i, SIZE(t[u])) {
                    int v = t[u][i];
                    if(nodeLvl[v] > nodeLvl[u]) {
                        aux2.pb(labels[v]);
                    }
                }
                
                sort(aux2.begin(), aux2.end());
                
                if(id.count(aux2)) {
                    labels[u] = id[aux2];
                } else {
                    id[aux2] = lcnt;
                    labels[u] = lcnt++;
                }
            }
        }
    }
}

bool isIso(const int& c1, const int& c2, const vector<vector<int> >& t1, const vector<vector<int> >& t2) {
    map<vector<int>, int> id;
    int lcnt = 0;
    map<int, set<int> > lvls1, lvls2;
    vector<int> nodeLvl1(n), nodeLvl2(n);
    
    getLevels(lvls1, c1, t1, nodeLvl1);
    
    getLevels(lvls2, c2, t2, nodeLvl2);
    
    vector<int> labels1(n), labels2(n);
    
    getLabels(lvls1, labels1, t1, nodeLvl1, id, lcnt);
    getLabels(lvls2, labels2, t2, nodeLvl2, id, lcnt);
    
    return (labels1[c1] == labels2[c2]);
}

bool iso( const vector<vector<int> >& t1,  const vector<vector<int> >& t2,  const vector<int>& d1,  const vector<int>& d2) {
    vector<int> c1, c2;
    getCenter(c1, t1, d1);
    getCenter(c2, t2, d2);
    
    REP(i, SIZE(c1)) {
        REP(j, SIZE(c2)) {
            if(isIso(c1[i], c2[j], t1, t2)) {
                return true;
            }
        }
    }
    
    return false;
}

int main(){
	int i, x, y, k = 0;
	ios::sync_with_stdio(false);
	string ans = "";
	
	while( read(n) ){   
		tree1.resize(n); 
		tree2.resize(n);
		vector  < int > d1(n,0), d2(n,0);

		REP(i,n-1){          
			read(x); read(y);
			x--; y--;
			tree1[x].pb(y);
			tree1[y].pb(x);
			d1[x]++;
			d1[y]++;
		}

		REP(i,n-1){          
			read(x); read(y);
			x--; y--;
			tree2[x].pb(y);
			tree2[y].pb(x);
			d2[x]++;
			d2[y]++;
		}

		ans += (( iso(tree1,tree2,d1,d2) ) ? ( 'S' ) : ( 'N' ));
		ans += '\n';
		k+=2;
		tree1.clear(); tree2.clear(); 
	}
	ans[k-1] = '\0';
	puts((char*)ans.c_str());
	return 0;
}
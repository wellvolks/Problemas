#include <bits/stdc++.h>

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
    } 
    while ('0' <= c && c <= '9') { 
        n = n * 10 + c - '0'; 
        c = getchar_unlocked(); 
    } 
    n = (neg ? (-n) : (n)); 
    return true;
} 
  
int n, m;
struct tri{
	int at, custo;
	tri( int at = 0, int custo = 0 ) : at(at), custo(custo) { }
	bool operator < (const tri &a) const{
		if( custo != a.custo ) return custo < a.custo;
		return at < a.at;
	}
};

vector < vector < tri > > grafo;
int used[100001], memo[100001], dp[100001], vis = 1, vis2 = 1;
int  tam, resp = 1e9;
int maiorCiclo = 0;
int flag = 0;

int dfs( int at, int ant, int custo ){
	int &us = used[at];
	int &sv = memo[at];
	if( us == vis ){
		if((custo-sv) >= tam ){
			resp = min(resp, custo+sv);
			dp[at] = min(dp[at], resp);
			return (custo+sv);
		}
		return 1e9;
	}
	if(  resp <= custo ) return 1e9;
	sv = custo;
	us = vis;
	int ans = 1e9;
	for( int i = 0; i < grafo[at].size(); i++ ){
		if( grafo[at][i].at == ant ) continue;
		ans = min(ans, dfs(grafo[at][i].at, at, custo + grafo[at][i].custo));
	}
	us = 0;
	return ans;
}

int main(){
	ios::sync_with_stdio(false);
	while( read(n) ){
		read(m);
	  int de, para, custo;
	  grafo.resize(n);
	  for( int i = 0; i < m; i++ ){
		  read(de); read(para); read(custo);
		  grafo[de-1].push_back(tri(para-1, custo));
		  grafo[para-1].push_back(tri(de-1, custo));
	  }
	  for( int i = 0; i < n; i++ ) sort(grafo[i].begin(), grafo[i].end());
	  int q;
	  read(q);
	  maiorCiclo = 0;
	  while( q-- ){
		  read(de); read(tam);
		  resp = 1e9;
		  int ans = 1e9;
		  flag = 0;
		  ans = dfs(de-1, -1, 0);
		  if( ans < 1e9 ) cout << ans << '\n';
		  else cout << "-1\n";
		  vis++;
		  vis2++;
	  }
	  vis++;
	  grafo.clear();
	}
	return 0;
}
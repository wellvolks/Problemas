#include <set>
#include <tr1/unordered_map>
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
#define MAXN 1000603
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
  
struct par{
    unsigned long long mask;
	int lcp;
	par( unsigned long long mask = 0LL, int lcp = 0 ) : mask(mask) , lcp(lcp) { }
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
  
char str[MAXN], texto[MAXN];
vector < string > mapa;

int N, id[MAXN], v[MAXN], visit[MAXN], SA[MAXN];
char mask[]={0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01};
#define tget(i) ( (t[(i)/8]&mask[(i)%8]) ? 1 : 0 )
#define tset(i, b) t[(i)/8]=(b) ? (mask[(i)%8]|t[(i)/8]) : ((~mask[(i)%8])&t[(i)/8])
#define chr(i) (cs==sizeof(int)?((int*)s)[i]:(( char *)s)[i])
#define isLMS(i) (i>0 && tget(i) && !tget(i-1))
   
// find the start or end of each bucket
void getBuckets( char *s, int *bkt, int n, int K, int cs, bool end) {
  int i, sum=0;
  for(i=0; i<=K; i++) bkt[i]=0; // clear all buckets
  for(i=0; i<n; i++) bkt[chr(i)]++; // compute the size of each bucket
  for(i=0; i<=K; i++) { sum+=bkt[i]; bkt[i]=end ? sum : sum-bkt[i]; }
}
  
// compute SAl
void induceSAl( char *t, int *SA,  char *s, int *bkt,
                int n, int K, int cs, bool end) {
  int i, j;
  getBuckets(s, bkt, n, K, cs, end); // find starts of buckets
  for(i=0; i<n; i++) {
      j=SA[i]-1;
      if(j>=0 && !tget(j)) SA[bkt[chr(j)]++]=j;
  }
}
  
// compute SAs
void induceSAs( char *t, int *SA,  char *s, int *bkt,
                int n, int K, int cs, bool end) {
    int i, j;
    getBuckets(s, bkt, n, K, cs, end); // find ends of buckets
    for( i=n-1; i>=0; i-- ){
        j=SA[i]-1;
        if(j>=0 && tget(j)) SA[--bkt[chr(j)]]=j;
    }
}
  
// find the suffix array SA of s[0..n-1] in {1..K}^n
// require s[n-1]=0 (the sentinel!), n>=2
// use a working space (excluding s and SA) of at most 2.25n+O(1) for a constant alphabet
void SA_IS( char *s, int *SA, int n, int K, int cs) {
  int i, j;
   char *t=( char *)malloc(n/8+1); // LS-type array in bits
  
  // Classify the type of each character
  tset(n-2, 0); tset(n-1, 1); // the sentinel must be in s1, important!!!
  for(i=n-3; i>=0; i--)
    tset(i, (chr(i)<chr(i+1) || (chr(i)==chr(i+1) && tget(i+1)==1))?1:0);
  
  // stage 1: reduce the problem by at least 1/2
  // sort all the S-substrings
  int *bkt = (int *)malloc(sizeof(int)*(K+1)); // bucket array
  getBuckets(s, bkt, n, K, cs, true); // find ends of buckets
  for(i=0; i<n; i++) SA[i]=-1;
  for(i=1; i<n; i++)
    if(isLMS(i)) SA[--bkt[chr(i)]]=i;
  
  induceSAl(t, SA, s, bkt, n, K, cs, false);
  induceSAs(t, SA, s, bkt, n, K, cs, true);
  free(bkt);
  
  // compact all the sorted substrings into the first n1 items of SA
  // 2*n1 must be not larger than n (proveable)
  int n1=0;
  for(i=0; i<n; i++)
    if(isLMS(SA[i])) SA[n1++]=SA[i];
  
  // find the lexicographic names of all substrings
  for(i=n1; i<n; i++) SA[i]=-1; // init the name array buffer
  int name=0, prev=-1;
  for(i=0; i<n1; i++) {
    int pos=SA[i]; bool diff=false;
    for(int d=0; d<n; d++)
      if(prev==-1 || chr(pos+d)!=chr(prev+d) || tget(pos+d)!=tget(prev+d))
      { diff=true; break; }
      else if(d>0 && (isLMS(pos+d) || isLMS(prev+d))) break;
    if(diff) { name++; prev=pos; }
    pos=(pos%2==0)?pos/2:(pos-1)/2;
    SA[n1+pos]=name-1;
  }
  for(i=n-1, j=n-1; i>=n1; i--)
      if(SA[i]>=0) SA[j--]=SA[i];
  
  // stage 2: solve the reduced problem
  // recurse if names are not yet unique
  int *SA1=SA, *s1=SA+n-n1;
  if(name<n1)
    SA_IS(( char*)s1, SA1, n1, name-1, sizeof(int));
  else // generate the suffix array of s1 directly
    for(i=0; i<n1; i++) SA1[s1[i]] = i;
  
  // stage 3: induce the result for the original problem
  bkt = (int *)malloc(sizeof(int)*(K+1)); // bucket array
  // put all left-most S characters into their buckets
  getBuckets(s, bkt, n, K, cs, true); // find ends of buckets
  for(i=1, j=0; i<n; i++)
    if(isLMS(i)) s1[j++]=i; // get p1
  for(i=0; i<n1; i++) SA1[i]=s1[SA1[i]]; // get index in s
  for(i=n1; i<n; i++) SA[i]=-1; // init SA[n1..n-1]
  for(i=n1-1; i>=0; i--) {
      j=SA[i]; SA[i]=-1;
      SA[--bkt[chr(j)]]=j;
  }
  induceSAl(t, SA, s, bkt, n, K, cs, false);
  induceSAs(t, SA, s, bkt, n, K, cs, true);
  free(bkt); free(t);
}
  
#define NMAX 100100
int ranking[1000603];
int lcp[1000603];
void compute_lcp( int n ){
    int i, j, h = 0;
    for (i = 0; i != n; ++i) { ranking[SA[i]] = i; }
    for (i = 0; i != n; ++i) if (ranking[i] > 0) {
        j = SA[ranking[i]-1];
        while (texto[i+h] != 'A' && texto[i+h] == texto[j+h]) { h++; }
        lcp[ranking[i]] = h;
        if (h > 0) { h--; }
    }
}
 
int idx[1000603], tam[1000603], tp = 0;
char pala[1000603];
par pilha[1000603];
 
int main(){
    register int c = 0, t = 0, w = 0;
	
    while( read(t) && t ){ 
	//while(scanf("%d",&t) && t){
		c = N = w = 0;
		//getchar();
        REP(i,t){
			w  = 0;
			pala[w] = getchar_unlocked();
			while(!isalpha(pala[w])) pala[w] = getchar_unlocked();
			while(isalpha(pala[w])) pala[++w] = getchar_unlocked();
			pala[w] = '\0';
			//scanf("%s",&pala);
			//w = strlen(pala);
			for(int k = 0; k < w ;k++){
                texto[N] = pala[k];
                idx[N] = c;
				tam[N++] = (w - k);
            }
            c++;
            idx[N] = 62;
            if( i + 1 != t ) texto[N] = 'A';
            N++;
        }

        idx[N-1] = idx[N] = c; texto[N-1] = '.'; texto[N] = '\0';
		
		SA_IS( texto, SA, N, 200, 200 ); 
        compute_lcp(N);
		
        //REP(i,N) cout << texto+SA[i] << lcp[i] << " " << idx[SA[i]] << " " << tam[SA[i]] << "\n";
        unordered_map < uint64, int > mapa;
		
		tp = 0;
		par at;
        FOR(i,t,N-1){
			at.mask = 0LL;
			while( tp && (pilha[tp-1].lcp > lcp[i] || !lcp[i] ) ){
				mapa[pilha[tp-1].mask]++;
				tp--;
				if( tp ) pilha[tp-1].mask |= pilha[tp].mask;
				at = pilha[tp];
			}
			if( lcp[i] ){
				if( !tp || pilha[tp-1].lcp < lcp[i] ){
					tp++;
					pilha[tp-1].mask = (at.mask | (1LL << idx[SA[i]]) | (1LL << idx[SA[i-1]]));
					pilha[tp-1].lcp = lcp[i];
				}
				else if( pilha[tp-1].lcp == lcp[i] ) pilha[tp-1].mask |= (1LL << idx[SA[i]]);
			}
			if( (lcp[i] < tam[SA[i]]) && ((i+1 == N)||(lcp[i+1] < tam[SA[i]])) ) mapa[(1LL << idx[SA[i]])]++;
			if( i == N-1 && tp ){
				while( tp ){
					mapa[pilha[tp-1].mask]++;
					tp--;
					if( tp ) pilha[tp-1].mask |= pilha[tp].mask;
					at = pilha[tp];
				}
			}
	    }
		
        printf("%d\n",((int)mapa.size()));
    }
    return 0;
}
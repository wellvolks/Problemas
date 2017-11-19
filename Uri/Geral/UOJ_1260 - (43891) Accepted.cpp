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
//using namespace tr1;

#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define RFOR(i, b, a) for(int i = b; i >= a; --i)
#define REP(i, N) for(int i = 0; i < N; ++i)
#define RREP(i, N) for(int i = N-1; i >= 0; --i)
#define FORIT(i, a) for( TI(a) i = a.begin(); i != a.end(); i++ )
#define MAXN 10000
#define LINF 0x3F3F3F3FFFFFFFFFLL
#define FILL(X, V) memset( X, V, sizeof(X) )
#define TI(X) __typeof((X).begin())
#define ALL(V) V.begin(), V.end()
#define SIZE(V) int((V).size())
#define pb push_back
#define mp make_pair
using namespace std;
using namespace tr1;

int main(){
	register char buffer[100];
	register float cont = 1, resp = 0;
	register int qt;
	vector < pair <string, float > > ans;
	unordered_map <string , float> mapa;
	unordered_map <string , float>::iterator it;
	fscanf(stdin,"%d",&qt);
	getchar();
	getchar();
	while(qt--){
		cont = 1;
		while(gets(buffer)&& buffer[0]){
			cont++;
			mapa[buffer]++;
		}
		for(it = mapa.begin(); it != mapa.end(); it++){
			resp = it->second;
			resp = (resp / (cont-1))*100;
			ans.pb(make_pair(it->first, resp ));
		}
		mapa.clear();
		sort(ans.begin(), ans.end());
		for(int i = 0; i < ans.size(); i++) fprintf(stdout,"%s %.4f\n", ans[i].first.c_str(), ans[i].second);
		ans.clear();
		if(qt != 0) fprintf(stdout,"\n");
		resp = 0;
		cont = 1;       
	}
	return 0;
}
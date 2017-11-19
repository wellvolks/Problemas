#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef unsigned long long uint64;

int64 ata;

struct tri{
	int64 a, b, c;
	tri( int64 a = 0, int64 b = 0, int64 c = 0) : a(a), b(b), c(c) { }

	bool operator < ( const tri &u ) const {
		return (u.b) > ( b);
	}
};

int main(){
	ios::sync_with_stdio(false);
	priority_queue < tri > vet;
	int64 ans = 0LL;
	int a, b;
	int64 acm = 0, i = 0;
	while( cin >> a >> b ){
		ans += b*i;
		a--;
		if( a ){
			vet.push(tri(a,b,i));
			ata += b;
		}
		i++;
	}
	cout << ans << endl;

	while(!vet.empty()){
		tri at = vet.top();
		vet.pop();
		ans += (i-at.c) * at.b;
		at.c = i++;
		at.a--;
		if( at.a ) vet.push(at);
		else ata -= at.b;
	}

	cout << ans << '\n';

	return 0;
}
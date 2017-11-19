#include <bits/stdc++.h>
#define MAXN 111

using namespace std;

typedef long long int64;
typedef unsigned long long uint64;

char mapa[300];
char str[1000000];

int main(){
	ios::sync_with_stdio(false);
	memset(mapa, '\0',sizeof(mapa));
	mapa[64] = ' ';
	for(int i = 129; i <= 137; i++ ) mapa[i] = char((i-129) + 'a');
	for(int i = 145; i <= 153; i++ ) mapa[i] = char((i-145) + 'j');
	for(int i = 162; i <= 169; i++ ) mapa[i] = char((i-162) + 's');
	for(int i = 193; i <= 201; i++ ) mapa[i] = char((i-193) + 'A');
	for(int i = 209; i <= 217; i++ ) mapa[i] = char((i-209) + 'J');
	for(int i = 226; i <= 233; i++ ) mapa[i] = char((i-226) + 'S');
	for(int i = 240; i <= 249; i++ ) mapa[i] = char((i-240) + '0');
	while( gets(str) != NULL ){
		char *p = strtok(str, " ");
		string ans = "";
		while( p != NULL ){
			int val = 0;
			for(int i = 0, sz = strlen(p); i < sz; i++ ){
				val = (val * 8) + (p[i]-'0');
			}
			ans += mapa[val];
			p = strtok(NULL, " ");
		}
		cout << ans << '\n';
	}
	return 0;
}
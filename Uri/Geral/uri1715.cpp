#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int N, M, partida;
	cin >> N >> M;
	int resp = 0;
	for(int i = 0; i < N; i++){
		int contador = 0;
		for(int j = 0; j < M; j++){
			cin >> partida;
			if(partida)contador++;
		}
		if(contador == M)resp++;
	}
	cout << resp << "\n";
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	srand(time(NULL));

	cout << 1000000 << " " << 100000 << "\n";
    for(int i = 0; i < 1000000; i++){
        cout << char((rand() % 26)+'a');
    }

    cout << endl;

    int t = 1000000;
    for(int i = 0; i < 100000; i++){
        int op = (rand() % 4);
        cout << op+1 << " ";
        if( op == 0 ){
            int u = rand() % t;
            int v = rand() % t;
            char c = (rand() % 26)+'a';
            cout << min(u,v)+1 << " " << max(u,v)+1 << " " << c << endl;
        }
        else if( op == 1 ){
            int u = rand() % t;
            int v = rand() % t;
            char c = (rand() % 26)+'a';
            cout << min(u,v)+1 << " " << max(u,v)+1 << " " << c << endl;
        }
        else if( op == 2 ){
            int u = rand() % t;
            int v = rand() % t;
            cout << min(u,v)+1 << " " << max(u,v)+1 << endl;
        }
        else if( op == 3 ){
            cout << (rand() % t)+1 << " " << char((rand() % 26)+'a') << endl;
            t++;
        }
    }
	return 0;
}
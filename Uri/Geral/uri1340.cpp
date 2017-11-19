#include <bits/stdc++.h>
#include <tr1/unordered_map>

using namespace std;
using namespace tr1;

typedef long long int64;
typedef unsigned long long uint64;

int main(){
    ios::sync_with_stdio(false);
    int n, op, val;
    while( cin >> n ){
    	stack < int > pilha;
    	queue < int > fila;
    	priority_queue < int > fila_p;
    	bool ok1 = true, ok2 = true, ok3 = true;
    	for( int i = 0; i < n; i++ ){
    		cin >> op >> val;
    		if( op == 1 ){
    			pilha.push(val);
    			fila.push(val);
    			fila_p.push(val);
    		}
    		else{
    			if( pilha.empty() ) ok1 = false;
    			else if( pilha.top() == val ) pilha.pop();
    			else ok1 = false;
    			if( fila.empty() ) ok2 = false;
    			else if( fila.front() == val ) fila.pop();
    			else ok2 = false;
    			if( fila_p.empty() ) ok3 = false;
    			else if( fila_p.top() == val ) fila_p.pop();
    			else ok3 = false;
    		}
    	}
    	if( (ok1+ok2+ok3) > 1 ) cout << "not sure\n";
    	else if( !(ok1+ok2+ok3) ) cout << "impossible\n";
    	else if( ok1 ) cout << "stack\n";
    	else if( ok2 ) cout << "queue\n";
    	else cout << "priority queue\n";
    }
    return 0;
}
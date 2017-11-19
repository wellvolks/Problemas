#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>

using namespace std;

struct tri{
	int x, y, z;
};

struct evento{
	int x, y, tipo, id;
	evento( int x = 0, int y = 0, int tipo = 0, int id = 0) : x(x), y(y), tipo(tipo), id(id) { }
	bool operator < ( const evento &a ) const{
		if( x != a.x ) return x < a.x;
		if( y != a.y ) return y < a.y;
		if( tipo != a.tipo ) return tipo < a.tipo;
		return id < a.id;
	}
};

int main(){
	ios::sync_with_stdio(false);
	tri in;
	vector < tri > pts;
	vector < evento > event;
	int lo = 1e9, hi = 0, id = 0, tam = 0;
	while( cin >> in.x >> in.y >> in.z ){
		pts.push_back(in);
		hi = max(hi,in.z);
		lo = min(lo,in.x);
		event.push_back(evento(in.x, in.y, -1, id ));
		event.push_back(evento(in.z, in.y, 1, id++));
	}

	sort(event.begin(), event.end());
	int qt = event.size();
	tam = pts.size();

	map < int, int > ans;
	map < int, int > :: iterator jt;
	int ant = -1;
	for( int i = 0; i < qt; i++ ){
		evento at = event[i];
		if( at.tipo == -1 ){
			int alt = 0;
			for( int j = 0; j < tam; j++ ){
				if( at.x > pts[j].x && at.x < pts[j].z && j != at.id ) alt = max(alt,pts[j].y);
			}
			if( alt < at.y && at.y != ant ){ ans[at.x] = at.y; ant = at.y; }
		}
		else{
			int alt = 0;
			for( int j = 0; j < tam; j++ ){
				if( at.x >= pts[j].x && at.x < pts[j].z && j != at.id ) alt = max(alt,pts[j].y);
			}
			if( alt < at.y && alt != ant ){ ans[at.x] = alt; ant = alt; }
		}
	}

	bool flag = false;
	for( jt = ans.begin(); jt != ans.end(); jt++ ){
		if( flag ) cout << " ";
		flag = true;
		cout << jt->first << " " << jt->second;
	}
	cout << "\n";
	
	return 0;
}
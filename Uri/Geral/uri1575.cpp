#include <bits/stdc++.h>

using namespace std;
const double EPS = 1e-9;
const double INF = 1e50;

//funcao de comparacao
int cmp(double a, double b = 0.0){
	if(fabs(a-b) < EPS) return 0;
	return a > b ? 1 : -1;
}

struct pt {
	double x, y;
 	pt(double x = 0.0, double y = 0.0) : x(x), y(y) {}
	bool operator< (const pt & p) const {
		return x < p.x-EPS || abs(x-p.x) < EPS && y < p.y - EPS;
	}

	double length() { return sqrt(x*x + y*y); }
	pt operator - (pt p){ return pt(x - p.x, y - p.y); }
};
 
struct line {
	double a, b, c;
 
	line() {}
	line (pt p, pt q) {
		a = p.y - q.y;
		b = q.x - p.x;
		c = - a * p.x - b * p.y;
		norm();
	}
 
	void norm() {
		double z = sqrt (a*a + b*b);
		if (abs(z) > EPS)
			a /= z,  b /= z,  c /= z;
	}
 
	double dist (pt p) const {
		return a * p.x + b * p.y + c;
	}
};
 
#define det(a,b,c,d)  (a*d-b*c)
 
inline bool betw (double l, double r, double x) {
	return min(l,r) <= x + EPS && x <= max(l,r) + EPS;
}
 
inline bool intersect_1d (double a, double b, double c, double d) {
	if (a > b)  swap (a, b);
	if (c > d)  swap (c, d);
	return max (a, c) <= min (b, d) + EPS;
}
 
bool intersect (pt a, pt b, pt c, pt d, pt & left, pt & right) {
	if (! intersect_1d (a.x, b.x, c.x, d.x) || ! intersect_1d (a.y, b.y, c.y, d.y))
		return false;
	line m (a, b);
	line n (c, d);
	double zn = det (m.a, m.b, n.a, n.b);
	if (abs (zn) < EPS) {
		if (abs (m.dist (c)) > EPS || abs (n.dist (a)) > EPS)
			return false;
		if (b < a)  swap (a, b);
		if (d < c)  swap (c, d);
		left = max (a, c);
		right = min (b, d);
		return true;
	}
	else {
		left.x = right.x = - det (m.c, m.b, n.c, n.b) / zn;
		left.y = right.y = - det (m.a, m.c, n.a, n.c) / zn;
		return betw (a.x, b.x, left.x)
			&& betw (a.y, b.y, left.y)
			&& betw (c.x, d.x, left.x)
			&& betw (c.y, d.y, left.y);
	}
}

double dist(pt a, pt b){ return (a - b).length(); }

struct tri{
	pt p;
	int tempo;
	tri( pt p, int tempo = 0) : p(p), tempo(tempo) { }
};

int main(){
	ios::sync_with_stdio(false);
	pt a, b, p, ant;
	int t, qa, qb;
	cin >> t;
	vector < tri > pa, pb;
	bool flag = false;
	while( t-- ){
		if( flag ) cout << "\n";
		flag = true;
		pa.clear(); pb.clear();
		cin >> a.x >> a.y >> b.x >> b.y;
		cin >> qb;
		int tempo = 0;
		ant = b;
		pb.push_back(tri(b,tempo));
		for( int i = 0; i < qb; i++ ){
			cin >> p.x >> p.y;
			tempo += dist(ant,p);
			pb.push_back(tri(p,tempo));
			ant = p;
		}
		cin >> qa;
		ant = a;
		tempo = 0;
		pa.push_back(tri(a,tempo));
		for( int i = 0; i < qa; i++ ){
			cin >> p.x >> p.y;
			tempo += dist(ant,p);
			pa.push_back(tri(p,tempo));
			ant = p;
		}
		bool ans = false;
		string resp[] = {"Yes","No"};
		if( a.x == b.x && a.y == b.y ) ans = true;
		for( int j = 1; j <= qb && !ans; j++ ){
			for( int i = 1; i <= qa && !ans; i++ ){
				pt r1, r2;
				if( intersect(pa[i-1].p,pa[i].p,pb[j-1].p, pb[j].p, r1, r2) ){
					double d1, d2;
					if( !(r1 < r2 || r2 < r1 ) ){
						d1 = (int)dist(r1,pa[i-1].p);
						d2 = (int)dist(r1,pb[j-1].p);
						if( !cmp(((pa[i-1].tempo) + d1),((pb[j-1].tempo) + d2)) ){
							if( j == qb && (!cmp(r1.x,pb[j].p.x) && !cmp(r1.y,pb[j].p.y)) ) continue;
							ans = true;
							break;
						}
					}
					else{
						d1 = (int)dist(pt((r1.x+r2.x)/2., (r1.y+r2.y)/2.), pa[i-1].p);
 						d2 = (int)dist(pt((r1.x+r2.x)/2., (r1.y+r2.y)/2.), pb[j-1].p);
						if( !cmp((pa[i-1].tempo + d1),(pb[j-1].tempo + d2)) ){
							ans = true;
							break;
						}
					}
				}
			}
		}
		cout << resp[ans] << "\n";
	}
	return 0;
}
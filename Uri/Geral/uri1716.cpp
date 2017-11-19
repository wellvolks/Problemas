#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
int64 _sieve_size;
bitset < 100012 > bs;
vector < int64 >  primes;

void sieve( int64 upperbound ){
    _sieve_size = upperbound + 1;
    bs[0] = bs[1] = 1;
    for( int64 i = 2; i <= _sieve_size; i++ ){
        if( !bs[i] ){
            for( int64 j = i * i; j <= _sieve_size; j += i ) bs[j] = 1;
            primes.push_back((int)i);
        }
    }
}

int64 fastexp(int64 a, int64 b, int64 mod){ 
    int64 x; 
    if(b==0) return 1LL; 
    if(b==1) return a; 
    if(b%2==0){ 
        x = fastexp(a,b>>1, mod) % mod; 
        return (x*x) % mod; 
    } 
    else return (a*fastexp(a,b-1, mod)) % mod; 
} 

int64 mod(int64 a, int64 b){
    int64 r = a % b;
    if ((r < 0) && (b > 0))
    return (b + r);
 
    if ((r > 0) && (b < 0))
    return (b + r);
 
    return (r);
}
 
int64 euclides_ext(int64 a, int64 b, int64 c){
    int64 r;
 
    r = mod(b, a);
 
    if (r == 0) {
    return (mod((c / a), (b / a))); 
    }
 
    return ((euclides_ext(r, a, -c) * b + c) / (mod(a, b)));
}
int main(){
	ios::sync_with_stdio(false);
	int64 n, e, c;
	cin >> n >> e >> c;
	sieve(100000);
	int tam = primes.size();

	for( int i = 0; i < tam; i++ ){
		if( primes[i] == 2 ) continue;
		for( int j = 0; j < tam; j++ ){
			if( primes[j] == 2 ) continue;
			if( (primes[i] * primes[j]) == n ){
				int64 tot = (primes[i]-1LL) * (primes[j]-1LL);
				if( e >= tot || __gcd(tot, e) != 1 ) continue;
				int64 d = euclides_ext(e, tot, 1);
				int64 m = fastexp(c, d, n);
				int64 original = fastexp(m, e, n);
				if( c == original ){
					cout << m << '\n';
					i = tam;
					break;
				}
			}
		}
	}
	return 0;
}
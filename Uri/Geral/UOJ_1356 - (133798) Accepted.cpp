#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static long long  b, p, l, n, H, ss, AUX, AUX2;
static long long  x, y;
static long long  pot[100002];
static int r, i;
static char s;

static long long tree [100010];

long long query(int tam, long long a, long long b) {
    if (a == 0) {
        long long sum = 0;
        for (; b >= 0; b = (b & (b + 1)) - 1){
          sum += tree[b];
    	}
        return sum; 
    } else {
        return query(tam, 0, b) - query(tam, 0, a-1);
    }
}
void increase(int tam, long long k, long long inc) {
    for (; k < tam+1; k |= k + 1){
        tree[k] += inc;
	}
}
void decrease(int tam, long long k, long long inc) {
    for (; k < tam+1; k |= k + 1){
        tree[k] -= inc;
	}
}
long long mod(long long a, long long b)
{
    long long r = a % b;
    if ((r < 0) && (b > 0))
	return (b + r);

    if ((r > 0) && (b < 0))
	return (b + r);

    return (r);
}

long long euclides_ext(long long a, long long b, long long c)
{
    long long r;

    r = mod(b, a);

    if (r == 0) {
	return (mod((c / a), (b / a)));	
    }

    return ((euclides_ext(r, a, -c) * b + c) / (mod(a, b)));
}
int para = 0;
void read( long long *n ) {
	*n = 0;
	 int neg = 0;
	 char c = getchar_unlocked();
    if( c == EOF) { para = 1; return; }
	while (!('0' <= c && c <= '9')) {
		if( c == '-' ) neg = 1;
		c = getchar_unlocked();
	}
	while ('0' <= c && c <= '9') {
		*n = *n * 10 + c - '0';
		c = getchar_unlocked();
	}
	*n = (neg ? (-*n) : (*n));
}

int main(){

	while(1){
		read(&b); read(&p); read(&l); read(&n);
		if(!(b+p+l+n)) break;
		memset(tree,0,sizeof(tree));
		pot[0] = 1;
		for(r = 1; r < l+1; r++){
			pot[r] = mod (pot[r-1] * b,  p);
		}
		for(i = 0; i < n; i++){
            s = getchar_unlocked();
			read(&x); read(&y);
			//scanf(" %c %ld %ld",&s,&x,&y);
			if(s == 'E'){
				ss =  (pot[l-x] * y);
				AUX = query(l,0,x);
				AUX2 = query(l,0,x-1);
				H = AUX - AUX2;
				ss = mod(ss,p);
				H = H * (-1);
				ss += H;
				increase(l,x,ss);
			}
			else{
				AUX = query(l,0,y);
				AUX2 = query(l,0,x-1);
				H = AUX - AUX2;
				H = mod(H,p);
				AUX = euclides_ext(pot[l-y],p,1);
				AUX = mod(AUX,p);
				H = mod (H*AUX,p);
				printf("%ld\n",H);
			}
		}
		printf("-\n");
	}
	return 0;
}



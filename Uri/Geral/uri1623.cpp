#include <bits/stdc++.h>

using namespace std;

char val[60000-1];

#include <bits/stdc++.h>
#include <tr1/unordered_map>

using namespace std;
using namespace tr1;

class BigNum  
{
private:
	static const int DigLen = 4;    
	static const int MaxVal = 9999;  
	static const int MaxLen = 60000; 
	int len, a[MaxLen/DigLen];
public:
	BigNum(){ len = 1; memset(a, 0, sizeof(a)); }
	BigNum(int);
	BigNum(const char*);
	BigNum(const BigNum &);
	BigNum &operator = (const BigNum &);
 
	BigNum operator + (const BigNum &) const;
	BigNum operator - (const BigNum &) const;
	BigNum operator * (const BigNum &) const;
	BigNum operator / (const int &) const;
	BigNum operator / (const BigNum &) const;
	int operator % (const int &) const;
	BigNum operator % (const BigNum &) const;
	bool operator < (const BigNum &) const;
	bool operator == (const BigNum &) const;
 
	BigNum pow(int);
	BigNum sqrt();
	void print();
private:
	pair<BigNum, BigNum> divmod(const BigNum &) const;
};
pair<BigNum, BigNum> BigNum::divmod(const BigNum &T) const
{
	BigNum quotient, remainder=*this;
	while( remainder.len >= T.len )
	{
		int diff = max(remainder.len-T.len-1, 0)*DigLen;
		int t1=remainder.a[remainder.len-1], t2=T.a[T.len-1];
		if( remainder.len > T.len )
			t1 = t1*(MaxVal+1)+remainder.a[remainder.len-2];
		while( t1 > t2*10+9 )  // bug
		{
			diff++;
			t2 = t2*10+9;
		}
		if( diff == 0 )
			break;
		BigNum tmp = BigNum(10).pow(diff);
		quotient = quotient+tmp;
		remainder = remainder-tmp*T;
	}
	while( T<remainder || T==remainder )
	{
		quotient = quotient+1;
		remainder = remainder-T;
	}
	return make_pair(quotient, remainder);
}
 
BigNum::BigNum(int b)
{
	len = 0;
	memset(a, 0, sizeof(a));
	while( b > MaxVal )
	{
		a[len++] = b%(MaxVal+1);
		b /= MaxVal+1;
	}
	a[len++] = b;
}
BigNum::BigNum(const char*s)
{
	int idx=0, n=strlen(s);
	memset(a, 0, sizeof(a));
	len = n/DigLen + (n%DigLen>0);
	for(int i=n-1; i>=0; i-=DigLen)
	{
		int t = 0;
		for(int j=max(i-DigLen+1, 0); j<=i; j++)
			t = t*10+s[j]-'0';
		a[idx++] = t;
	}
}
BigNum::BigNum(const BigNum &T)
{
	if( this == &T )
		return;
	len = T.len;
	memcpy(a, T.a, sizeof(T.a));
}
BigNum & BigNum::operator = (const BigNum &T)
{
	if( this == &T )
		return *this;
	len = T.len;
	memcpy(a, T.a, sizeof(T.a));
	return *this;
}
 
BigNum BigNum::operator + (const BigNum &T) const
{
	BigNum ret(*this);
	ret.len = max(len, T.len);
	for(int i=0; i<ret.len; i++)
	{
		ret.a[i] += T.a[i];
		if( ret.a[i] > MaxVal )
		{
			ret.a[i+1]++;
			ret.a[i] -= MaxVal+1;
		}
	}
	if( ret.a[ret.len] != 0 )
		ret.len++;
	return ret;
}
BigNum BigNum::operator - (const BigNum & T) const
{
	BigNum t1(*this), t2(T);  // *this > T
	if( *this < T )
		swap(t1, t2);
	for(int i=0; i<t1.len; i++)
	{
		if( t1.a[i] < t2.a[i] )
		{
			int j = i+1;
			while( t1.a[j] == 0 )
				j++;
			t1.a[j]--;  j--;
			while( j > i )
				t1.a[j--] += MaxVal;
			t1.a[i] = (t1.a[i]+MaxVal+1)-t2.a[i];
		}
		else
			t1.a[i] -= t2.a[i];
	}
	while( t1.a[t1.len-1]==0 && t1.len>1 )
		t1.len--;
	return t1;
}
BigNum BigNum::operator * (const BigNum & T) const
{
	BigNum ret;
	ret.len = len+T.len;
	for(int i=0; i<len; i++)
		for(int j=0; j<T.len; j++)
		{
			int tot = a[i]*T.a[j] + ret.a[i+j];
			if( tot > MaxVal )
			{
				ret.a[i+j] = tot%(MaxVal+1);
				ret.a[i+j+1] += tot/(MaxVal+1);
			}
			else
				ret.a[i+j] = tot;
		}
	while( ret.a[ret.len-1]==0 && ret.len>1 )
		ret.len--;
	return ret;
}
BigNum BigNum::operator / (const int & b) const
{
	BigNum ret;
	ret.len = len;
	int pre = 0;
	for(int i=len-1; i>=0; i--)
	{
		ret.a[i] = (a[i] + pre*(MaxVal+1))/b;
		pre = a[i] + pre*(MaxVal+1) - ret.a[i]*b;
	}
	while( ret.a[ret.len-1]==0 && ret.len >1 )
		ret.len--;
	return ret;
}
BigNum BigNum::operator / (const BigNum & T) const
{
	return divmod(T).first;
}
int BigNum::operator % (const int & b) const
{
	int ret = 0;
	for(int i=len-1; i>=0; i--)
		ret = ( (ret*(MaxVal+1))%b + a[i] )%b;
	return ret;
}
BigNum BigNum::operator % (const BigNum & T) const
{
	return divmod(T).second;
}
bool BigNum::operator < (const BigNum & T) const
{
	if( len < T.len )
		return true;
	else if( len == T.len )
	{
		int idx = len-1;
		while( a[idx]==T.a[idx] && idx>=1 )
			idx--;
		if( idx>=0 && a[idx]<T.a[idx] )
			return true;
		else
			return false;
	}
	return false;
}
bool BigNum::operator == (const BigNum & T) const
{
	if( len != T.len )
		return false;
	for(int i=len-1; i>=0; i--)
		if( a[i] != T.a[i] )
			return false;
	return true;
}
 
BigNum BigNum::pow(int m)
{
	if( m <= 0 )
		return BigNum(1);
	BigNum t(*this), ret(1);
	while( m )
	{
		if( m&1 )
			ret = ret*t;
		t = t*t;
		m >>= 1;
	}
	return ret;
}
BigNum BigNum::sqrt()
{
	BigNum l=1, r(*this), m, ret;
	while( l<r || l==r )
	{
		m = (l+r)/2;
		BigNum mul = m*m;
		if( mul == *this )
			return m;
		else if( mul < *this )
		{
			l = m+1;
			ret = m;
		}
		else
			r = m-1;
	}
	return ret;
}
void BigNum::print()
{
	printf("%d", a[len-1]);
	for(int i=len-2; i>=0; i--)
		printf("%04d", a[i]);
	printf("\n");
}

bool getFat(BigNum &valLim, BigNum &ans, int n){
	if( n <= 1 ){
		ans = BigNum(1);
		return true;
	}
	BigNum fat = BigNum(1);
	for( int i = 2; i <= n; i++ ){
		fat = fat * BigNum(i);
		if( !((fat < valLim) || (fat == valLim)) ){
			return false;
		}
	}
	ans = fat;
	return true;
}

int main(){
	int n, q;
	while( cin >> n >> q && (n+q) ){
		cin >> val;
		BigNum t = BigNum(val), r;
		if( getFat(t, r, n-(q-1)) ) r.print();
		else cout << "descartado\n";
	}
	return 0;
}
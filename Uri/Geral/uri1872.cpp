#include <bits/stdc++.h>
 
using namespace std;
 
bool isPalin(int val){
    char str[100];
    sprintf(str,"%d",val);
    string a = "", b;
    a += str;
    b = a;
    reverse(a.begin(), a.end());
    return (a == b);
}
 
string getAns(double val){
    char str[100];
    sprintf(str,"%.6lf",val);
    int i = strlen(str);
    i--;
    while( i >= 0 && str[i] == '0' ) i--;
    if( str[i] != '.' ) i++;
    str[i] = '\0';
    return str;
}
 
int main(){
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    string val;
    while( t-- ){
        cin >> val;
        string lo = "", hi = "";
        int i = 0, ok = 0;
        for( ; i < val.size() && val[i] != '.'; i++ ) lo += val[i];
        for( i++; i < val.size(); i++ ) hi += val[i];
        if( hi == "" ) ok = 1;
        while( hi.size() < lo.size() ) hi += "0";
        double v = 0., num, n;
        char aux[100];
        sscanf((char*)lo.data(),"%lf",&n);
        reverse(lo.begin(), lo.end());
        sscanf((char*)lo.data(),"%lf",&v);
        sscanf((char*)val.data(),"%lf",&num);
        if(ok && isPalin(num)) cout << "0\n";
        else{
	        if( hi > lo ){
	            sprintf(aux,"%lf",n+1.);
	            reverse(aux, aux+strlen(aux));
	            sscanf(aux,"%lf",&n);
	            double ans = (floor(num+1.) - num) + (isPalin(num+1) ? (0.) : (n));
	            cout << getAns(ans) << "\n";
	        }
	        else if( lo > hi ){
	            double ans = (v/double(powl(10.,lo.size()))) - (num - floor(num));
	            cout << getAns(ans) << "\n";
	        }
	        else cout << "0\n";
    	}
    }
    return 0;
}
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
 
using namespace std;
 
string backtracking(int i, int s, string& resp)
{
	int c = 0;
	//cout << i << " " << s << " " << resp << endl;
	for ( int k = 0, sz = resp.size(); k < sz; k++ )
	{
		if ( k+i + i <= sz )
		{
			//cout << resp.substr(k, i) << " " << resp.substr(k+i, i) << endl;
			if ( resp.substr(k, i) == resp.substr(k+i, i) ) return resp.substr(0, resp.size()-1);
		}
		//c++;
	}
	if ( i == s || s == 0 ) return resp;
	//else if ( i < s ) return "";
	//if ( i > s && i > 1 && s > 1 ) return resp.substr(0, resp.size()-1);
	else return backtracking(i+1, s, resp);
}
 
int main()
{
	ios::sync_with_stdio(false);
	string resp = "", at = "";
	queue<string> gr;
	gr.push("N");
	int count = 0;
	while ( !gr.empty() )
	{
		at = gr.front();
		int s = at.size();
		gr.pop();
 
		string tmp = at+"N";
		resp = backtracking(1, ((s+1) >> 1), tmp);
		if ( tmp == resp ) gr.push(resp);
 
		if ( resp.size() == 5000 )
		{
			cout << at << endl;
			break;
		}
 
		tmp = at+"O";
		resp = backtracking(1, ((s+1) >> 1), tmp);
		if ( tmp == resp ) gr.push(resp);
 
		if ( resp.size() == 5000 )
		{
			cout << at << endl;
			break;
		}
 
		tmp = at+"P";
		resp = backtracking(1, ((s+1) >> 1), tmp);
		if ( tmp == resp ) gr.push(resp);
 
		if ( resp.size() == 5000 )
		{
			cout << at << endl;
			break;
		}
	}
 
	//at = gr.front();
	//cout << "resposta " << at << endl;
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

struct plan
{
    int starting, ending, interference;
    double ang;
    plan(int s, int e, int i, double ang) : starting(s), ending(e), interference(i), ang(ang) {}
    plan(){}
};

vector<plan> airplanes(2010);
    double intersection[2010][2010];

int main()
{
    ios::sync_with_stdio(false);
    int X, K, N, Q;
    cin >> X >> K >> N >> Q;
    
    memset(intersection, 0, sizeof(intersection));
    for( int i = 0; i < N; i++ )
    {
        int S, E, I;
        cin >> S >> E >> I;
        airplanes[i] = plan(S, E, I, ((double)E - S)/(X));
        for( int j = 0; j < i; j++ )
            intersection[i][j] = intersection[j][i] = (airplanes[j].starting - airplanes[i].starting)/(airplanes[i].ang - airplanes[j].ang);
    }
    vector<pair<double,int>> verify;
    for( int i = 0; i < Q; i++ )
    {
        verify.clear();
        int A, x;
        cin >> A >> x;
        A--;
        //cout << airplanes[A].interference << endl;
        int sum = 0, lim = x + K;
        if( lim > X ) lim = X;
        double atx = airplanes[A].ang*x + airplanes[A].starting,
        atlim = airplanes[A].ang*lim + airplanes[A].starting;
        for( int i = 0; i < N; i++ )
        {
            if( i == A ) continue;
            double Atx = airplanes[i].ang * x + airplanes[i].starting,
                Atlim = airplanes[i].ang * lim + airplanes[i].starting;
            if( Atx > atx && Atlim > atlim )
                sum += airplanes[i].interference;
            else if( Atx > atx || Atlim > atlim )
            {
                if( Atx > atx )
                    sum += airplanes[i].interference;
                verify.push_back(make_pair(intersection[i][A], i));
            }
        }
        sort(verify.begin(), verify.end());
        int temp = sum;
        double anterior = x;
        for( auto ints : verify )
        {
            //cout << temp << "(" << sum << ") ";
            int i = ints.second;
            if( airplanes[i].ang * lim + airplanes[i].starting > atlim )
            {
                temp += airplanes[i].interference;
                if( temp > sum ) sum = temp;
            }
            else
            {
                if( fabs(ints.first - anterior) < 0.000001 && sum == temp )
                    sum -= airplanes[i].interference;
                temp -= airplanes[i].interference;
            }
            anterior = ints.first;
        }
        //cout << temp << "(" << sum << ") " << endl;
        cout << sum << endl;
    }
}

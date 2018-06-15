#include <bits/stdc++.h>
using namespace std;

#define foreach(i,n) for(__typeof((n).begin())i =(n).begin();i!=(n).end();i++)
#define rep(i,n) for(__typeof(n) i=0; i<(n); i++)
#define mem(x,val) memset((x),(val),sizeof(x));
#define all(x) x.begin(),x.end()
#define pb push_back
#define mp make_pair
#define ins insert
#define ff first
#define ss second
#define ll long long
typedef string st;
typedef vector<int> vi;
typedef vector<st> vs;
typedef map<int,int> mii;
typedef map<st,int> msi;
typedef set<int> si;
typedef set<st> ss;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

#define debug1(x) cout << #x << ": " << x << endl
#define debug2(x, y) cout << #x << ": " << x << '\t' << #y << ": " << y << endl
#define debug3(x, y, z) cout << #x << ": " << x << '\t' << #y << ": " << y << '\t' << #z << ": " << z << endl


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        int am=0,bm=0,asum=0,bsum=0;
        int te;
        cin>>n;
        rep(i,n)
        {
            cin>>te;
            asum += te;
            if(te > am)
                am = te;
        }

        asum -=am;

        rep(i,n)
        {
            cin>>te;
            bsum += te;
            if(te > bm)
                bm = te;
        }

        bsum -=bm;

        if(bsum == asum)
            cout<<"Draw\n";
        else if(asum < bsum)
            cout<<"Alice\n";
        else
            cout<<"Bob\"


    }

    return 0;
}
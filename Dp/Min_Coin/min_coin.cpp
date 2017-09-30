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
    int s,n;
    cin>>s>>n;
    vi x;
    int t;
    rep(i,n)
    {
        cin>>t;
        x.pb(t);
    }
    int sum[s+1];
   
    rep(i,s+1)
    {
        sum[i] = INT_MAX;
    }
    sum[0] = 0;
    
    
    rep(i,n)//for coins
    {
        for(int j=1;j<s+1;j++)//for each sum
        {
            if(x[i] <= j)
            {
                int c_taken = sum[j-x[i]]+1;
                if(c_taken < sum[j])
                {
                    sum[j] = c_taken;
                }
            }
        }
    }
    
    cout<<x[n];
    

  return 0;
}
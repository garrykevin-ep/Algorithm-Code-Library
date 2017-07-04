using namespace std;
#include <bits/stdc++.h>

#define foreach(i,n) for(__typeof((n).begin())i =(n).begin();i!=(n).end();i++)
#define rep(i,n) for(__typeof(n) i=0; i<(n); i++)
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




int main()
{
	//use . to refer pair objects
	time_t start=clock();
	ios_base::sync_with_stdio(0);
	
	set<pair<int,pair<int,int>>> cen;
	
	rep(i,44)
	{
		int s,x,y;
		cin>>s>>x>>y;
		cen.ins(mp(s,mp(x,y)));
	}

	for(auto i= cen.rbegin(); i !=cen.rend();++i)
	{
		for(auto j = next(i); j != cen.rend();++j)
		{
			cout<<i->ff<<","<<i->ss.ff<<","<<i->ss.ss<<endl;
			cout<<j->ff<<","<<j->ss.ff<<","<<j->ss.ss<<endl;
		}
		cout<<endl;
	}
	

	cerr << " Program has run "<< ( clock()-start ) / CLOCKS_PER_SEC << " s " << endl;
	return 0;
}
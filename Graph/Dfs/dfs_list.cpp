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
typedef vector<vi> vvi;
typedef vector<st> vs;
typedef vector<vs> vvs;
typedef map<int,int> mii;
typedef map<st,int> msi;
typedef set<int> si;
typedef set<st> ss;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

int maxx=0;

//visted is used for searching
//this is to see depth

int tr(vvi &graph,int s,int depth)
{
	depth++;
	//cout<<"depth "<<depth<<" src "<<s+1<<endl;
	foreach(i,graph[s])
	{	
		tr(graph,(*i)-1,depth);
		maxx = max(depth,maxx);
		cout<<*i;//<<endl; //see how dfs goes
	}
	return maxx;
}


void vis(vvi &graph)
{
	rep(i,3)
	{
		cout<<i+1<<" : ";
		foreach(j,graph[i])
		{
			cout<<*j;
		}
		cout<<endl;
	}
}


int main()
{
	time_t start=clock();
	ios_base::sync_with_stdio(0);

	vvi graph(10);
	
	graph[0].pb(2);
	graph[0].pb(3);
	graph[1].pb(4);
	graph[1].pb(5);
	graph[1].pb(6);
	graph[2].pb(7);
	graph[2].pb(8);
	graph[2].pb(9);

	//travese graph
	cout<<tr(graph,0,0)<<endl;
	
	//visuallise graph as adj list
	vis(graph);
	
	cerr <<" Program has run "<< ( clock()-start ) / CLOCKS_PER_SEC <<" s "<< endl;
	return 0;
}


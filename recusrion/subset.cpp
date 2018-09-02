#include <bits/stdc++.h>
using namespace std;

#define foreach(i,n) for(__typeof((n).begin())i =(n).begin();i!=(n).end();i++)
#define rep(i,n) for(__typeof(n) i=0; i<(n); i++)
#define mem(x,val) memset((x),(val),sizeof(x));
#define all(x) x.begin(),x.end()
#define mp make_pair
#define ins insert
#define ff first
#define ss second

typedef string st;
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

//we eleminate duplicates not making make branches
void dfs(vector<int> &nums,int index,vector<int> &result)
{
	if(nums.size() == index)//base condtion
	{
		rep(i,result.size())
		cout<<result[i]<<" ";
		cout<<endl;
		return;
	}

	dfs(nums,index+1,result);//nums[index] not in the solution
	result.push_back(nums[index]);
	dfs(nums,index+1,result);//nums[index] in the solution
	result.pop_back();
}

int main()
{
	int n;
	cin>>n;
	vector<int> nums(n),result;
	
	rep(i,n)
	{
		cin>>nums[i];
	}

	// rep(i,n)
	// {
	// 	debug1(nums[i]);
	// }

	dfs(nums,0,result);

	return 0;
}
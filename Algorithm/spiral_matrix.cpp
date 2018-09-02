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

int Find(int row ,int col,int n)
{
  int start = 0 ,end = n -1 ;
  int mat = n;
  int layerValue = 0,layer = 0;
  while(start <= end)
  {
    int top =  ((n-1)*0)+1;
    int right = ((n-1)*1)+1;
    int bottom = ((n-1)*2)+1;
    int left = ((n-1)*3)+1;

    if( row == start ){
      // cout<<"top ";
      return layerValue + top + col - layer;
    }

    else if(end == col)
    {
      // cout<<"Right ";
      return layerValue + right + row - layer;
    }
    else if(row == end)
    {
      // cout<<layerValue<<" "<<bottom<<endl;
      return layerValue + bottom + (end - col);
    }
    else if(col == start)
    {
      // cout<<"left ";
      return layerValue + left + (end - row );
      return 1;
    }
    
    layerValue += (n*4) - 4;
    layer++;
    n-=2;
    start++;
    end--;
  }

}


int main()
{
  
  int n;
  cin>>n;
  // cout<<Find(5,4,6)<<endl;
  rep(i,n)
  {
    rep(j,n)
    {
      cout<<Find(i,j,n)<<" ";
    }
    cout<<endl;
  }

  return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define foreach(i,n) for(__typeof((n).begin())i =(n).begin();i!=(n).end();i++)
#define rep(i,n) for(__typeof(n) i=0; i<(n); i++)
#define mem(x,val) memset((x),(val),sizeof(x));

#define debug1(x) cout << #x << ": " << x << endl
#define debug2(x, y) cout << #x << ": " << x << '\t' << #y << ": " << y << endl
#define debug3(x, y, z) cout << #x << ": " << x << '\t' << #y << ": " << y << '\t' << #z << ": " << z << endl

int a[5]={1,2,3,4,5},tree[10];

int build(int start,int end,int node)
{
  if(start == end)
  {
    tree[node] = a[end];
    return tree[node];
  }
  else
  {
    int mid = (start + end)/2;
    tree[node] = build(start,mid,2*node+1) + build(mid+1,end,(2*node)+2);
    return tree[node];
  }
}

int query(int start ,int end , int l ,int r,int node)
{
  
  //totally outside
  if(r < start  || end < l)
    return 0;
  //totally inside
  if(l <= start && end <= r)
    return tree[node];
  
  //partial inside

  int mid = (start+end)/2;
  return query(start,mid,l,r,2*node+1) + query(mid+1,end,l,r,2*node+2);
}

int main()
{
  build(0,4,0);
  // rep(i,10)debug1(tree[i]);
 
  // cout<<query(0,4,0,4,0)<<endl;
  cout<<query(0,4,0,2,0)<<endl;
  // cout<<query(0,4,0,3,0)<<endl;
  cout<<query(0,4,1,3,0)<<endl;

  return 0;
}
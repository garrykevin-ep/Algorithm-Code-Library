/*

source: gog
constructSTUtil :
	uses top to bottom to fill st
	if start index == end index its leaf
	recurse left+right and return calculated
	
*/
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

int getMid(int start, int end) {  return start + (end -start)/2;  }



//st -> seg tree
//ss & se -> start,end index for maintaining recursion
//qs & qe -> start,end  changes for recursion depth = node iteration
int getSumUtil(int *st, int ss, int se, int qs, int qe, int si)
{
    // If segment of this node is a part of given range, then return
    // the sum of the segment
    
    // cur start is greater than seg & cur end is less than seg
    // ss >= qs && se <= qe
    if (qs <= ss && qe >= se)
        return st[si];
 	// debug3(ss,se,si);
    
    // If segment of this node is outside the given range
    if (se < qs || ss > qe)
        return 0;
 	
    // If a part of this segment overlaps with the given range
    int mid = getMid(ss, se);
    return getSumUtil(st, ss, mid, qs, qe, 2*si+1) +
           getSumUtil(st, mid+1, se, qs, qe, 2*si+2);
}

int getSum(int *st, int n, int qs, int qe)
{
    // Check for erroneous input values
    if (qs < 0 || qe > n-1 || qs > qe)
    {
        printf("Invalid Input");
        return -1;
    }
 
    return getSumUtil(st, 0, n-1, qs, qe, 0);
}

int constructSTUtil(int arr[], int ss, int se, int *st, int si)
{
    // If there is one element in array, store it in current node of
    // segment tree and return
    // debug3(si,ss,se);
    if (ss == se)
    {
    	// debug1("assign");
        st[si] = arr[ss];
        return arr[ss];
    }
 
    // If there are more than one elements, then recur for left and
    // right subtrees and store the sum of values in this node
    // debug2("segement index",si);

    int mid = getMid(ss, se);
    st[si] =  constructSTUtil(arr, ss, mid, st, si*2+1) +
              constructSTUtil(arr, mid+1, se, st, si*2+2);
    return st[si];
}
 

int *constructST(int arr[], int n)
{
    // Allocate memory for segment tree
 
    //Height of segment tree
    int x = (int)(ceil(log2(n))); 
 
    //Maximum size of segment tree
    int max_size = 2*(int)pow(2, x) - 1; 
 
    // Allocate memory
    int *st = new int[max_size];
 
    
    //st->segment tree
    //last parm = 0 -> current index
    constructSTUtil(arr, 0, n-1, st, 0);
 
    // Return the constructed segment tree
    return st;
}

int main()
{
	int arr[] = {1,3,5,7,9,11};
	int n = sizeof(arr)/sizeof(arr[0]);

	int *st = constructST(arr,n);
	cout<<getSum(st,n,1,3);

	


	return 0;
}
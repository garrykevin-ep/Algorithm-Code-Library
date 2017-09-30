/*
source : gog
*/
#include <iostream>
#include <vector>
using namespace std;
#define debug1(x) cout << #x << ": " << x << "\n";
#define debug2(x, y) cout << #x << ": " << x << '\t' << #y << ": " << y << "\n";
#define debug3(x, y, z) cout << #x << ": " << x << '\t' << #y << ": " << y << '\t' << #z << ": " << z << "\n";
#define foreach(i,n) for(__typeof((n).begin())i =(n).begin();i!=(n).end();i++)


// Binary search (note boundaries in the caller)
int CeilIndex(std::vector<int> &v, int l, int r, int key) {
    while (r-l > 1) {
    int m = l + (r-l)/2;
    if (v[m] >= key)
        r = m;
    else
        l = m;
    }
 
    return r;
}
 
/*
if greater than last element increase sub-seq
if middle replace with ceil
*/

/*
logical proof for replacing with small numbers maybe wrong
small numbers can be a potential candidate to start new sequence

*/
int LongestIncreasingSubsequenceLength(std::vector<int> &v) {
    if (v.size() == 0)
        return 0;
 
    std::vector<int> tail(v.size(), 0);
    int length = 1; // always points empty slot in tail
 
    tail[0] = v[0];
    for (size_t i = 1; i < v.size(); i++) {
        if (v[i] < tail[0])
            // new smallest value
            tail[0] = v[i];
        else if (v[i] > tail[length-1])
            // v[i] extends largest subsequence
            tail[length++] = v[i];
        else
            tail[CeilIndex(tail, -1, length-1, v[i])] = v[i];
    }
    
/*      
    dp:table stores the value least value of ith+1 length subsequence
    j++: 0  *i: 2
    j++: 1  *i: 5
    j++: 2  *i: 3
    j++: 3  *i: 7
    j++: 4  *i: 11
    j++: 5  *i: 8
    j++: 6  *i: 10
    j++: 7  *i: 13
    j++: 8  *i: 6    
*/
    int j=0;
    foreach(i,v)
      debug2(j++,*i);

    return length;
}
 
int main() {
    std::vector<int> v{ 2, 5, 3, 7, 11, 8, 10, 13, 6 };
    std::cout << "Length of Longest Increasing Subsequence is " << LongestIncreasingSubsequenceLength(v);
   return 0;
}

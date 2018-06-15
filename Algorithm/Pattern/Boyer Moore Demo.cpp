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

/* 
Boyer Moore Algorithm
bm is a improvment for navie method where shift factor is 1
iterate from last
if mismatch
increase shift by bmt
*/

void printText(char *a)
{
  for(int i =0 ; i < strlen(a) ; i++)
  {
    cout<<a[i];
  }
  cout<<endl;
}

void printIndex(char *a)
{
  for(int i =0 ; i < strlen(a) ; i++)
  {
    cout<<i;
  }
  cout<<endl;
}

void printShift (int shift)
{
  for(int i =0 ; i < shift ; i++)
  {
    cout<<" ";
  }
}


int main()
{
  
  char text[100] = {"tette"};
  char pattern[10] = {"te"};
  //bad match table
  int bmt[129];
  int  patLen =  strlen(pattern),textLen = strlen(text);


  //bmt 
  for(int i = 0 ; i < 129 ; i++ )
  {
    bmt[i] = strlen(pattern);
  }

  for(int i=0; i < patLen - 1 ; i++)
  {
    bmt[pattern[i]] =  strlen(pattern) - i - 1;
  }

  //print bmt
  // for(int i=0; i < patLen ; i++)
  // {
  //   debug2((char)pattern[i],bmt[pattern[i]]);
  //  }

  int shift = 0;

  //shift is the start index of mismatch
  while(textLen >= shift + patLen  )
  {   
      printIndex(text);
      printText(text);
      printShift(shift);
      printText(pattern);
      printShift(shift);
      printIndex(pattern);
      cout<<endl;
      int patternIndex;
      for(patternIndex = patLen - 1 ; patternIndex >= 0 ; patternIndex--)
      {
        if(text[shift + patternIndex ] != pattern[patternIndex])
        {
          shift += bmt[text[shift+patternIndex]];
          break;
        }
      }
      
      if(patternIndex == -1)
      {
        cout<<"Found "<<shift<<endl;
        shift++;  
      }

  }

  return 0;
}
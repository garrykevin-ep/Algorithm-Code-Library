#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

#define debug1(x) cout << #x << ": " << x << endl
#define debug2(x, y) cout << #x << ": " << x << '\t' << #y << ": " << y << endl
#define debug3(x, y, z) cout << #x << ": " << x << '\t' << #y << ": " << y << '\t' << #z << ": " << z << endl
/*
given a target 
find whether it is possible 
to make sum of from given elements

constraints : use one for loop 
*/

int findPossibility(int * arr, int length,int target);

void fillarray(int * a ,int n)
{
    static int i =0;
    if(i<n)
    {
        scanf("%d",a+i);
        i++;
        fillarray(a,n);
    }
}

int sum_index,sum;

int sum_arr(int * arr , int length)
{
    if(sum_index < length)
    {
        //debug2(sum_index,arr[sum_index]);
        sum += arr[sum_index];
        sum_index++;
        sum_arr(arr,length);  
    }
    return sum;
}

int cpy_i,cpy_new_i;
void cpy_arr(int * arr ,int * n_arr , int omit , int length)
{
    if(cpy_new_i < length)
    {
        if(cpy_i!=omit)
        {
            n_arr[cpy_new_i] = arr[cpy_i];
            cpy_new_i++;
        }
        cpy_i++;
        cpy_arr(arr,n_arr,omit,length);
    }
}

int findPossibility(int * arr,  int length,int target) 
{
    static int ans =0;
    
    sum_index=0,sum=0;
    int sum = sum_arr(arr,length),i=0;
   // debug2(sum,length);
   // cout<<"\n";
    if(sum == target || ans ==1)
     {
        ans=1;
        return ans;
    }
    
    if(length == 1)
        return 1;
    
    // cout<<"orgi array\n";
    // for(i=0;i<length;i++)
    // {
    //     debug2(i,arr[i]);
    // }
    // cout<<"\n";

    for(i=0;i<length;i++)
    {
        int j=0;
        n_arr = (int *) malloc(length*sizeof(int));
        cpy_i=0,cpy_new_i=0;
        cpy_arr(arr,n_arr,i,length-1);
        
        // debug1(i);
        // cout<<"new array\n";
        // for(j=0;j<length-1;j++)
        // {
        //     debug2(j,n_arr[j]);
        // }
        // cout<<"\n";


        findPossibility(n_arr,length-1,target);
    }

    return ans;
}


int main()
{
    int n, *arr, i, target;
    scanf("%d",&n);
    arr = (int *) malloc(n*sizeof(int));
    
    fillarray(arr,n);
    
    // int *n_arr;
    // n_arr = (int *) malloc(n*sizeof(int));
    // cpy_arr(arr,n_arr,5,n-1);
    // for(int i=0;i<n-1;i++)
    //     debug2(i,n_arr[i]);
    // cout<<sum_arr(n_arr,n-1);
   //debug1(sizeof(arr)/sizeof(arr[0]));

    scanf("%d",&target);
    if(findPossibility(arr,n,target) == 1)
    printf("Yes\n");
    else
    printf("No\n");
    return 0;
}


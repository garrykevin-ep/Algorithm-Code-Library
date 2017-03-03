//
//  prim.cpp
//  
//
//  Created by garry kevin on 19/10/16.
//
//

/*
see least in adj
min() finds least
make it known
if node exist and not known
    EDGE is less than prev
    upadate mins 
*/


#include <iostream>
#include<limits.h>
using namespace std;
bool known[5];
int dist[5];
int par[5];

int min()
{
    int min=INT_MAX;
    int min_index;
    for(int i=0;i<5;i++)
    {
        if(!known[i]&&dist[i]<min)
        {
            min = dist[i];
            min_index=i;
        }
    }
    cout<<"min  "<<min_index<<endl;
    return min_index;
}


void prim(int graph[5][5],int src)
{
    for(int i=0;i<5;i++)
    {
        known[i]=0;
        dist[i]=INT_MAX;
        par[i]=0;
    }
    dist[src]=0;
    for(int count=0;count<5;count++)
    {
        int index;
        index=min();
        known[index]=1;
        for(int i=0;i<5;i++)
        {
            if(graph[index][i]&&!known[i])
            {
                if(graph[index][i]<dist[i])
                {
                    dist[i]=graph[index][i];
                    par[i]=index;
                }
            }
        }
        
    }
}




int main()
{
    /* Let us create the following graph
     2    3
     (0)--(1)--(2)
     |   / \   |
     6| 8/   \5 |7
     | /     \ |
     (3)-------(4)
     9          */
    int graph[5][5] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0},
    };
    int src;
    cout<<"Enter Source";
    cin>>src;
    // Print the solution
    src = src;
    prim(graph,src);
    for(int i=0;i<5;i++)
        cout<<"vertex "<<i<<"   "<<dist[i]<<"  par--- "<<par[i]<<endl;
    

    return 0;
}

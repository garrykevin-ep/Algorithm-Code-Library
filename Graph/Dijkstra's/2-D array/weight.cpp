//
//
//
//
//  Created by garry kevin on 18/10/16.
//
//

/*
see least in adj
min() finds least
make it known
if node exist and not known
    path thorough the parent is less than prev
    upadate min 
*/

#include <iostream>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;
bool known[7];
int dis[7];
int par[7];//stores the index

int min()
{
    int min=INT_MAX;
    int min_index;
    for(int i=0;i<20;i++)
    {
        if(!known[i]&&dis[i]<min)
        {
            min = dis[i];
            min_index=i;
        }
    }
    cout<<"min  "<<min_index<<"  "<< min<<endl;
    return min_index;
}

void dijkstra(int graph[20][20],int src)
{
    
    for(int i=0;i<7;i++)
    {
        known[i]=0;
        dis[i]=INT_MAX;
        par[i]=0;
    }
    dis[src]=0;
    for(int count=0;count<20;count++)
    {
        //update dis of adj
        int index;
        index=min();
        known[index]=1;
        for(int i=0;i<20;i++)
        {
            if(graph[index][i]&&!known[i])
            {
                if(graph[index][i]+dis[index]<dis[i])
                {
                    par[i]=index;
                    dis[i]=graph[index][i]+dis[index];
                }
            }
        }
    }
}



int main()
{
    
    int graph[20][20]=
        {{0,28,5,48,66,0,2,0,28,33,0,46,0,0,34,0,20,46,0,0,},
{28,0,0,0,0,0,0,0,0,0,0,0,0,15,0,0,0,0,0,0,},
{5,0,0,0,0,0,10,0,0,0,0,0,0,27,0,0,0,0,0,0,},
{48,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
{66,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
{0,0,0,0,0,0,42,0,0,0,0,0,0,26,0,0,0,0,0,0,},
{2,0,10,0,0,42,0,0,21,0,0,13,66,54,0,21,0,0,52,0,},
{0,0,0,0,0,0,0,0,0,0,0,0,0,43,0,0,0,0,0,0,},
{28,0,0,0,0,0,21,0,0,0,0,0,0,34,0,0,0,0,0,0,},
{33,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
{0,0,0,0,0,0,0,0,0,0,0,0,0,64,0,0,0,0,0,0,},
{46,0,0,0,0,0,13,0,0,0,0,0,0,19,0,0,0,0,0,0,},
{0,0,0,0,0,0,66,0,0,0,0,0,0,0,0,0,0,0,0,0,},
{0,15,27,0,0,26,54,43,34,0,64,19,0,0,19,0,0,0,0,14,},
{34,0,0,0,0,0,0,0,0,0,0,0,0,19,0,0,0,0,0,0,},
{0,0,0,0,0,0,21,0,0,0,0,0,0,0,0,0,0,0,0,0,},
{20,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
{46,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,},
{0,0,0,0,0,0,52,0,0,0,0,0,0,0,0,0,0,0,0,0,},
{0,0,0,0,0,0,0,0,0,0,0,0,0,14,0,0,0,0,0,0,}};
    int s;
    //cout<<"Enter Source";
    //cin>>s;
    s=16;
    dijkstra(graph,s);
    for(int i=0;i<20;i++)
        cout<<"vertex "<<i+1<<"   "<<dis[i]<<"  par--- "<<par[i]+1<<endl;
    return 0;
}

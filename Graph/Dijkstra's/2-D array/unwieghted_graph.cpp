//
//  unwieghted_graph.cpp
//  
//
//  Created by garry kevin on 13/10/16.
//
//

/*
push the parent to the queue
explore its adj-vertex
push the adj-vertex to queue
do this unti queue empty
*/



#include <iostream>
#include<queue>
#include<algorithm>

using namespace std;
queue<int> q;
bool known[7];
int dis[7];
int par[7];//stores the index


void dijkstra(int graph[7][7],int src)
{
    for(int i=0;i<7;i++)
    {
        known[i]=0;
        dis[i]=0;
        par[i]=0;
    }
    q.push(src);
    dis[src]=0;
    par[src]=-1;
    while(!q.empty())
    {
        int index;
        index = q.front();
        known[index]=1;
        q.pop();
        for(int i =0;i<7;i++)
        {
            if(graph[index][i]==1 && !known[i])
            {
                q.push(i);
                dis[i]=1+dis[index];
                par[i]=index;
                known[i]=1;
            }
        }
    }
   
}



int main()
{
    
    int graph[7][7]=
    {{0,1,0,1,0,0,0},
    {0,0,0,1,1,0,0},
    {1,0,0,0,0,0,0},
    {0,0,1,1,1,1,1},
    {0,0,0,0,0,0,1},
    {0,0,0,0,0,0,0},
    {0,0,0,1,1,0,0}};
    int s;
    cout<<"Enter Source";
    cin>>s;
    s=s-1;
    dijkstra(graph,s);
    for(int i=0;i<7;i++)
    cout<<"vertex "<<i+1<<"   "<<dis[i]<<"  par--- "<<par[i]+1<<endl;
    
    return 0;
}





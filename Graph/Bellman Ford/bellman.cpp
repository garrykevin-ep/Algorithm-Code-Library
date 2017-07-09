#include<iostream>
#include<limits.h>
using namespace std;
#define node 5

bool known[node];
int par[node];
int dist[node];

void bmf(int graph[node][node])
{
	for (int i = 0; i < node; ++i)
	{
		known[i]=0;
		par[i]=0;
		dist[i]=INT_MAX;
	}
	int src=1;
    src=src-1;
	dist[src]=0;
	known[src]=1;
for (int count = 0; count < node; ++count)
{
	for(int index=0;index<node;index++)
	{
		if(known[index])
		{
			for(int i=0;i< node ;i++)
			{	
				if(graph[index][i])
				{
					if(graph[index][i]+dist[index]<dist[i])
					{
						if(node-1==count)
						cout<<"NO NOT POSSIBLE";
                    	dist[i]=graph[index][i]+dist[index];
					   	par[i]=index;
					   	known[i]=1;
					}
				}
			}

		}	
	}
}
}

int main()
{
	int graph[node][node]={{0,5,4,0},
						   {0,0,0,3},
						   {0,-6,0,0},
						   {0,0,2,0},
						   };
	bmf(graph);	
	for(int i=0;i<node;i++)
	cout<<dist[i]<<endl;
}

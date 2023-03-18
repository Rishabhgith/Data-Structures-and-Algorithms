#include<bits/stdc++.h>
# define v 4
# define INF 99999
using namespace std;
void printsolution(int g[v][v])
{
	for(int i=0; i<v; i++)
	{
		for(int j=0; j<v; j++)
		cout<<g[i][j]<<" ";
		
		cout<<endl;
	
	}
}
void floyd(int g[v][v])
{
	int dis[v][v];
	for(int i=0; i<v; i++)
	{
		for(int j=0; j<v; j++)
		dis[i][j]=g[i][j];
	}
	
for(int k=0; k<v; k++)
{
	for(int i=0; i<v; i++)
	{
		for(int j=0; j<v; j++)
		{
			if (dis[i][j] > (dis[i][k] + dis[k][j])
                    && (dis[k][j] != INF
                        && dis[i][k] != INF))
                    dis[i][j] = dis[i][k] + dis[k][j];
		}
	}
}
printsolution(dis);
}
int main()
{
	int graph[v][v] = { { 0, 5, INF, 10 },
                        { INF, 0, 3, INF },
                        { INF, INF, 0, 1 },
                        { INF, INF, INF, 0 } };
     floyd(graph);
    return 0;                   
}
#include<bits/stdc++.h>
using namespace std;
const int v=9;
int mi(bool proc[],int dis[],int N)
{
	int m;
	int k=INT_MAX;
	for(int i=0; i<N; i++)
	{
		if(proc[i] == false && dis[i]<k)
		{
			m=i;
			k=dis[m];
		}
	}
	return m;
}
void dijkstra(int a[v][v],int N,int src)
{
	bool proc[N];
	int dis[N];
	for(int i=0; i<N; i++)
	{
		proc[i]=false;
		dis[i]=INT_MAX;
	}
dis[src]=0;

for(int i=0; i<N-1; i++)
{
	int u=mi(proc,dis,N);
	proc[u]=true;
	
for(int x=0; x<N; x++)
{
	if(a[u][x])
	{
		if(dis[u]+a[u][x]<dis[x])
		dis[x]=dis[u]+a[u][x];
	}
}
}
 cout <<"Vertex \t Distance from Source" << endl;
    for (int i = 0; i < N; i++)
        cout  << i << " \t\t"<<dis[i]<< endl;

}
int main()
{
	
	int graph[v][v] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
    int src=0;
    dijkstra(graph,v,src);
 
}
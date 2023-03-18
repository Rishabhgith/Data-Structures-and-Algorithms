#include<bits/stdc++.h>
using namespace std;
void addEdge(vector<int>g[],int x,int y)
{
	g[x].push_back(y);
	g[y].push_back(x);
}
void APutil(vector<int> g[], int u, bool vis[],
            int disc[], int low[], int& time, int p,
            bool isAP[])
{
	int children =0;
	vis[u]=true;
	disc[u]=low[u]=++time;
	
	
for(auto v:g[u])
{
	 if (!vis[v]) {
            children++;
            APutil(g, v, vis, disc, low, time, u, isAP);
            
    low[u]=min(low[u],low[v]);
    if(p!=-1 && low[v]>=disc[u])
    isAP[u]=true;
    
}
else if(v!=p)
{
	low[u]=min(low[u],disc[v]);
}}
if(p==-1 && children>1)
isAP[u]=true;
}
            
            
void AP(vector<int>g[],int V)
{
	int disc[V]={-1};
	int low[V];
	bool vis[V]={false};
	bool isap[V]={false};
	int time=0,par=-1;
	
for(int i=0; i<V; i++)
{
	if(!vis[i])
	{
	 APutil(g, i, vis, disc, low,
                   time, par, isap);
	}
}
for (int u = 0; u < V; u++)
        if (isap[u] == true)
            cout << u << " ";
	
}
int main()
{
	int V=5;
	vector<int>g[V];
	addEdge(g, 1, 0);
    addEdge(g, 0, 2);
    addEdge(g, 2, 1);
    addEdge(g, 0, 3);
    addEdge(g, 3, 4);
    AP(g, V);
 
}
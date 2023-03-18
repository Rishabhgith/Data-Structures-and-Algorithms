#include<bits/stdc++.h>
using namespace std;
class graph
{
	int V;
	vector<int> *g;
	void dfs(int v,bool visited[]);
public:
graph(int V);
void addedge(int u,int w);
int findmother();
};
void graph::dfs(int y,bool visited[])
{
	visited[y]=true;
	for(auto x:g[y])
	{
		if(!visited[x])
		dfs(x,visited);
	}
}
graph::graph(int V)
{
	this->V=V;
	g=new vector<int>[V];
}
void graph::addedge(int u,int w)
{
	g[u].push_back(w);
}
int graph::findmother()
{
	bool visited[V]={false};
	int x;
	
for(int i=0; i<V; i++)
{
	if(visited[i]==false)
	{
		dfs(i,visited);
		x=i;
	}
}
visited[V]={false};
dfs(x,visited);
for(int i=0; i<V; i++)
{
	if(visited[i]==false)
	return -1;
}
return x;
}
int main()
{
	graph g(7);
	g.addedge(0, 1);
    g.addedge(0, 2);
    g.addedge(1, 3);
    g.addedge(4, 1);
    g.addedge(6, 4);
    g.addedge(5, 6);
    g.addedge(5, 2);
    g.addedge(6, 0);
 
    cout << "A mother vertex is " << g.findmother();
}
#include<bits/stdc++.h>
using namespace std;
class graph
{
	int V;
	vector<int>*g;
	bool dfs(int start,bool vis[],int parent);
	
public:
graph(int V);
void addEdge(int u,int v);
bool isCyclic();
};
graph::graph(int V)
{   this->V=V;
	g=new vector<int>[V];
}

void graph::addEdge(int u,int v)
{
	g[u].push_back(v);
	g[v].push_back(u);
}
bool graph::dfs(int start,bool vis[],int parent)
{
	vis[start]=true;
	for(auto node: g[start])
	{
		if(!vis[node])
		{
			if(dfs(node,vis,start))
			return true;
		}
		else if(node!=parent)
		return true;
	}
	return false;
}
bool graph::isCyclic()
{
	bool vis[]={false};
	
for(int i=0; i<V; i++)
{
	if(!vis[i])
	{
		if(dfs(i,vis,-1))
		return true;
	}
}
return false;
}

int main()
{
    graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 1);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    if(g1.isCyclic())
    cout<<"Cycle is present"<<endl;
    else
    cout<<"Cycle not present"<<endl;
}







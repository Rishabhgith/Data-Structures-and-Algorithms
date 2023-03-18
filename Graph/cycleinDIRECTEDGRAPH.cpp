#include<bits/stdc++.h>
using namespace std;
class graph
{
	int V;
	vector<int>*g;
	bool cycle(bool vis[],int start,bool anc[]);
	
public:
graph(int n);
void addEdge(int u,int v);
bool iscyclic();
};
bool graph::cycle(bool vis[],int start,bool anc[])
{
	vis[start]=true;
	anc[start]=true;
for(auto node:g[start])
{
	if(!vis[start])
	{
		if(cycle(vis,node,anc))
		return true;
	}
	else if(anc[node])
	return true;
}
anc[start]=false;
return false;
	
}

graph::graph(int V)
{
	this->V=V;
	g=new vector<int>[V];
}

void graph::addEdge(int u,int v)
{
	g[u].push_back(v);
}

bool graph::iscyclic()
{
	bool anc[V]={false};
	bool vis[V]={false};
for(int i=0; i<V; i++)
{
	if(!vis[i])
	{
		if(cycle(vis,i,anc))
		return true;
	}
}
return false;
	
}
int main()
{
	graph x(4);
	x.addEdge(0,1);
	x.addEdge(0,2);
	x.addEdge(1,2);
	x.addEdge(2,0);
	x.addEdge(2,3);
	x.addEdge(3,3);
	
if(x.iscyclic())
cout<<"Graph contains cycle"<<endl;
else
cout<<"Graph does not contain cycle"<<endl;
}






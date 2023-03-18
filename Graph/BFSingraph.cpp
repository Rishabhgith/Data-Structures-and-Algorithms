#include<bits/stdc++.h>
using namespace std;
void bfs(vector<int>g[],int n)
{
	queue<int>q;
	int vis[n]={0};
	q.push(2);
vis[2]=1;
vector<int>v;
while(!q.empty())
{
	int temp=q.front();
	q.pop();
	v.push_back(temp);
for(int j=0; j<(g[temp].size()); j++)
{
	if(!vis[g[temp][j]])
	{
		q.push(g[temp][j]);
		vis[g[temp][j]]=1;
	}
}
}
for(int i=0; i<n; i++)
cout<<v[i]<<" ";

}
void addEdge(vector<int>graph[],int u,int v)
{
	graph[u].push_back(v);
}
void printGraph(vector<int>graph[],int v)
{
	for(int i=0; i<v; i++)
	{   cout<<i<<": ";
		for(auto x:graph[i])
		{
		cout<<x<<" ";}
		cout<<endl;
	}
}
int main()
{
	int v;
	cin>>v;
	vector<int>graph[v];
	addEdge(graph,0,1);
	addEdge(graph,0,2);
	addEdge(graph,1,2);
	addEdge(graph,2,0);
	addEdge(graph,2,3);
	addEdge(graph,3,3);
	printGraph(graph,v);
	cout<<"\n BFS TRAVERSAL -";
    bfs(graph,v);		
}
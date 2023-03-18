#include<bits/stdc++.h>
using namespace std;
void bfs(vector<int>g[],int n)
{
	queue<int>q;
	int vis[n]={0};
	q.push(0);
vis[0]=1;
vector<int>v;
while(!q.empty())
{
	int temp=q.front();
	q.pop();
	v.push_back(temp);
for(auto x:g[temp])
{
	if(!vis[x])
	{
		q.push(x);
		vis[x]=1;
	}
}
}
for(int i=0; i<n; i++)
cout<<v[i]<<" ";

cout<<"\n";
}
void addEdge(vector<int>g[], int u,int v)
{
	g[u].push_back(v);
	g[v].push_back(u);
}
void printGraph(vector<int>g[],int n)
{   cout<<"\n";
	for(int i=0; i<n; i++)
	{  
		cout<<i<<"-: ";
		for(auto x: g[i]){
		cout<<x<<" ";}
		cout<<endl;
	}
}
void dfs(vector<int>g[],int n,int start,vector<int> &v,int vis[])
{
	v.push_back(start);
	vis[start]=1;
	for(auto x:g[start])
	{
		if(!vis[x])
		dfs(g,n,x,v,vis);
	}
}

int main()
{   int n;
	cout<<"\nEnter the number of nodes";
	cin>>n;
	vector<int>graph[n];
	cout<<"\n1) Enter the nodes between which you want edge\n 2)Display Graph\n 3)DFS Traversal \n4) BFS TRAVERSAL\n 5) EXIT";

	while(1)
	{int ch;
	
	cout<<"\nEnter your choice";
	cin>>ch;
	if(ch==1)
	{
		int u,v;
		cout<<"\nEnter the two nodes";
		cin>>u>>v;
		addEdge(graph,u,v);
	}
	else if(ch==2)
	{
		printGraph(graph,n);
	}
	else if(ch==3)
	{
		vector<int>v;
		int start=0;
		int vis[n]={0};
		dfs(graph,n,start,v,vis);
		cout<<"\n Depth first Traversal"<<endl;
		for(int i=0; i<n; i++)
		cout<<v[i]<<" ";
	}
	else if(ch==4)
	{
		cout<<"\n BFS TRAVERSAL -"<<endl;
    bfs(graph,n);
	}
	else if(ch==5)
	break;
	
}
}
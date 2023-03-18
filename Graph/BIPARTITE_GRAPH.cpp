// n-number of vertices   m-number of edges
#include<bits/stdc++.h>
using namespace std;
bool dfs(vector<int>g[],vector<int>&col,int start,int v,int cr)
{
	bool flag=true;
col[start]=cr;
for(auto node:g[start])
{
	if(col[node]==-1)
	{
		flag=dfs(g,col,node,v,1-cr);
		if(!flag)
		return false;
		else
		{
			if(col[node]==col[start])
			return false;
		}
	}
}
return true;
}
int main()
{    int n,m;
cin>>n>>m;
	vector<int> *adj;
	adj= new vector<int>[n];
for(int i=0; i<m; i++)
{
	int u,v;
	cin>>u>>v;
	adj[u].push_back(v);
	adj[v].push_back(u);
	
}
vector<int>colour(n,-1);
bool flag=true;
for(int i=0; i<n; i++)
{
	if(colour[i]==-1)
	{
		flag=dfs(adj,colour,i,n,0);
		if(!flag)
		{
			cout<<"NO";
			return 0;
		}
	}
}
cout<<"YES";
return 0;
}
#include<bits/stdc++.h>
using namespace std;
void dfs(vector<int>g[],int V,int start,bool vis[],stack<int>&s)
{
	vis[start]=true;
	for(auto node:g[start])
	{
		if(!vis[node])
		dfs(g,V,node,vis,s);
	}
	s.push(start);
}
int main()
{
	int n;
	cout<<"Enter the number of vertices"<<endl;
	cin>>n;
	bool vis[n]={false};
	int m;
	cout<<"Enter the number of edges"<<endl;
	cin>>m;
	vector<int>g[n];
	for(int i=0; i<m; i++)
	{
		int x,y;
		cin>>x>>y;
		g[x].push_back(y);
	}
stack<int>s;
for(int i=0; i<n; i++)
{
	if(vis[i]==false)
	dfs(g,n,i,vis,s);
}
while(!s.empty())
{
	cout<<s.top()<<" ";
	s.pop();
}
}
	
	
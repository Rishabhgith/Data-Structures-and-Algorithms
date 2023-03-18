#include<bits/stdc++.h>
using namespace std;
bool dfs(int u,vector<int>g[],bool vis[],int &count,int n)
{
	vis[u]=true;
	count++;
if(count==n)
return true;

for(auto v:g[u])
{
	bool flag=dfs(v,g,vis,count,n);
	if(flag)
	return true;
}
vis[u]=false;
return false;
}
int main()
{   int n;
vector<int>*g;
cin>>n;
g=new vector<int>[n];
cout<<"Enter the number of edges"<<endl;
int m;
cin>>m;
for(int i=0; i<m; i++)
{
	int u,v;
	cin>>u>>v;
	g[u].push_back(v);
	g[v].push_back(u);
}
bool vis[n]={false};
for(int i=0; i<n; i++)
{
	int count=0;
	bool f=false;
	f=dfs(i,g,vis,count,n);
	if(f){
	cout<<"TRUE"<<endl;
	return 0;
	}
}
cout<<"FALSE"<<endl;
return 0;
}
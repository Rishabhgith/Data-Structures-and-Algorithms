#include<bits/stdc++.h>
# define n 4
using namespace std;
void TSP(int u,bool vis[],int g[][n],int count,int &min_cost,int cur_cost)
{
	count++;
	vis[u]=true;
if(count==n)
{
	if(g[u][0] && cur_cost+g[u][0]<min_cost)
	{
		min_cost=cur_cost+g[u][0];
	}
	vis[u]=false;
	return;
}
for(int i=0; i<n; i++)
{
	if(g[u][i] && !vis[i])
	{
TSP(i,vis,g,count,min_cost,cur_cost+g[u][i]);
	}
}
vis[u]=false;
}

int main()
{   
	int matrix[n][n];
	cout<<"Enter the number of edges"<<endl;
	int m;
	cin>>m;
for(int i=0; i<n; i++)
{
	for(int j=0; j<n; j++)
	{
		if(i==j)
		matrix[i][j]=INT_MAX;
	}
}
	for(int i=0; i<m; i++)
	{
		int x,y;
		cin>>x>>y;
		int c;
		cin>>c;
		matrix[x][y]=c;
		matrix[y][x]=c;
	}
bool vis[n]={false};
int count=0;
int min_cost=INT_MAX;
int cur_cost=0;
TSP(0,vis,matrix,count,min_cost,cur_cost);
cout<<min_cost<<endl;	
}
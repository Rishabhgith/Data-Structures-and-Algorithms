
#include<bits/stdc++.h>
#define c 5
using namespace std;
void Bellman(vector<pair<int,int>>v,int n,int src,int g[c][c])
{
	vector<int>dis(n,INT_MAX);
	int e=v.size();
	dis[src]=0;
for(int i=0; i<n-1; i++)
{
	for(int j=0; j<e; j++)
	{
		int u=v[j].first;
		int w=v[j].second;
		
		if(dis[u]!=INT_MAX)
		{
			if(dis[u]+g[u][w]<dis[w])
			dis[w]=dis[u]+g[u][w];
		}
	}
}
for(int i=0; i<n; i++)
{
cout<<i<<" "<<dis[i]<<endl;
	}
}
int main()
{
	vector<pair<int,int>>v;
	cout<<"Enter the number of edges "<<endl;
	int z;
	cin>>z;
	for(int i=0; i<z; i++)
	{
		int a,b;
		cin>>a>>b;
		v.push_back(make_pair(a,b));
	}
	int graph[][5] = { { 0, 5, 3, 0, 0 }, { 0, 0, 0, 0, 4 },
                       { 0, -2, 0, 1, 0 }, { 0, 0, 0, 0, 4 },
                       { 0, 0, 0, 0, 0 } };
	
   Bellman(v,5,0,graph);
}

	
	
	
	
	

#include<bits/stdc++.h>
using namespace std;
void dfs(vector<int>g[],int start,int V,bool vis[],stack<int>&s)
{
	vis[start]=true;
	for(auto node:g[start])
	{
		if(!vis[node])
		dfs(g,node,V,vis,s);
	}
	s.push(start);
}
void topologicalsort(vector<int>g[],int n)
{
	bool vis[n]={false};
	stack<int>s;
	for(int i=0; i<n; i++)
	{
		if(!vis[i])
		{
			dfs(g,i,n,vis,s);
		}
	}
while (!s.empty())
    {
        cout << (char) ('a' + s.top()) << " ";
        s.pop();
    }
}
void printorder(string a[],int n,int k)
{
	vector<int>g[k];
	for(int i=0; i<n-1; i++)
	{
		string x=a[i];
		string y=a[i+1];
		int k=x.size(),q=y.size();
		int m=min(k,q);
		for(int j=0; j<m; j++)
		{
			if(x[j]!=y[j])
			{
				g[x[j]-'a'].push_back(y[j]-'a');
				break;
			}
		}
	}
topologicalsort(g,k);	

}
int main()
{
	string a[]={"baa", "abcd", "abca","cab","cad"};
	printorder(a,5,4);
	
}
//YOU HAVE GOT THIS QUESTION VERY EASILY IN THE PAST, SO JUST
//JUST TRY ONE MORE TIME NOW AGAIN
#include<bits/stdc++.h>
using namespace std;
class graph
{
	int V;
	vector<int>*g;
	void printallpathsutil(int,int,bool[],int[],int&);
public:
graph(int V);
void addedge(int v,int w);
void printallpaths(int s,int d);
};
graph::graph(int V)
{
	this->V=V;
	g=new vector<int>[V];
}

void graph::printallpathsutil(int s,int d,bool visited[],int path[],int &count)
{
	visited[s]=true;
	path[count]=s;
	count++;
	
if(s==d)
{
	for(int i=0; i<count; i++)
	{
		cout<<path[i]<<" ";
	}
	cout<<"\n";}
	
else
{
	for(auto node:g[s])
	{
		if(!visited[node])
		printallpathsutil(node,d,visited,path,count);
		
	}
}
count--;
visited[s]={false};
}

void graph::addedge(int v,int w)
{
	g[v].push_back(w);
}
void graph::printallpaths(int s,int d)
{
	bool visited[V]={false};
	int path[V]={0};
	int count=0;
printallpathsutil(s,d,visited,path,count);
}
int main()
{
	graph g(4);
	g.addedge(0, 1);
    g.addedge(0, 2);
    g.addedge(0, 3);
    g.addedge(2, 0);
    g.addedge(2, 1);
    g.addedge(1, 3);
    
    int s = 2, d = 3;
    cout << "Following are all different paths from " << s << " to " << d << endl;
    g.printallpaths(s, d);
}
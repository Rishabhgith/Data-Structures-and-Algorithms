#include<bits/stdc++.h>
# define n 30
using namespace std;
void exp_neighbour(int x,int y,int d1,int d2,queue<pair<int,int>>&q,bool vis[][n],int &flag)
{
	int cx[]={-1,-1,1,1,2,2,-2,-2};
	int cy[]={2,-2,2,-2,1,-1,-1,1};
for(int i=0; i<8; i++)
{
	if(x+cx[i]<0 || x+cx[i]>=n || y+cy[i]<0 || y+cy[i]>=n || vis[x+cx[i]][y+cy[i]])
	continue;
	if(x+cx[i]==d1 && y+cy[i]==d2)
	{
		flag=1;
		return;
	}
	else
	{
		q.push({x+cx[i],y+cy[i]});
		vis[x+cx[i]][y+cy[i]]=true;
	}
}
}
int minstep(int knightpos[],int targetpos[])
{   int count,steps=0;
	int s1=knightpos[0]-1;
	int s2=knightpos[1]-1;
	int d1=knightpos[0]-1;
	int d2=targetpos[1]-1;
	if(s1==d1 && s2==d2)
	return 0;
	
queue<pair<int,int>>q;
bool vis[n][n];
for(int i=0; i<n; i++)
{
	for(int j=0; j<n; j++)
	vis[i][j]=false;
}
q.push({s1,s2});
vis[s1][s2]=true;
count=q.size();
int flag=0;
while(count>0)
{  
for(int i=0; i<n; i++)
{
	pair<int,int>p=q.front();
	q.pop();
exp_neighbour(p.first,p.second,d1,d2,q,vis,flag);


if(flag)
return steps;
}
steps++;
count=q.size();
}
return -1;
}
	

	

int main()
{  
	int knightpos[]={1,1};
	int targetpos[]={30,30};
	cout<<minstep(knightpos,targetpos);
}
#include<bits/stdc++.h>
# define r 4
# define c 4
using namespace std;
void push_neighbour(pair<int,int>p,int matrix[r][c],queue<pair<int,int>>&q)
{
	int X=p.first;
	int Y=p.second;
	int x[]={-1,1,0,0};
	int y[]={0,0,-1,1};
for(int i=0; i<4; i++)
{
if(X+x[i]<0||X+x[i]>=r||Y+y[i]<0||Y+y[i]>=c||matrix[X+x[i]][Y+y[i]]!=1)
continue;
else
{
	q.push({X+x[i],Y+y[i]});
	matrix[X+x[i]][Y+y[i]]=2;
}
}
}
int rotOranges(int matrix[r][c])
{   int time=0;
	int count;
	queue<pair<int,int>>q;


for(int i=0; i<r; i++)
{
	for(int j=0; j<c; j++)
	{
		if(matrix[i][j]==2)
		q.push({i,j});
		
	}
}
count=q.size();
while(count>0)
{ for(int i=0; i<count; i++)
{
	pair<int,int>p=q.front();
	q.pop();
	push_neighbour(p,matrix,q);
}
count=q.size();
if(count>0)
time++;
}

for(int i=0; i<r; i++)
{
	for(int j=0; j<c; j++)
	if(matrix[i][j]==1)
	return -1;
}
return time;
}
int main()
{
int matrix[r][c] = { {0,0,0,1},
                    { 2,1,1,1 },
                    { 2,0,2,0 },
                    {1,1,0,2} };

cout << "Max time incurred: " << rotOranges(matrix);
	
}
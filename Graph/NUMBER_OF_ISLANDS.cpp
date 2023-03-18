#include<bits/stdc++.h>
# define r 5
# define c 5
using namespace std;
int issafe(int m[r][c],int row,int col,bool visited[r][c])
{
	return (row >= 0) && (row < r) && (col >= 0) && (col < c) && (m[row][col] && !visited[row][col]);
}
void DFS(int m[r][c],int row,int col,bool visited[r][c])
{
	static int rn[]={ -1, -1, -1, 0, 0, 1, 1, 1 };
	static int cn[]={ -1, 0, 1, -1, 1, -1, 0, 1 };
	
	visited[row][col]=true;
	for(int k=0; k<8; k++)
	{
		if(issafe(m,row+rn[k],col+cn[k],visited))
		DFS(m,row+rn[k],col+cn[k],visited);
	}
}
int countIslands(int m[r][c])
{
	bool visited[r][c];
    for(int i=0; i<r; i++)
    {
    	for(int j=0; j<c; j++)
    	{
    		visited[i][j]=false;
    	}
    }
int count=0;
for(int i=0; i<r; i++)
{
	for(int j=0; j<c; j++)
	{
		if(m[i][j] && !visited[i][j])
		{
			DFS(m,i,j,visited);
			count++;
		}
	}
}
return count;
}
int main()
{
	int m[r][c] = { { 1, 1, 0, 0, 0 },
                     { 0, 1, 0, 0, 1 },
                     { 1, 0, 0, 1, 1 },
                     { 0, 0, 0, 0, 0 },
                     { 1, 0, 1, 0, 1 } };
                    
cout<<"Number of Islands are: "<<countIslands(m);
return 0;
}

#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>result;
bool isSafe(vector<vector<int>>board,int row,int col)
   {
       int i,j;
       int N = board.size();
       for(i=0; i<col; i++)
       {
           if(board[row][i])
           return false;
       }
       
       for(i = row, j = col; i>=0&&j>=0; i--, j--)
       {
           if(board[i][j])
           return false;
       }
       
       for(i=row, j=col; i<N && j>=0; i++,j--)
       {
           if(board[i][j])
           return false;
       }
       
       return true;
   }
   
   bool solveNQUtil(vector<vector<int>>& board, int col)
   {
       int N = board.size();
       if(col==N)
       {
           vector<int>v;
           for(int i=0; i<N; i++)
           {
               for(int j=0; j<N; j++)
               {
                   if(board[i][j]==1)
                   {
                       v.push_back(j+1);
                   }
               }
           }
          result.push_back(v);
          return true;
       }
       
       bool res = false;
       for(int i=0; i<N; i++)
       {
           if(isSafe(board,i,col))
           {
               board[i][col] = 1;
               
               res = solveNQUtil(board,col+1) || res;
               board[i][col] = 0;
           }
       }
       return res;
    }
 
    vector<vector<int>> nQueen(int n) 
    {
        vector<vector<int>> board(n, vector<int>(n,0));
        if(solveNQUtil(board,0)==false)
        return {};
        
        sort(result.begin(),result.end());
        return result;
    }
int main()
{
	cout<<"Enter the size"<<endl;
	int n;
	cin>>n;
	nQueen(n);
	for(auto v:result)
	{
		for(auto x:v)
		cout<<x<<" ";
		cout<<endl;
	}
}
#include<bits/stdc++.h>
# define m 8
# define n 8
using namespace std;
void floodfillutil(int screen[m][n],int x,int y,int prevc,int newc)
{
	if(x<0|| x>=m || y<0 || y>=n)
	return ;
	if(screen[x][y]!=prevc)
	return;
	if(screen[x][y]==newc)
	return;
	
screen[x][y]=newc;

floodfillutil(screen, x+1, y, prevc, newc);
floodfillutil(screen, x-1, y, prevc, newc);
floodfillutil(screen, x, y+1, prevc, newc);
floodfillutil(screen, x, y-1, prevc, newc);
}
void floodfill(int screen[m][n],int x,int y,int newc)
{
	int prevc=screen[x][y];
	if(prevc==newc)
	return;
	floodfillutil(screen,x,y,prevc,newc);
}
int main()
{
	int screen[m][n] = {{1, 1, 1, 1, 1, 1, 1, 1},
                      {1, 1, 1, 1, 1, 1, 0, 0},
                      {1, 0, 0, 1, 1, 0, 1, 1},
                      {1, 2, 2, 2, 2, 0, 1, 0},
                      {1, 1, 1, 2, 2, 0, 1, 0},
                      {1, 1, 1, 2, 2, 2, 2, 0},
                      {1, 1, 1, 1, 1, 2, 1, 1},
                      {1, 1, 1, 1, 1, 2, 2, 1},
                     };
int x=4,y=4;
int newc=3;
floodfill(screen,x,y,newc);
cout << "Updated screen after call to floodFill: \n";
    for (int i=0; i<m; i++)
    {
        for (int j=0; j<n; j++)
           cout << screen[i][j] << " ";
        cout << endl;
    }
}

#include<bits/stdc++.h>
using namespace std;
bool canrepresentbst(int pre[],int n)
{   
    int p=INT_MIN;
	stack<int>s;
for(int i=0; i<n; i++)
{
	while(!s.empty() && s.top()<pre[i])
	{
	  p=s.top();
	  s.pop();
	}
	if(pre[i]<p)
	return false;
	s.push(pre[i]);
}
return true;
}
int main()
{
	int pre[]={40,30,35,80,100};
	int n=sizeof(pre)/sizeof(pre[0]);
	cout<<canrepresentbst(pre,n)<<endl;
}
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a[]={1,2,3,1,3,6,6};
	set<int>s;
	int n=sizeof(a)/sizeof(a[0]);
	for(int i=0; i<n; i++)
	{
		if(s.find(a[i])!=s.end())
		{
			cout<<a[i]<<" ";
		}
		s.insert(a[i]);
	}
}
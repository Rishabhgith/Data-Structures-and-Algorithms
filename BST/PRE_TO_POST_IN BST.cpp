#include<bits/stdc++.h>
using namespace std;
int nextgreater(int a[],int l,int r)
{   int i;
	for(i=l; i<=r; i++)
	{
		if(a[i]>a[l])
		return i;
	}
	return i;
}
void pretopost(int a[],int l,int r,vector<int>&v)
{
	if(l>r)
	return;
	int g=nextgreater(a,l,r);
	pretopost(a,l+1,g-1,v);
	pretopost(a,g,r,v);
	v.push_back(a[l]);
}
int main()
{
	int a[]={40,30,35,80,100};
	int n=sizeof(a)/sizeof(a[0]);
	int l=0;
	int r=n-1;
	vector<int>v;
	pretopost(a,l,r,v);
	for(auto x:v)
	cout<<x<<" ";
}
#include<bits/stdc++.h>
using namespace std;
int findnextsmaller(int a[],int l,int r)
{
	int i;
	for(i=r; i>=l; i--)
	{
		if(a[i]<a[r])
		return i;
	}
	return i;
}
void posttopre(int a[],int l,int r,vector<int>&v)
{
	if(l>r)
	return;
	int s=findnextsmaller(a,l,r);
	v.push_back(a[r]);
	posttopre(a,l,s,v);//LEFT SUBTREE
	posttopre(a,s+1,r-1,v);//RIGHT SUBTREE
}
int main()
{
	int a[]={35,30,100,80,40};
	vector<int>v;
	int l=0;
	int size=sizeof(a)/sizeof(a[0]);
	int r=size-1;
	posttopre(a,l,r,v);
	for(auto x:v)
	cout<<x<<" ";
}
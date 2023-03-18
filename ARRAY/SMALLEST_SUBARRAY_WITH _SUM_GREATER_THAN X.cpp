#include<bits/stdc++.h>
using namespace std;
int ms(int a[],int n,int x)
{
	int start=0;
	int end=0;
	int len=INT_MAX;
	int sum=0;
while(end<n)
{
	while(sum<=x && end<n)
	sum+=a[end++];
	
	while(sum>x && start<n)
	{
		if(end-start<len)
		len=end-start;
		
		sum-=a[start++];
	}
}
return len;
}
int main()
{
	int a[]={1,4,45,6,0,19};
	int n=sizeof(a)/sizeof(a[0]);
	int x=51;
	cout<<ms(a,n,x);
}
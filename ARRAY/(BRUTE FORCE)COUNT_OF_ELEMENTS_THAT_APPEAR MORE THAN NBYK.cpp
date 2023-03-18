#include<bits/stdc++.h>
using namespace std;
int countelements(int a[],int n,int k)
{
	sort(a,a+n);
int c=0,s=0;
for(int i=0; i<n-1; i++)
{
	if(a[i]==a[i+1])
	c++;
	else
	{
		if(c+1>(n/k))
		s++;
		c=0;
	}
}
return s;
}
int main()
{
   int a[]={1, 1, 2, 2, 3, 5, 4, 2, 2, 3, 1, 1, 1};
   int n=sizeof(a)/sizeof(a[0]);
   int k=4;
   int count=countelements(a,n,k);
   cout<<count<<endl;
}
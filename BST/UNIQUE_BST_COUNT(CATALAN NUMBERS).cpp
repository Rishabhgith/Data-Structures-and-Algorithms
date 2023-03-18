#include<bits/stdc++.h>
using namespace std;
int uniquebst(int n)
{
	if(n==0 || n==1)
	return 1;
	int count=0;
	for(int i=1; i<=n; i++)
	{
		count+=uniquebst(i-1)*uniquebst(n-i);
	}
	return count;
}
int main()
{
	int n=3;
	cout<<uniquebst(n)<<endl;
}
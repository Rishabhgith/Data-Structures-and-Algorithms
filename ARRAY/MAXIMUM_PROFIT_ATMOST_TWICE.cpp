#include<bits/stdc++.h>
using namespace std;
int maxprofit(int price[],int n)
{
	int profit[n];
for(int i=0; i<n; i++)
profit[i]=0;
int maxprice=price[n-1];
for(int i=n-2; i>=0; i--)
{
	if(price[i]>maxprice)
	maxprice=price[i];
	profit[i]=max(profit[i+1],maxprice-price[i]);
}
int minprice=price[0];
for(int i=1; i<n; i++)
{
	if(price[i]<minprice)
	minprice=price[i];
	profit[i]=max(profit[i-1],profit[i]+(price[i]-minprice));
}
int result=profit[n-1];
return result;
}
int main()
{
	int price[]={10,22,5,75,65,80};
	int n=sizeof(price)/sizeof(price[0]);
	cout<<maxprofit(price,n)<<endl;
}
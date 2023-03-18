#include<bits/stdc++.h>
using namespace std;
void subsets(int i ,int arr[], int n ,set<vector<int>>&s,vector<int>&curr)
{
	if(i == n)
	{
		s.insert(curr);
		return;
	}
	subsets(i+1,arr,n,s,curr);
	curr.push_back(arr[i]);
	subsets(i+1,arr,n,s,curr);
	curr.pop_back();
}
int main()
{
	int n;
	cout<<"Enter the number of elements: "<<endl;
	cin>>n;
	int arr[n];
	cout<<"Enter the elements"<<endl;
	for(int i = 0; i<n; i++)
	cin>>arr[i];
	vector<int>curr;
	set<vector<int>>s;
	subsets(0,arr,n,s,curr);
	for(auto x:s)
	{
		for(auto y:x)
		cout<<y<<" ";
		cout<<endl;
	}
}
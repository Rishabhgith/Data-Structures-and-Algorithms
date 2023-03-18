#include<bits/stdc++.h>
using namespace std;
void permutations(int pos, int len, string &curr, set<string>&s)
{
	if(pos == len-1)
	{
		s.insert(curr);
		return;
	}
	int i;
	for(i = pos; i<=len-1; i++)
	{
		swap(curr[pos],curr[i]);
		permutations(pos+1,len,curr,s);
		swap(curr[pos],curr[i]);
	}
}
void print(set<string>s)
{
	for(auto x:s)
	{
		cout<<x<<endl;
	}
}
int main()
{
	string curr;
	cout<<"Enter the string"<<endl;
	cin>>curr;
	int len = curr.size();
	set<string>s;
	permutations(0,len,curr,s);
	print(s);
	return 0;
}
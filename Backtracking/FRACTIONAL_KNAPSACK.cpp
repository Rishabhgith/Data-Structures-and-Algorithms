#include<bits/stdc++.h>
using namespace std;
int main()
{
	cout<<"Enter the number of elements"<<endl;
	int n;
	cin>>n;
	cout<<"Enter total weight"<<endl;
	int m;
	cin>>m;
	vector<pair<float,pair<int,int>>>p;
	for(int i = 0; i<n; i++)
	{   
	    int a,b;
	    float temp;
		cout<<"Enter the weight of element "<<i<<endl;
		cin>>a;
		cout<<"Enter the profit of element "<<i<<endl;
		cin>>b;
		temp = b/float(a);
		p.push_back({temp,{a,b}});
	}
	sort(p.begin(),p.end());
	for(int i = 0; i<n; i++)
	{
		cout<<p[i].first<<" "<<p[i].second.first<<" "<<p[i].second.second<<endl;
	}
     float s = 0;
     for(int i = n-1; i>=0; i--)
     {
     	int currw = p[i].second.first;
     	int currp = p[i].second.second;
     	if(currw<=m)
     	{
     		s+=currp;
     		m = m - currw;
     		cout<<"Item selected "<<(n-(i+1))<<endl;
     	}
     	else 
     	{
     		float f = m/(float)currw;
     		s+=currp*f;
     		cout<<"Item selected "<<(n-(i+1))*f<<endl;
     		break;
     	}
     }
     cout<<"Total Profit "<<s<<endl;
}
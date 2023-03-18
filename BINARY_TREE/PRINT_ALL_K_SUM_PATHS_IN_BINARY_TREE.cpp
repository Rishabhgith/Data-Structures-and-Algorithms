#include<bits/stdc++.h>
using namespace std;
struct node
{
	int val;
	node *right;
	node *left;
};
node *addnode(int data)
{
	node *t=new node();
	t->val=data;
	t->left=NULL;
	t->right=NULL;
	return t;
}
void printvector(vector<int>v,int j)
{
	for(int i=j; i<v.size(); i++)
	{
		cout<<v[i]<<" ";
	}cout<<endl;
}
void printkpaths(node *root,int k,vector<int>&v)
{
	if(!root)
	return;
	v.push_back(root->val);
	printkpaths(root->left,k,v);
	printkpaths(root->right,k,v);
	int f=0;
	for(int i=v.size()-1; i>=0; i--)
	{
		f=f+v[i];
		if(f==k)
		{
			printvector(v,i);
		}
	}
	v.pop_back();
}
int main()
{
	node *root=addnode(1);
	root->left=addnode(7);
	root->right=addnode(3);
	root->right->left=addnode(5);
	root->right->right=addnode(4);
	vector<int>v;
	int k=8;
	printkpaths(root,k,v);
}

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
	t->right=NULL;
	t->left=NULL;
	return t;
}

void kdistance(node *root,int k,vector<int>&v)
{
	if(!root)
	return;
	if(k==0)
	{
		v.push_back(root->val);
		return;
	}
	kdistance(root->left,k-1,v);
	kdistance(root->right,k-1,v);
}
int main()
{
	node *root=addnode(1);
	root->left=addnode(2);
	root->left->left=addnode(4);
	root->left->right=addnode(5);
	root->left->right->right=addnode(6);
	root->right=addnode(3);
	root->right->right=addnode(7);
	root->right->right->right=addnode(8);
	vector<int>v;
	int k=2;
	kdistance(root,k,v);
	for(auto x:v)
	cout<<x<<" ";
}
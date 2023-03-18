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
void preorder(node *root,map<int,vector<int>>&m,int d)
{
	if(!root)
	return;
	
	m[d].push_back(root->val);
	preorder(root->left,m,d+1);
	preorder(root->right,m,d);
	
}
void diagonal(node *root)
{
	map<int,vector<int>>m;
	int d=0;
	preorder(root,m,d);
	vector<int>v;
	for(auto it:m)
	{
		for(auto x:it.second)
		v.push_back(x);
	}
for(auto x:v)
cout<<x<<" ";
}
int main()
{
	node *root=addnode(1);
	root->left=addnode(2);
	root->left->left=addnode(4);
	root->left->right=addnode(5);
	root->right=addnode(3);
	root->right->left=addnode(6);
	root->right->right=addnode(7);
	
  diagonal(root);
}
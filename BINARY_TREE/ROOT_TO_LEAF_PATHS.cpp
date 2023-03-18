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

void pathsutil(node *root,vector<vector<int>>&v,vector<int>&currpath)
{
	if(!root)
	return;
	currpath.push_back(root->val);
	if(!root->right && !root->left)
	v.push_back(currpath);
	pathsutil(root->left,v,currpath);
	pathsutil(root->right,v,currpath);
	currpath.pop_back();
}
vector<vector<int>> paths(node *root)
{
	vector<vector<int>>v;
	vector<int>currpath;
	pathsutil(root,v,currpath);
	return v;
}
int main()
{
	node *root=addnode(1);
	root->left=addnode(2);
	root->right=addnode(3);
	root->right->right=addnode(7);
	root->left->left=addnode(4);
	root->left->right=addnode(5);
	vector<vector<int>>v=paths(root);
	for(auto x:v)
	{
		for(auto z:x)
		cout<<z<<" ";
		cout<<endl;
	}
}
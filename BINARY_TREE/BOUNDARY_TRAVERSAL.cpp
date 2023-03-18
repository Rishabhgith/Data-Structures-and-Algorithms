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
void leftboundary(node *root,vector<int>&v)
{
	if(!root)
	return;
	if(root->left || root->right)
	v.push_back(root->val);
	if(root->left)
	leftboundary(root->left,v);
	else if(root->right)
	leftboundary(root->right,v);
}

void rightboundary(node *root,vector<int>&v)
{
	if(!root)
	return;
	if(root->right)
	rightboundary(root->right,v);
	else if(root->left)
	rightboundary(root->left,v);
	
	if(root->left || root->right)
	v.push_back(root->val);
	
}

void leafnodes(node *root,vector<int>&v)
{
	if(!root)
	return;
	leafnodes(root->left,v);
	if(!root->left && !root->right)
	v.push_back(root->val);
	leafnodes(root->right,v);
}
vector<int> boundarytraversal(node *root)
{
	vector<int>v;
	if(!root)
	return v;
	v.push_back(root->val);
	if(!root->left && !root->right)
	return v;
	leftboundary(root->left,v);
	leafnodes(root,v);
	rightboundary(root->right,v);
	return v;
}

int main()
{
	node *root=addnode(1);
	root->left=addnode(2);
	root->left->right=addnode(3);
	root->left->right->left=addnode(4);
	root->right=addnode(5);
	root->right->left=addnode(8);
	root->right->right=addnode(6);
	root->right->right->left=addnode(7);
	root->right->right->left->left=addnode(9);
	vector<int>v=boundarytraversal(root);
	for(auto x:v)
	cout<<x<<" ";
}

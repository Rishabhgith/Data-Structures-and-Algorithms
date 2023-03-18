#include<bits/stdc++.h>
using namespace std;
struct node
{
	int val;
	node *right;
	node *left;
};
node *newnode(int data)
{
	node *t=new node();
	t->val=data;
	t->right=NULL;
	t->left=NULL;
	return t;
}
void preorder(node *root,vector<int>&v)
{
	if(root==NULL)
	return;
	stack<node *>s;
	s.push(root);
	while(!s.empty())
	{
		node *temp=s.top();
		s.pop();
		v.push_back(temp->val);
		if(temp->right!=NULL)
		s.push(temp->right);
		if(temp->left!=NULL)
		s.push(temp->left);
	}
}
int main()
{
	node *root=newnode(1);
	root->left=newnode(3);
	root->right=newnode(7);
	root->left->left=newnode(6);
	root->left->right=newnode(4);
	root->right->left=newnode(8);
	root->right->right=newnode(2);
	vector<int>v;
	preorder(root,v);
	for(auto x:v)
	cout<<x<<" ";
}
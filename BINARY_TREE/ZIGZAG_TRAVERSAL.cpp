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
	t->left=NULL;
	t->right=NULL;
	return t;
}
void spiral(node *root,vector<int>&v)
{
	stack<node*>s1;
	stack<node*>s2;
	s1.push(root);
while(!s1.empty() || !s2.empty())
{
	while(!s1.empty())
	{
		node *temp=s1.top();
		v.push_back(temp->val);
		if(temp->right)
		s2.push(temp->right);
		if(temp->left)
		s2.push(temp->left);
		s1.pop();
	}
	while(!s2.empty())
	{
		node *temp=s2.top();
		v.push_back(temp->val);
		if(temp->left)
		s1.push(temp->left);
		if(temp->right)
		s1.push(temp->right);
		s2.pop();
	}
}
}
int main()
{
	node *root=newnode(1);
	root->left=newnode(2);
	root->right=newnode(3);
	root->left->left=newnode(4);
	root->left->right=newnode(5);
	root->right->left=newnode(6);
	root->right->right=newnode(7);
	
	vector<int>v;
	spiral(root,v);
	for(auto x:v)
	cout<<x<<" ";
}
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
	node *temp=new node();
	temp->val=data;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}
void preorder(node *root,vector<int>&u)
{
	if(!root)
	return;
	u.push_back(root->val);
	preorder(root->left,u);
	preorder(root->right,u);
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
	
	vector<int>u;
	preorder(root,u);
	for(auto x:u)
	cout<<x<<" ";
}
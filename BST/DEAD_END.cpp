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
node *insert(node *root,int data)
{
	if(!root)
	{
		root=addnode(data);
		return root;
	}
	if(data<root->val)
	root->left=insert(root->left,data);
	else if(data>root->val)
	root->right=insert(root->right,data);
	return root;
}
void deadend(node *root,int l,int r,bool &flag)
{
	if(!root)
	return;
	if(flag)
	return;
	if(!root->left && !root->right)
	{
		if(l==r || r==1)
		{
			flag=true;
			return;
		}
	}
	deadend(root->left,l,root->val-1,flag);
	deadend(root->right,root->val+1,r,flag);
	
}
int main()
{
	node *root=NULL;
	root=insert(root,25);
	root=insert(root,18);
	root=insert(root,17);
	root=insert(root,20);
	root=insert(root,19);
	root=insert(root,30);
	root=insert(root,35);
	int l=INT_MIN;
	int r=INT_MAX;
	bool flag=false;
	deadend(root,l,r,flag);
	cout<<flag;
}
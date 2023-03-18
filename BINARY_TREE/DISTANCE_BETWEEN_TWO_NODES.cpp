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
node *lca(node *root,int a,int b)
{
	if(!root)
	return NULL;
	if(root->val==a || root->val==b)
	return root;
	node *left=lca(root->left,a,b);
	node *right=lca(root->right,a,b);
	if(left && right)
	return root;
	if(left)
	return left;
	if(right)
	return right;
	return NULL;
}
int DIS(node *root,int a,int level)
{
	if(!root)
	return -1;
	if(root->val==a)
	return level;
	int left=DIS(root->left,a,level+1);
	if(left==-1)
	{
	return DIS(root->right,a,level+1);
	}
	return left;
}
int main()
{
	node *root=addnode(1);
	root->left=addnode(2);
	root->left->left=addnode(4);
	root->left->right=addnode(5);
	root->left->left->left=addnode(6);
	root->left->left->right=addnode(7);
	root->right=addnode(3);
	int a=6,b=5;
	node *l=lca(root,a,b);
	int dis=DIS(l,a,0)+DIS(l,b,0);
	cout<<dis<<endl;
}
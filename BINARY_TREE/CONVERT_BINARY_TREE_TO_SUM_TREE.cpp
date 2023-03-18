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
void inorder(node *root)
{
	if(!root)
	return;
	inorder(root->left);
	cout<<root->val<<" ";
	inorder(root->right);
}
int transform(node *root)
{
	if(!root)
	return 0;
	int lsum=transform(root->left);
	int rsum=transform(root->right);
	int value=root->val+lsum+rsum;
	root->val=lsum+rsum;
	return value;
}
int main()
{
	node *root=addnode(10);
	root->left=addnode(-2);
	root->right=addnode(6);
	root->left->left=addnode(8);
	root->left->right=addnode(-4);
	root->right->left=addnode(7);
	root->right->right=addnode(5);
	int x=transform(root);
	cout<<x<<endl;
	inorder(root);
	
}
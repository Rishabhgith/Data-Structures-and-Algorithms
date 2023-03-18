#include<bits/stdc++.h>
using namespace std;
struct node
{
	int val;
	node *left;
	node *right;
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
	node *l=lca(root->left,a,b);
	node *r=lca(root->right,a,b);
	if(l&&r)
	return root;
	if(l)
	return l;
	if(r)
	return r;
	return NULL;
	
}
int main()
{
	node *root=addnode(1);
	root->left=addnode(2);
	root->right=addnode(3);
	root->left->left=addnode(4);
	root->left->right=addnode(5);
	root->right->left=addnode(6);
	root->right->right=addnode(7);
	int a=6;
	int b=7;
	node* ans=lca(root,a,b);
	cout<<ans->val<<endl;
}
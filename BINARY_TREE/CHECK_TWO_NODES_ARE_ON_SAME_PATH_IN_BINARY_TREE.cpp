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
node *lca(node *root,int a,int b,bool &flag)
{
	if(!root)
	return NULL;
	if(root->val==a || root->val==b)
	return root;
	node *l=lca(root->left,a,b,flag);
	node *r=lca(root->right,a,b,flag);
	if(l && r)
	{
		flag=false;
		return root;
	}
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
	root->left->left=addnode(4);
	root->left->right=addnode(5);
	root->left->left->left=addnode(9);
	root->left->right->left=addnode(8);
	root->right=addnode(3);
	root->right->left=addnode(6);
	root->right->right=addnode(7);
	int a=5,b=6;
	bool flag=true;
	node *x=lca(root,a,b,flag);
	cout<<x->val<<endl;
	cout<<flag;
}
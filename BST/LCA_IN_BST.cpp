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
	root->left= insert(root->left,data);
	else if(data>root->val)
	root->right=insert(root->right,data);
	return root;
}
node *lca(node *root,int a,int b)
{
	if (!root)
	return NULL;
    if(a<root->val && b<root->val)
	return lca(root->left,a,b);
    if (a>root->val && b>root->val)
	return lca(root->right,a,b);
	return root;
}
int main()
{
	node *root=NULL;
	root=insert(root,50);
	root=insert(root,30);
	root=insert(root,10);
	root=insert(root,40);
	root=insert(root,5);
	root=insert(root,35);
	root=insert(root,70);
	root=insert(root,80);
	root=insert(root,75);
	int a=70,b=80;
	node *ans=lca(root,a,b);
	cout<<ans->val<<endl;
}

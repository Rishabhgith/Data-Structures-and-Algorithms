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
void countnodes(node *root,int l,int r,int &count)
{
	if(!root)
	return;
	if(root->val>=l && root->val<=r)
	count++;
	if(root->val>l)
	countnodes(root->left,l,r,count);
	if(root->val<r)
	countnodes(root->right,l,r,count);
}
int main()
{
	node *root=NULL;
	root=insert(root,40);
	root=insert(root,20);
	root=insert(root,10);
	root=insert(root,25);
	root=insert(root,22);
	root=insert(root,50);
	root=insert(root,45);
	root=insert(root,70);
	root=insert(root,47);
	int l=20,r=40;
	int count=0;
	countnodes(root,l,r,count);
	cout<<count<<endl;
	
	
}
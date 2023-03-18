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
void inorder(node *root,int &value,int &k)
{
	if(!root)
	return;
	if(k<=0)
	return;
	inorder(root->left,value,k);
	k--;
	if(k==0)
	{
		value=root->val;
		return;
	}
	inorder(root->right,value,k);
}
int main()
{
	node *root=NULL;
	root=insert(root,1);
	root=insert(root,2);
	root=insert(root,3);
	int value=-1;
	int k=5;
	inorder(root,value,k);
	cout<<value<<endl;
}
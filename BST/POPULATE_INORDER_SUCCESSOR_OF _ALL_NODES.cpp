#include<bits/stdc++.h>
using namespace std;
struct node
{
	int val;
	node *right;
	node *left;
	node *next;
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
void solve(node *root,node *&prev)
{
	if(!root)
	return;
	solve(root->left,prev);
	if(prev)
	prev->next=root;
	prev=root;
	solve(root->right,prev);
}
void display(node *root)
{
	if(!root)
	return;
	display(root->left);
	cout<<root->val<<" ";
	if(root->next==NULL)
	cout<<-1;
	display(root->right);
}
int main()
{
	node *root=NULL;
	root=insert(root,10);
	root=insert(root,8);
	root=insert(root,3);
	root=insert(root,12);
	node *prev=NULL;
	solve(root,prev);
	display(root);
}
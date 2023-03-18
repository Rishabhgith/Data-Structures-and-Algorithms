#include<bits/stdc++.h>
using namespace std;
struct node
{
	int val;
	node *right;
	node *left;
};
node *create(int data)
{
	node *t=new node();
	t->val=data;
	t->left=NULL;
	t->right=NULL;
	return t;
}
node *insert(node *root,int data)
{
	if(!root)
	{
		root=create(data);
		return root;
	}
	if(data<root->val)
	{
		root->left=insert(root->left,data);
	}
	else if(data>root->val)
	{
		root->right=insert(root->right,data);
	}
	return root;
}
void level(node *root)
{
	if(!root)
	return;
	queue<node*>q;
	q.push(root);
	while(!q.empty())
	{
		node *temp=q.front();
		q.pop();
		cout<<temp->val<<" ";
		if(temp->left)
		q.push(temp->left);
		if(temp->right)
		q.push(temp->right);
	}
	cout<<endl;
}
bool search(node *root,int x)
{
	if(!root)
	{
		return false;
	}
	if(root->val==x)
	return true;
	if(x<root->val)
	return search(root->left,x);
	if(x>root->val)
	return search(root->right,x);
}
int main()
{
	node *root=NULL;
	root=insert(root,15);
	root=insert(root,10);
	root=insert(root,20);
	root=insert(root,8);
	root=insert(root,12);
	root=insert(root,17);
	root=insert(root,25);
	
	level(root);
	int x=17;
	cout<<search(root,x);
}
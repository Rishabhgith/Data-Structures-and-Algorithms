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
	t->right=NULL;
	t->left=NULL;
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
int minelement(node *root)
{
	while(root->left)
	root=root->left;
	return root->val;
}
int maxelement(node *root)
{
	while(root->right)
	root=root->right;
	return root->val;
}
int main()
{
	node *root=NULL;
	root=insert(root,70);
	root=insert(root,60);
	root=insert(root,55);
	root=insert(root,65);
	root=insert(root,80);
	root=insert(root,75);
	root=insert(root,85);
	level(root);
	cout<<"MINIMUM ELEMNT- "<<minelement(root)<<endl;
	cout<<"MAXIMUM ELEMENT- "<<maxelement(root)<<endl;
}
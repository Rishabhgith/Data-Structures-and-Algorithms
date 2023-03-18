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
node *util(node *root)
{
	while(root->right)
	root=root->right;
	return root;
}
node *deletenode(node *root,int x)
{
	if(!root)
	return NULL;
	if(root->val==x)
	{
		if(!root->left && !root->right)
		return NULL;
		if(root->left && root->right)
		{
			node *temp=util(root->left);
			root->val=temp->val;
			root->left=deletenode(root->left,temp->val);
			return root;
		}
		if(root->left)
		return root->left;
		if(root->right)
		return root->right;
	}
else if(x<root->val)
root->left=deletenode(root->left,x);
else if(x>root->val)
root->right=deletenode(root->right,x);
return root;
}
int main()
{
	node *root=NULL;
	root = insert(root, 50);
    root = insert(root, 40);
    root = insert(root, 45);
    root = insert(root, 43);
    root = insert(root, 60);
    root = insert(root, 55);
    root = insert(root, 66);
    root=insert(root,58);
    root=insert(root,57);
    level(root);
    int x=60;
    root=deletenode(root,x);
    level(root);
}

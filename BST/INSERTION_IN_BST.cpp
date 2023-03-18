#include<bits/stdc++.h>
using namespace std;
struct node
{
	int val;
	node *left;
	node *right;
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
int main()
{
	node *root=NULL;
	root=insert(root,30);
	root=insert(root,25);
	root=insert(root,22);
	root=insert(root,22);
	root=insert(root,27);
	root=insert(root,33);
	root=insert(root,37);
	root=insert(root,36);
	level(root);
}
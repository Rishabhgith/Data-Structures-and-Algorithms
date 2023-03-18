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
void smallertree(node *root,int &sum)
{
	if(!root)
	return;
	smallertree(root->left,sum);
	sum+=root->val;
	root->val=sum;
	smallertree(root->right,sum);
}
int main()
{
	node *root=NULL;
	root=insert(root,30);
	root=insert(root,20);
	root=insert(root,13);
	root=insert(root,24);
	root=insert(root,40);
	root=insert(root,42);
	level(root);
	int sum=0;
	smallertree(root,sum);
	level(root);
}
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
void greatersum(node *root,int &sum)
{
	if(!root)
	return;
	greatersum(root->right,sum);
	sum+=root->val;
	root->val=sum;
	greatersum(root->left,sum);
}
int main()
{
	node *root=NULL;
	root=insert(root,50);
	root=insert(root,40);
	root=insert(root,30);
	root=insert(root,45);
	root=insert(root,60);
	root=insert(root,55);
	root=insert(root,65);
	level(root);
	int sum=0;
	greatersum(root,sum);
	level(root);
}
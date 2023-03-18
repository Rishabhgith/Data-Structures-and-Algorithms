#include<bits/stdc++.h>
using namespace std;
struct node
{
	int val;
	node *right;
	node *left;
};

node *newnode(int data)
{
	node *temp=new node();
	temp->val=data;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}
void reverselevelorder(node *root,stack<int>&s)
{
	queue<node*>q;
	if(!root)
	return;
	q.push(root);
	while(!q.empty())
	{
		node *temp=q.front();
		q.pop();
		s.push(temp->val);
		if(temp->right)
		q.push(temp->right);
		if(temp->left)
		q.push(temp->left);
		
	}
}
int main()
{
	node *root=newnode(10);
	root->left=newnode(20);
	root->right=newnode(30);
	root->left->left=newnode(40);
	root->left->right=newnode(60);
	stack<int>s;
	reverselevelorder(root,s);
	while(!s.empty())
	{
		cout<<s.top()<<" ";
		s.pop();
	}
}
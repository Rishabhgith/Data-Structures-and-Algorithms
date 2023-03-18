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
	node *t=new node();
	t->val=data;
	t->left=NULL;
	t->right=NULL;
	return t;
}

void bottomview(node *root)
{
	if(!root)
	return;
	map<int,int>m;
	queue<pair<node*,int>>q;
	q.push(make_pair(root,0));
	
while(!q.empty())
{
	pair<node*,int>p=q.front();
	q.pop();
	node *temp=p.first;
	int hd=p.second;
	m[hd]=temp->val;
	if(temp->left)
	q.push(make_pair(temp->left,hd-1));
	if(temp->right)
	q.push(make_pair(temp->right,hd+1));
}
for(auto x:m)
cout<<x.second<<" ";
}

int main()
{
	node *root=newnode(1);
	root->left=newnode(2);
	root->left->left=newnode(4);
	root->left->right=newnode(5);
	root->right=newnode(3);
	root->right->right=newnode(7);
	root->right->left=newnode(6);
	root->right->left->right=newnode(8);
	root->right->left->right->right=newnode(9);
	bottomview(root);
}
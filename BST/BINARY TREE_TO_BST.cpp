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
node *addnode(int data)
{
	node *t=new node();
	t->val=data;
	t->right=NULL;
	t->left=NULL;
	return t;
}

void retrive(node *root,vector<int>&v)
{
	if(!root)
	return;
	retrive(root->left,v);
	v.push_back(root->val);
	retrive(root->right,v);
}
void change(node *root,vector<int>&v,int &i)
{
	if(!root)
	return;
	change(root->left,v,i);
	root->val=v[i++];
	change(root->right,v,i);
}
void conversion(node *root)
{
	vector<int>v;
	retrive(root,v);
	sort(v.begin(),v.end());
	int i=0;
	change(root,v,i);
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
	node *root=addnode(25);
	root->left=addnode(30);
	root->left->left=addnode(17);
	root->left->right=addnode(22);
	root->right=addnode(32);
	root->right->right=addnode(28);
	level(root);
	cout<<endl;
	conversion(root);
	level(root);
}
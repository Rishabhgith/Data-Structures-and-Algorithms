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
	t->right=NULL;
	t->left=NULL;
	return t;
	
}

void inorder(node *root,vector<int>&v)
{
	stack<node*>s;
	while(true)
	{
		if(root!=NULL)
		{
			s.push(root);
			root=root->left;
		}
		else
		{
			if(s.empty()==true)
			break;
			root=s.top();
			s.pop();
			v.push_back(root->val);
			root=root->right;
		}
	}
}

int main()
{
	node *root=newnode(1);
	root->left=newnode(3);
	root->right=newnode(7);
	root->left->left=newnode(6);
	root->left->right=newnode(4);
	root->right->left=newnode(8);
	root->right->right=newnode(2);
	vector<int>v;
	inorder(root,v);
	for(auto x:v)
	cout<<x<<" ";
}
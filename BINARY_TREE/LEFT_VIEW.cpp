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

void leftview(node *root,vector<int>&v)
{
	if(!root)
	return;
	bool isfirst=true;
	queue<node*>q;
	q.push(root);
	q.push(NULL);
	while(!q.empty())
	{
		node *temp=q.front();
		q.pop();
		if(!temp)
		{
			if(q.size()==0)
			return;
			q.push(NULL);
			isfirst=true;
		}
		else
		{
			if(isfirst)
			{
				v.push_back(temp->val);
				isfirst=false;
				if(temp->left)
				q.push(temp->left);
				if(temp->right)
				q.push(temp->right);
			}
			else
			{
				if(temp->left)
				q.push(temp->left);
				if(temp->right)
				q.push(temp->right);
			}
		}
	}
}
int main()
{
	node *root=addnode(1);
	root->left=addnode(2);
	root->left->right=addnode(5);
	root->right=addnode(3);
	root->right->right=addnode(6);
	root->right->right->right=addnode(8);
	root->right->right->left=addnode(7);
	vector<int>v;
	leftview(root,v);
	for(auto x:v)
	cout<<x<<" ";
}
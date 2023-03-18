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
	t->right=t->left=NULL;
	return t;
}
void rightview(node *root,vector<int>&v)
{
	if(!root)
	return;
	queue<node*>q;
	q.push(root);
	q.push(NULL);
	bool isfirst=true;
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
				if(temp->right)
				q.push(temp->right);
				if(temp->left)
				q.push(temp->left);
			}
			else
			{
				if(temp->right)
				q.push(temp->right);
				if(temp->left)
				q.push(temp->left);
			}
		}
		
	}
}
int main()
{
	node *root=addnode(1);
	root->left=addnode(2);
	root->left->left=addnode(5);
	root->left->left->right=addnode(6);
	root->right=addnode(3);
	root->right->left=addnode(4);
	vector<int>v;
	rightview(root,v);
	for(auto x:v)
	cout<<x<<" ";
}
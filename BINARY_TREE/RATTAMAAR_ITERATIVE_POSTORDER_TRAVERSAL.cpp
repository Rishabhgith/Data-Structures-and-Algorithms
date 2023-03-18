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

void postorder(node *root,vector<int>&v)
{   
    if(root==NULL)
    return;
	stack<node*>s;
	node *temp;
while(root!=NULL || !s.empty())
{
	if(root!=NULL)
	{
		s.push(root);
		root=root->left;
	}
	else
	{
		temp=s.top()->right;
		if(temp==NULL)
		{
			temp=s.top();
			s.pop();
			v.push_back(temp->val);
			cout<<temp->val<<endl;
			while(!s.empty() && temp==s.top()->right)
			{
				temp=s.top();
				s.pop();
				v.push_back(temp->val);
			}
		}
		else
		root=temp;
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
	postorder(root,v);
	for(auto x:v)
	cout<<x<<" ";
}
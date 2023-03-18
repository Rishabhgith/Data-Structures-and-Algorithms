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
void preorder(node *root)
{
	if(!root)
	return;
	cout<<root->val<<" ";
	preorder(root->left);
	preorder(root->right);
}
node * serialize(node *root,vector<int>&v)
{
	if(!root)
	{
	 v.push_back(-1);
	 return root;
	}
	v.push_back(root->val);
	serialize(root->left,v);
	serialize(root->right,v);
	return root;
}
node *deserialize(vector<int>v,int &curr)
{
	if(v[curr]==-1)
	{
		curr++;
		return NULL;
	}
	node *temp=addnode(v[curr]);
	curr++;
	temp->left=deserialize(v,curr);
	temp->right=deserialize(v,curr);
	return temp;
}

int main()
{
	node *root=addnode(1);
	root->left=addnode(2);
	root->left->left=addnode(4);
	root->left->right=addnode(5);
	root->right=addnode(3);
	root->right->right=addnode(6);
	preorder(root);
	cout<<endl;
	vector<int>v;
	serialize(root,v);
	for(auto x:v)
	cout<<x<<" ";
	cout<<endl;
	int curr=0;
	node *ans=deserialize(v,curr);
	preorder(ans);
}
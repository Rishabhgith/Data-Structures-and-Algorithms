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
	root->left=insert(root->left,data);
	else if(data>root->val)
	root->right=insert(root->right,data);
	return root;
}
int closest(node *root,int target)
{
	if(!root)
	return INT_MAX;
	if(root->val==target)
	return 0;
	if(target<root->val)
	return min(abs(root->val-target),closest(root->left,target));
	return min(abs(root->val-target),closest(root->right,target));
}
int main()
{
	node *root=NULL;
	root=insert(root,70);
	root=insert(root,60);
	root=insert(root,50);
	root=insert(root,65);
	root=insert(root,45);
	root=insert(root,67);
	root=insert(root,80);
	root=insert(root,90);
	int target=66;
	int mi=closest(root,target);
	cout<<mi<<endl;
}

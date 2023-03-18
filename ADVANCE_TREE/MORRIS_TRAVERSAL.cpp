// SPACE COMPLEXITY-O(1)
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
	{
		root->left=insert(root->left,data);
	}
	else if(data>root->val)
	root->right=insert(root->right,data);
	return root;
}
void morris(node *root)
{   node *pre;
	node *curr=root;
	while(curr!=NULL)
	{
		if(curr->left==NULL)
		{
			cout<<curr->val<<" ";
			curr=curr->right;
		}
		else
		{
			pre=curr->left;
		while(pre->right!=NULL && pre->right!=curr)
		pre=pre->right;
		
		if(pre->right==NULL)
		{
			pre->right=curr;
			curr=curr->left;
		}
		else
		{
			pre->right=NULL;
			cout<<curr->val<<" ";
			curr=curr->right;
		}
		}
	}
}
int main()
{
	node *root=NULL;
	root=insert(root,50);
	root=insert(root,40);
	root=insert(root,30);
	root=insert(root,45);
	root=insert(root,60);
	root=insert(root,65);
	morris(root);
}
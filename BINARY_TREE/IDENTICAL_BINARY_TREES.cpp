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

bool identical(node *root1,node *root2)
{
	if(!root1 && !root2)
	return true;
	if(!root1 || !root2)
	return false;
	if(root1->val!=root2->val)
	return false;
	return identical(root1->left,root2->left) && identical(root1->right,root2->right);
}

int main()
{
	node *root1=addnode(1);
	root1->left=addnode(2);
	root1->right=addnode(3);
	node *root2=addnode(1);
	root2->left=addnode(2);
	root2->right=addnode(3);
	bool ans=identical(root1,root2);
	cout<<ans<<" ";
}
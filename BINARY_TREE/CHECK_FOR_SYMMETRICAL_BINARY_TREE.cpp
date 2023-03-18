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
}
bool mirror(node *root1,node *root2)
{
	if(!root1 && !root2)
	return true;
	if(!root1 || !root2)
	return false;
	if(root1->val!=root2->val)
	return false;
	return(mirror(root1->left,root2->right) && mirror(root1->right,root2->left));
}

bool symmetrical(node *root)
{
	if(!root)
	return true;
	
	return mirror(root->left,root->right);
}
int main()
{
	node *root=addnode(1);
	root->left=addnode(2);
	root->right=addnode(2);
	root->left->left=addnode(3);
	root->left->right=addnode(4);
	root->right->left=addnode(4);
	root->right->right=addnode(3);
	root->left->right->left=addnode(5);
	root->right->left->right=addnode(5);
	cout<<symmetrical(root)<<endl;
}
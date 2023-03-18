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
	t->left=NULL;
	t->right=NULL;
	return t;
}
void invert(node *root)
{
	if(!root)
	return;
	node *temp=root->left;
	root->left=root->right;
	root->right=temp;
	invert(root->left);
	invert(root->right);
}
node *Invert(node *root)
{
	if(!root)
	return NULL;
	invert(root);
    return root;
	
}
bool mirror(node *root1,node *root2)
{
	if(!root1 && !root2)
	return true;
	if(!root1 || !root2)
	return false;
	if(root1->val!=root2->val)
	return false;
	return mirror(root1->left,root2->right) && mirror(root1->right,root2->left);
}

int main()
{
	node *root=addnode(1);
	root->left=addnode(2);
	root->left->left=addnode(4);
	root->left->right=addnode(5);
	root->right=addnode(3);
	root->right->right=addnode(6);
	node *p=root;
	node *root2=Invert(root);
	cout<<root->left->val<<endl;
	cout<<root->right->val<<endl;
	cout<<root->left->left->val<<endl;
	cout<<root->right->left->val<<endl;
	cout<<root->right->right->val<<endl;
}
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
int height(node *root)
{
	if(!root)
	return 0;
	return 1+max(height(root->left),height(root->right));
	
}
int main()
{
	node *root=addnode(1);
	root->left=addnode(2);
	root->left->left=addnode(4);
	root->left->right=addnode(5);
	root->left->right->right=addnode(6);
	root->left->right->right->left=addnode(7);
	root->right=addnode(3);
	root->right->right=addnode(8);
	root->right->right->right=addnode(9);
	cout<<"HEIGHT OF TREE IS "<<height(root)<<endl;
	
}
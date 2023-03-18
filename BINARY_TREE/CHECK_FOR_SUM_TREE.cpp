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
int sumtreeutil(node *root,bool &flag)
{
	if(!root)
	return 0;
	if(!root->right && !root->left)
	return root->val;
	int lsum=sumtreeutil(root->left,flag);
	int rsum=sumtreeutil(root->right,flag);
	if(root->val!=lsum+rsum)
	flag=false;
	return root->val+lsum+rsum;
}
bool sumtree(node *root)
{
	bool flag=true;
	int x=sumtreeutil(root,flag);
	cout<<x<<endl;
	return flag;
}
int main()
{
	node *root=addnode(22);
	root->left=addnode(6);
	root->right=addnode(5);
	root->left->left=addnode(4);
	root->left->right=addnode(2);
	root->right->left=addnode(1);
	root->right->right=addnode(4);
	bool ans=sumtree(root);
	cout<<ans<<endl;
}
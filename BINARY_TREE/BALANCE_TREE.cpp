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
int height(node *root,bool &isbalance)
{
	if(!root)
	return 0;
	int lh=height(root->left,isbalance);
	int rh=height(root->right,isbalance);
	if(abs(lh-rh)>1)
	isbalance=false;
	return (1+max(lh,rh));
}
int main()
{
	node *root=addnode(1);
	root->left=addnode(2);
	root->left->left=addnode(4);
	root->left->left->left=addnode(5);
	root->right=addnode(3);
	root->right->right=addnode(7);
	root->right->left=addnode(8);
	bool isbalance=true;
	height(root,isbalance);
	cout<<isbalance<<endl;
	
}
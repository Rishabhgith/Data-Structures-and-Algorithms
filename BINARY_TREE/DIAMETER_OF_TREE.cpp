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

int diameter(node *root,int &d)
{
	if(!root)
	return 0;
	int lh=diameter(root->left,d);
	int rh=diameter(root->right,d);
	if(1+rh+lh>d)
	d=1+rh+lh;
	return(1+max(lh,rh));
	
}

int main()
{
	node *root=addnode(1);
	root->left=addnode(2);
	root->left->left=addnode(4);
	root->left->left->left=addnode(5);
	root->right=addnode(3);
	root->right->left=addnode(6);
	root->right->right=addnode(7);
	int d=0;
	diameter(root,d);
	cout<<"DIAMETER OF TREE IS "<<d<<endl;
}
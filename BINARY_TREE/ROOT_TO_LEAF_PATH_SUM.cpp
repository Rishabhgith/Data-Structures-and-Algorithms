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

void findsum(node *root,int curr_sum,int sum,bool &isfound)
{
	if(!root)
	return;
	curr_sum+=root->val;
	if(!root->left && !root->right && curr_sum==sum)
	isfound=true;
	
	findsum(root->left,curr_sum,sum,isfound);
	findsum(root->right,curr_sum,sum,isfound);
}

int main()
{
	node *root=addnode(1);
	root->left=addnode(2);
	root->right=addnode(3);
	root->right->right=addnode(6);
	root->left->left=addnode(4);
	root->left->right=addnode(5);
	root->right->left=addnode(7);
	int sum=13;
	bool isfound=false;
	int curr_sum=0;
	findsum(root,curr_sum,sum,isfound);
	cout<<isfound<<endl;
}
	
	
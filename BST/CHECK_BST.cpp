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
bool check(node *root,int mi,int ma)
{
	if(!root)
	return true;
	if(mi>ma)
	return false;
	if(root->val<mi || root->val>ma)
	return false;
return check(root->left,mi,root->val-1) &&
       check(root->right,root->val+1,ma);
}

int main()
{
	node *root=addnode(50);
	root->left=addnode(40);
	root->left->left=addnode(30);
	root->left->right=addnode(45);
	root->right=addnode(60);
	root->right->right=addnode(65);
	root->right->right->left=addnode(63);
	int mi=INT_MIN;
	int ma=INT_MAX;
	cout<<check(root,mi,ma)<<endl;
}
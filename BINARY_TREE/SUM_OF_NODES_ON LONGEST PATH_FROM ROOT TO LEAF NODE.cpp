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
void findsum(node *root,int curr_sum,int &max_sum)
{
	if(!root)
	return;
	curr_sum+=root->val;
	if(!root->left && !root->right && curr_sum>max_sum)
	{
		max_sum=curr_sum;
	}
	findsum(root->left,curr_sum,max_sum);
	findsum(root->right,curr_sum,max_sum);
}
int main()
{
	node *root=addnode(4);
	root->left=addnode(2);
	root->left->left=addnode(7);
	root->left->right=addnode(1);
	root->left->right->left=addnode(6);
	root->right=addnode(5);
	root->right->left=addnode(2);
	root->right->right=addnode(3);
	int curr_sum=0,max_sum=0;
	findsum(root,curr_sum,max_sum);
	cout<<max_sum<<endl;
}
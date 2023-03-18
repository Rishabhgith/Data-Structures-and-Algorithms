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
int sumtree(node *root,int curr_sum,int &max_sum)
{
	if(!root)
	return 0;
	curr_sum=root->val+sumtree(root->left,curr_sum,max_sum)+sumtree(root->right,curr_sum,max_sum);
	max_sum=max(curr_sum,max_sum);
	return curr_sum;
}
int main()
{
	node *root=addnode(1);
	root->left=addnode(-4);
	root->right=addnode(3);
	root->right->left=addnode(6);
	root->right->right=addnode(2);
	int curr_sum=0,max_sum=0;
	sumtree(root,curr_sum,max_sum);
	cout<<max_sum<<endl;
}
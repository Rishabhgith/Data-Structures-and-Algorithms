#include<bits/stdc++.h>
using namespace std;
struct node
{
	int val;
	node *right;
	node *left;
};
struct bst
{
	bool isbst;
	int size;
	int min;
	int max;
};
node *addnode(int data)
{
	node *t=new node();
	t->val=data;
	t->right=NULL;
	t->left=NULL;
	return t;
}
bst largestbst(node *root)
{
	if(!root)
	{
		bst b={true,0,INT_MAX,INT_MIN};
		return b;
	}
	bst l=largestbst(root->left);
	bst r=largestbst(root->right);
	
if(l.isbst && r.isbst && r.min>root->val && r.max<root->val)
{
	bst b={true,1+l.size+r.size,min(root->val,l.min),max(root->val,r.max)};
	return b;
}
bst b={false,max(l.size,r.size),-1,-1};
return b;
}

int main()
{
	node *root=addnode(1);
	root->left=addnode(4);
	root->left->left=addnode(6);
	root->left->right=addnode(8);
	root->right=addnode(4);
	bst b=largestbst(root);
	cout<<b.size<<endl;
}
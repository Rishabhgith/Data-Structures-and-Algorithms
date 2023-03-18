#include<bits/stdc++.h>
using namespace std;
struct node
{
	int val;
	node *right;
	node *left;
};
node *temp=NULL;
node *addnode(int data)
{
	node *t=new node();
	t->val=data;
	t->right=NULL;
	t->left=NULL;
	return t;
}
node *kthancestor(node *root,int value,int &k)
{
	if(!root)
	return NULL;
	if((root->val==value) || (temp=kthancestor(root->left,value,k)) || (temp=kthancestor(root->right,value,k)))
	{
		if(k>0)
		k--;
		else if(k==0)
		{
			cout<<"KTH ANCESTOR IS "<<root->val<<endl;
			return NULL;
		}
		return root;
	}
}
int main()
{
	node *root=addnode(1);
	root->left=addnode(2);
	root->right=addnode(3);
	root->left->left=addnode(4);
	root->left->right=addnode(5);
	int k=2;
	int value=4;
	kthancestor(root,value,k);
}
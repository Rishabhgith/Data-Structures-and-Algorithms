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
node *insert(node *root,int data)
{
	if(!root)
	{
		root=addnode(data);
		return root;
	}
	if(data<root->val)
	root->left=insert(root->left,data);
	else
	root->right=insert(root->right,data);
	return root;
}
void findpreandsec(node *root,node *&pre,node *&sec,int key)
{
	if(!root)
	return;
if(root->val==key)
{
	if(root->left!=NULL)
	{
		node *temp=root->left;
		while(temp->right)
		temp=temp->right;
		pre=temp;
	}
	if(root->right!=NULL)
	{
		node *temp=root->right;
		while(temp->left)
		temp=temp->left;
		sec=temp;
	}
}
if(key<root->val)
{
	sec=root;
	findpreandsec(root->left,pre,sec,key);
}
else if(key>root->val)
{
	pre=root;
	findpreandsec(root->right,pre,sec,key);
}
}
int main()
{
	node *root=NULL;
	root=insert(root,50);
	root=insert(root,30);
	root=insert(root,20);
	root=insert(root,40);
	root=insert(root,70);
	root=insert(root,60);
	root=insert(root,80);
	node *pre=NULL;
	node *sec=NULL;
	int key=65;
	findpreandsec(root,pre,sec,key);
	cout<<pre->val<<" "<<sec->val<<endl;
}
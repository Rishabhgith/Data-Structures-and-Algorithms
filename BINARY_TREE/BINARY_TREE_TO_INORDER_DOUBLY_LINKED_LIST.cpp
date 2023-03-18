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

void bttoll(node *root,node *&head,node *&tail)
{
	if(!root)
	return;
	bttoll(root->left,head,tail);
	if(!head)
	{
		head=root;
		tail=root;
	}
	else
	{
		root->left=tail;
		tail->right=root;
		tail=root;
	}
	bttoll(root->right,head,tail);
}
void printlist(node *head)
{
	while(head!=NULL)
	{
		cout<<head->val<<" ";
		head=head->right;
	}
}
int main()
{
	node *root=addnode(1);
	root->left=addnode(2);
	root->left->left=addnode(5);
	root->left->right=addnode(6);
	root->right=addnode(3);
	root->right->left=addnode(4);
	node *head=NULL;
	node *tail=NULL;
	bttoll(root,head,tail);
	printlist(head);
}
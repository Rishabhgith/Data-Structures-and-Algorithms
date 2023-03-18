#include<bits/stdc++.h>
using namespace std;
struct node
{
	int val;
	node *next;
};
struct tnode
{
	int val;
	tnode *right;
	tnode *left;
};
void push(node *&head,int data)
{
	node *t=new node();
	t->val=data;
	t->next=head;
	head=t;
}
void printlist(node *head)
{
	while(head!=NULL)
	{
		cout<<head->val<<" ";
		head=head->next;
	}
	cout<<endl;
}
int countnodes(node *head)
{
	int c=0;
	while(head!=NULL)
	{
		c++;
		head=head->next;
	}
	return c;
}
tnode *constructbst(node *&head,int n)
{
	if(n==0)
	return NULL;
	tnode *root=new tnode();
	root->left=constructbst(head,n/2);
	root->val=head->val;
	head=head->next;
	root->right=constructbst(head,(n-1)/2);
	return root;
}
void level(tnode *root)
{
	if(!root)
	return;
	queue<tnode*>q;
	q.push(root);
	while(!q.empty())
	{
		tnode *t=q.front();
		q.pop();
		cout<<t->val<<" ";
		if(t->left)
		q.push(t->left);
		if(t->right)
		q.push(t->right);
	}
}
int main()
{
	node *head=NULL;
	push(head,15);
	push(head,12);
	push(head,9);
	push(head,5);
	push(head,1);
	printlist(head);
	int n=countnodes(head);
	tnode *ans=constructbst(head,n);
	level(ans);
}
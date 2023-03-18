#include<bits/stdc++.h>
using namespace std;
struct listnode
{
	int val;
	listnode *next;
};
struct node
{
	int val;
	node *right;
	node *left;
};
void pushnode(listnode *&head,int data)
{
	listnode *t=new listnode();
	t->val=data;
	t->next=head;
	head=t;
}
void createvector(listnode *head,vector<node*>&v)
{
	while(head!=NULL)
	{
		node *temp=new node();
		temp->val=head->val;
		temp->right=NULL;
		temp->left=NULL;
		v.push_back(temp);
		head=head->next;
	}
}
node *createtree(vector<node*>v)
{
	int n=v.size();
for(int i=0; i<=n/2; i++)
{
	if((2*i+1)<n)
	v[i]->left=v[2*i+1];
	if((2*i+2)<n)
	v[i]->right=v[2*i+2];
}
return v[0];
}
void levelorder(node *root)
{   
	if(!root)
	return;
	queue<node*>q;
	q.push(root);
	while(!q.empty())
	{
		node *temp=q.front();
		q.pop();
		cout<<temp->val<<" ";
		if(temp->left)
		q.push(temp->left);
		if(temp->right)
		q.push(temp->right);
	}
}
int main()
{
	listnode *head=NULL;
	pushnode(head,4);
	pushnode(head,3);
	pushnode(head,2);
	pushnode(head,1);
	vector<node*>v;
	createvector(head,v);
	node *root=createtree(v);
	levelorder(root);
}
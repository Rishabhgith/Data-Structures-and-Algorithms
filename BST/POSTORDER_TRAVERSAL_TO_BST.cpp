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
node *consttree(int a[],int l,int r,int &ptr)
{
	if(ptr<0)
	return NULL;
	if(l>r)
	return NULL;
	int x=a[ptr];
	if(a[ptr]<l || a[ptr]>r)
	return NULL;
	node *root=addnode(a[ptr]);
	ptr--;
	root->right=consttree(a,x+1,r,ptr);
	root->left=consttree(a,l,x-1,ptr);
	return root;
}
void level(node *root)
{
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
	}cout<<endl;
}
int main()
{
	int a[]={6,10,35,47,44,40,30};
	int l=INT_MIN;
	int r=INT_MAX;
	int n=sizeof(a)/sizeof(a[0]);
	int ptr=n-1;
	node *root=consttree(a,l,r,ptr);
	level(root);
}
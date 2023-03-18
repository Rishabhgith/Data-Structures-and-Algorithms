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
node *consttree(int a[],int n,int l,int r,int &ptr)
{
	if(ptr>=n)
	return NULL;
	if(l>r)
	return NULL;
	int x=a[ptr];
	if(a[ptr]<l || a[ptr]>r)
	return NULL;
	node *root=addnode(a[ptr]);
	ptr++;
	root->left=consttree(a,n,l,x-1,ptr);
	root->right=consttree(a,n,x+1,r,ptr);
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
	int a[]={40,30,22,34,50,60,62,65};
	int l=INT_MIN;
	int r=INT_MAX;
	int n=sizeof(a)/sizeof(a[0]);
	int ptr=0;
	node *root=consttree(a,n,l,r,ptr);
	level(root);
}
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
node *arraytobst(int a[],int l,int r)
{
	if(l>r)
	return NULL;
	int mid=(l+r)/2;
	node *root=addnode(a[mid]);
	root->left=arraytobst(a,l,mid-1);
	root->right=arraytobst(a,mid+1,r);
	return root;
}
void level(node *root)
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
	cout<<endl;
}
int main()
{
	int a[]={10,12,15,20,24,28};
	int l=0;
	int r=sizeof(a)/sizeof(a[0])-1;
	node *ans=arraytobst(a,l,r);
	level(ans);
	
}
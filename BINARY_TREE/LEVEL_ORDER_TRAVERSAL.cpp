//LEVEL ORDER TRAVERSAL HAS MANY DIFFERENT FORMS I 
//HAVE DID 2 ONLY BUT CAN BE DONE IN MANY WAYS
#include<bits/stdc++.h>
using namespace std;
struct node
{
	int val;
	node *right;
	node *left;
};
node *newnode(int data)
{
	node *t=new node();
	t->val=data;
	t->right=NULL;
	t->left=NULL;
	return t;
}
void levelorder(node *root,vector<int>&u)
{   queue<node *>q;
	if(!root)
	return;
	q.push(root);
	while(!q.empty())
	{
		node *temp=q.front();
		u.push_back(temp->val);
		if(temp->left)
		q.push(temp->left);
		if(temp->right)
		q.push(temp->right);
		q.pop();
	}
	
}
int main()
{
	node *root=newnode(1);
	root->left=newnode(2);
	root->right=newnode(3);
	root->left->left=newnode(4);
	root->left->right=newnode(5);
	root->right->right=newnode(6);
	vector<int>u;
	levelorder(root,u);
	for(auto x:u)
	cout<<x<<" ";
	
}
#include<bits/stdc++.h>
using namespace std;
struct node
{
	int val;
	node *left;
	node *right;
};
node *addnode(int data)
{
	node *t=new node();
	t->val=data;
	t->right=NULL;
	t->left=NULL;
	return t;
}

bool identical(node *root1,node *root2)
{
	if(!root1 && !root2)
	return true;
	if(!root1 || !root2)
	return false;
	if(root1->val!=root2->val)
	return false;
	return identical(root1->left,root2->left)&&identical(root1->right,root2->right);
}
bool subtree(node *root1,node *root2)
{
	queue<node*>q;
	q.push(root1);
	while(!q.empty())
	{
		node *temp=q.front();
		q.pop();
		if(temp->val==root2->val)
		{
			bool isidentical=identical(temp,root2);
			if(isidentical)
			return true;
		}
		if(temp->left)
		q.push(temp->left);
		if(temp->right)
		q.push(temp->right);
	}
	return false;
}

int main()
{
	node *root1=addnode(1);
	root1->left=addnode(2);
	root1->right=addnode(3);
	root1->left->left=addnode(3);
	root1->left->left->left=addnode(4);
	root1->left->left->right=addnode(5);
	root1->right->left=addnode(6);
	root1->right->right=addnode(7);
	
	node *root2=addnode(3);
	root2->left=addnode(4);
	root2->right=addnode(5);
	
	bool ans=subtree(root1,root2);
	cout<<ans<<endl;
}
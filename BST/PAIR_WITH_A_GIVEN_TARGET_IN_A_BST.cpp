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
	else if(data>root->val)
	root->right=insert(root->right,data);
	return root;
}
void pushelement(node *root,stack<node*>&s,bool direction)
{
	if(direction)
	{
		while(root)
		{
			s.push(root);
			root=root->left;
		}
	}
	else
	{
		while(root)
		{
			s.push(root);
			root=root->right;
		}
	}
}
bool findpair(node *root,int target)
{
	if(!root)
	return false;
	stack<node*>s1;
	stack<node*>s2;
	pushelement(root,s1,true);
	pushelement(root,s2,false);
while(!s1.empty() && !s2.empty() && s1.top()->val<=s2.top()->val)
{
	int x=s1.top()->val;
	int y=s2.top()->val;
	if(x+y==target)
	return true;
	if(x+y<target)
	{
		node *temp=s1.top();
		s1.pop();
		pushelement(temp->right,s1,true);
	}
	else
	{
		node *temp=s2.top();
		s2.pop();
		pushelement(temp->left,s2,false);
	}
}
return false;
}
int main()
{
	node *root=NULL;
	root=insert(root,70);
	root=insert(root,50);
	root=insert(root,40);
	root=insert(root,60);
	root=insert(root,30);
	root=insert(root,55);
	root=insert(root,80);
	root=insert(root,90);
	int target=150;
	bool ans=findpair(root,target);
	cout<<ans<<endl;
}
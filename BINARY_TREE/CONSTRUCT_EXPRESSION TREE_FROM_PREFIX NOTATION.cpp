#include<bits/stdc++.h>
using namespace std;
struct node
{
	char val;
	node *right;
	node *left;
};
node *addnode(char a)
{
	node *t=new node();
	t->val=a;
	t->right=NULL;
	t->left=NULL;
	return t;
}
node *et(string s,int &curr,int n)
{
	if(curr==n)
	return NULL;
	node *root=addnode(s[curr]);
if(s[curr]=='+' || s[curr]=='-' || s[curr]=='*' || s[curr]=='/')
{
	curr++;
	root->left=et(s,curr,n);
	root->right=et(s,curr,n);
	return root;
}
curr++;
return root;
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
	string s="*+34/76";
	int n=s.size();
	int curr=0;
	node *ans=et(s,curr,n);
	levelorder(ans);
}
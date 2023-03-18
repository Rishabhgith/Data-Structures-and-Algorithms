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
node *et(string s,int &curr)
{
	if(curr<0)
	return NULL;
	node *root=addnode(s[curr]);
	curr--;
if(root->val=='+' || root->val=='*' || root->val=='-' || root->val=='/')
{
	
	root->right=et(s,curr);
	root->left=et(s,curr);
	return root;
}

return root;
}
void inorder(node *root)
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
	}
	
}
void postorder(node *root)
{
	while(root!=NULL)
	{
		cout<<root->val<<" ";
		root=root->left;
	}
}
int main()
{
	string s;
	cin>>s;
	int curr=s.size()-1;
	node *ans=et(s,curr);
	//inorder(ans);
	//cout<<endl;
	postorder(ans);
}
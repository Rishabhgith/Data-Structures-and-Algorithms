#include<bits/stdc++.h>
using namespace std;
struct node
{
	char val;
	node *right;
	node *left;
};
node *addnode(char data)
{
	node *t=new node();
	t->val=data;
	t->right=NULL;
	t->left=NULL;
	return t;
}
node *constructtree(string s)
{    int n=s.length();
	//WE KNOW FIRST CHARACATER OF STRING IS ROOT OF TREE
	node *root=addnode(s[0]);
	stack<node *>str;
	for(int i=1; i<n; i++)
	{
		if(s[i]=='(')
		{
			str.push(root);
		}
		else if(s[i]==')')
		{
			root=str.top();
			str.pop();
		}
		else if(root->left==NULL)
		{
			root->left=addnode(s[i]);
			root=root->left;
		}
		else if(root->right==NULL)
		{
			root->right=addnode(s[i]);
			root=root->right;
		}
	}
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
cout<<endl;
}
int main()
{
	string s = "4(2(3)(1))(6(5))";
	node *ans=constructtree(s);
	levelorder(ans);
}
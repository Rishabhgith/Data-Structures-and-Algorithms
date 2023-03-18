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
	{
		root->left=insert(root->left,data);
	}
	else if(data>root->val)
	root->right=insert(root->right,data);
	return root;
}
void util(node *root,stack<node*>&s)
{
	while(root!=NULL)
	{
		s.push(root);
		root=root->left;
	}
}
void merge(node *root1,node *root2)
{
	stack<node*>s1;
	stack<node*>s2;
	util(root1,s1);
	util(root2,s2);
	vector<int>v;
	while(!s1.empty() && !s2.empty())
	{
		if(s1.top()->val<s2.top()->val)
		{
			node *temp=s1.top();
			s1.pop();
			v.push_back(temp->val);
			util(temp->right,s1);
		}
		else if(s1.top()->val>s2.top()->val)
		{
			node *temp=s2.top();
			s2.pop();
			v.push_back(temp->val);
			util(temp->right,s2);
		}
		else if(s1.top()->val==s2.top()->val)
		{
			node *t1=s1.top();
			node *t2=s2.top();
			s1.pop();
			s2.pop();
			v.push_back(t1->val);
			util(t1->right,s1);
			util(t2->right,s2);
		}
	}
	while(!s1.empty())
	{
		v.push_back(s1.top()->val);
		s1.pop();
	}
	while(!s2.empty())
	{
		v.push_back(s2.top()->val);
		s2.pop();
	}
for(auto x:v)
cout<<x<<" ";
cout<<endl;
}
int main()
{
	node *root1=NULL;
	root1=insert(root1,30);
	root1=insert(root1,17);
	root1=insert(root1,15);
	root1=insert(root1,20);
	root1=insert(root1,40);
	node *root2=NULL;
	root2=insert(root2,24);
	root2=insert(root2,16);
	root2=insert(root2,18);
	root2=insert(root2,29);
	root2=insert(root2,30);
	merge(root1,root2);
	
}
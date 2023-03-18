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

vector<int> verticalorder(node *root)
{
	vector<int>v;
	map<int,vector<int>>m;
	queue<pair<node*,int>>q;
	q.push(make_pair(root,0));
	
	while(!q.empty())
	{
		pair<node*,int>p=q.front();
		node *temp=p.first;
		int hd=p.second;
		m[hd].push_back(temp->val);
		
	if(temp->left!=NULL)
	q.push(make_pair(temp->left,hd-1));
	
	if(temp->right!=NULL)
	q.push(make_pair(temp->right,hd+1));
	
	q.pop();
	}
for(auto it:m)
{
	vector<int>l=it.second;
	for(auto x:l)
	v.push_back(x);
}
return v;
}

int main()
{
	node *root=newnode(1);
	root->left=newnode(2);
	root->right=newnode(3);
	root->left->left=newnode(4);
	root->left->right=newnode(5);
	root->right->left=newnode(6);
	root->right->right=newnode(9);
	root->left->left->right=newnode(7);
	root->left->left->right->right=newnode(8);
	vector<int>v;
	v=verticalorder(root);
	for(auto x:v)
	cout<<x<<" ";
	
	
}
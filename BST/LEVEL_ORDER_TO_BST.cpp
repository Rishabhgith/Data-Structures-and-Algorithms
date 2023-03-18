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
node *constructbst(vector<int>v)
{
	if(v.size()==0)
	return NULL;
	node *root=addnode(v[0]);
	vector<int>l,r;
	for(int i=1; i<v.size(); i++)
	{
		if(v[i]<v[0])
		l.push_back(v[i]);
		else 
		r.push_back(v[i]);
	}
	root->left=constructbst(l);
	root->right=constructbst(r);
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
	vector<int>v={50,45,57,42,55,56};
	node *ans=constructbst(v);
	level(ans);
}
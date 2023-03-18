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
node *searchnode(node *root,int value)
{
	queue<node*>q;
	q.push(root);
	while(!q.empty())
	{
		node *temp=q.front();
		if(temp->val==value)
		return temp;
		if(temp->left)
		q.push(temp->left);
		if(temp->right)
		q.push(temp->right);
		q.pop();
	}
}
void parent(node *root,node *p,map<node*,node*>&mp)
{
	if(!root)
	return;
	mp[root]=p;
	parent(root->left,root,mp);
	parent(root->right,root,mp);
}

void nextlevel(queue<node*>&q,set<node*>&s,map<node*,node*>mp)
{
	while(1)
	{
		node *temp=q.front();
		q.pop();
		if(temp==NULL)
		{
			if(q.size()!=0)
			q.push(NULL);
		return;
		}
	if(temp->left && s.find(temp->left)==s.end())
	{
		q.push(temp->left);
		s.insert(temp->left);
	}
	if(temp->right && s.find(temp->right) == s.end())
	{
        q.push(temp->right);
        s.insert(temp->right);
    }
    if(mp[temp] && s.find(mp[temp])==s.end())
    {
    	q.push(mp[temp]);
    	s.insert(mp[temp]);
    }
}
}

vector<int> kdistance(node *root,node *target,int k)
{
	map<node*,node*>mp;
	vector<int>v;
	parent(root,NULL,mp);
	int level=0;
	queue<node*>q;
	set<node*>s;
	q.push(target);
	s.insert(target);
	q.push(NULL);
	while(!q.empty())
	{
    if(level == k)
    {
    while(!q.empty())
    {
    node *temp = q.front();
    q.pop();
    if(temp)
    v.push_back(temp->val);
    }
    sort(v.begin(), v.end());
    return v;
    }

    level++;
    nextlevel(q,s,mp);
}
}

int main()
{
	node *root=addnode(1);
	root->left=addnode(2);
	root->right=addnode(3);
	root->left->left=addnode(4);
	root->left->right=addnode(5);
	root->left->right->left=addnode(7);
	root->left->right->right=addnode(6);
	root->left->right->left->left=addnode(8);
	int value=5;
	node *target=searchnode(root,value);
	int k=2;
	vector<int>v=kdistance(root,target,k);
	for(auto x:v)
	cout<<x<<" ";
}
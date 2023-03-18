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
node *maketree(vector<int>post,vector<int>in,int &end,unordered_map<int,int>mp,int ins,int ine)
{
	if(ins>ine)
	return NULL;
	node *root=addnode(post[end]);
	int mid=mp[post[end]];
	end--;
	root->right=maketree(post,in,end,mp,mid+1,ine);
	root->left=maketree(post,in,end,mp,ins,mid-1);
	return root;
}
node *buildtree(vector<int>post,vector<int>in)
{
	unordered_map<int,int>mp;
	int n=in.size();
	for(int i=0; i<n; i++)
	{
		mp[in[i]]=i;
	}
	int ins=0;
	int ine=n-1;
	int end=post.size()-1;
	return maketree(post,in,end,mp,ins,ine);
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
	vector<int>post={6,2,4,5,3,1};
	vector<int>in={6,2,1,4,3,5};
	node *ans=buildtree(post,in);
	levelorder(ans);
}
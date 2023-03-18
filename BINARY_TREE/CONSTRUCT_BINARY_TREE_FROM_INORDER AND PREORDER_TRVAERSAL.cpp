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
node *maketree(vector<int>pre,vector<int>in,int &start,unordered_map<int,int>mp,int ins,int ine)
{
	if(ins>ine)
	return NULL;
	node *root=newnode(pre[start]);
	int mid=mp[pre[start]];
	start++;
	root->left=maketree(pre,in,start,mp,ins,mid-1);
	root->right=maketree(pre,in,start,mp,mid+1,ine);
	return root;
}
node *buildtree(vector<int>in,vector<int>pre)
{
	unordered_map<int,int>mp;
	for(int i=0; i<in.size(); i++)
	{
		mp[in[i]]=i;
	}
	int start=0,ins=0;
	int ine=in.size()-1;
	return maketree(pre,in,start,mp,ins,ine);
	
}
int main()
{
	vector<int>in={4,2,5,1,3,7};
	vector<int>pre={1,2,4,5,3,7};
	node *root=buildtree(in,pre);
	cout<<root->val<<" "<<root->left->val<<" "<<root->right->val<<" ";
	cout<<root->left->left->val<<" "<<root->left->right->val<<" ";
	cout<<root->right->right->val<<" ";
}
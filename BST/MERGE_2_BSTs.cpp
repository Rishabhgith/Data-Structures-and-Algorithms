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
void inorder(node *root,vector<int>&v)
{
	if(!root)
	return;
	inorder(root->left,v);
	v.push_back(root->val);
	inorder(root->right,v);
}
vector<int> merge(vector<int>v1,vector<int>v2)
{
	int n1=v1.size();
	int n2=v2.size();
	int i=0,j=0;
	vector<int>v;
	while(i<n1 && j<n2)
	{
		if(v1[i]<v2[j])
		{
		v.push_back(v1[i]);
		i++;
		}
		else if(v1[i]>v2[j]){
		v.push_back(v2[j]);
		j++;
		}
		else if(v1[i]==v2[j])
		{   v.push_back(v1[i]);
			i++;
			j++;
		}
	}
	while(i<n1)
	{
		v.push_back(v1[i]);
		i++;
	}
	while(j<n2)
	{
		v.push_back(v2[i]);
		j++;
	}
	return v;
	
}
vector<int> mergebst(node *root1,node *root2)
{
	vector<int>v1;
	vector<int>v2;
	inorder(root1,v1);
	inorder(root2,v2);
	return merge(v1,v2);	
}
int main()
{
	node *root1=NULL;
	root1=insert(root1,24);
	root1=insert(root1,16);
	root1=insert(root1,10);
	root1=insert(root1,18);
	root1=insert(root1,30);
	root1=insert(root1,34);
	node *root2=NULL;
	root2=insert(root2,20);
	root2=insert(root2,18);
	root2=insert(root2,14);
	root2=insert(root2,25);
	root2=insert(root2,23);
	vector<int>v=mergebst(root1,root2);
	for(auto x:v)
	cout<<x<<" ";
	
}
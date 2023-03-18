//YOU GOT THIS QUES VERY WELL
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
string solve(node *root,unordered_map<string,int>&m)
{
	if(!root)
	return"&";
	string s="";
	if(!root->left && !root->right)
	{
		s=to_string(root->val);
		return s;
	}
	s=s+to_string(root->val);
	s=s+solve(root->left,m);
	s=s+solve(root->right,m);
	cout<<s<<endl;
	m[s]++;
	return s;
}
int main()
{
	node *root=addnode(1);
	root->left=addnode(2);
	root->left->left=addnode(4);
	root->left->right=addnode(5);
	root->right=addnode(3);
	root->right->right=addnode(2);
	root->right->right->left=addnode(4);
	root->right->right->right=addnode(5);
	unordered_map<string,int>m;
	solve(root,m);
	for(auto x:m)
	{
		if(x.second>=2)
		{
			cout<<"True";
			return 0;
		}
		
	}
	cout<<"False";
	
}
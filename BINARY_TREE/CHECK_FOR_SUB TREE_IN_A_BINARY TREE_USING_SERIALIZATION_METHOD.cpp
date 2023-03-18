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
node *serialization(node *root,string &s)
{
	if(!root)
	{
		s=s+'&';
		return root;
	}
	s=s+root->val;
	serialization(root->left,s);
	serialization(root->right,s);
	return root;
}
int main()
{
   node *root1=addnode('1');
   root1->left=addnode('2');
   root1->left->left=addnode('4');
   root1->left->right=addnode('5');
   root1->right=addnode('3');
   root1->right->right=addnode('6');
   string s="";
   serialization(root1,s);
   node *root2=addnode('2');
   root2->left=addnode('4');
   root2->right=addnode('5');
   string t="";
   serialization(root2,t);
   if(s.find(t))
   cout<<true;
}
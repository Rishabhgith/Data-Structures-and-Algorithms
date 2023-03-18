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
bool checkutil(node *root,int level,int &leaflevel)
{
	if(!root)
	return true;
	if(!root->left && !root->right)
	{
		if(leaflevel==0)
		{
			leaflevel=level;
			return true;
		}
		return(level==leaflevel);
	}
return checkutil(root->left,level+1,leaflevel) && checkutil(root->right,level+1,leaflevel); 
}
bool check(node *root)
{
	int level=0,leaflevel=0;
	return checkutil(root,level,leaflevel);
}
int main()
{
	node *root=addnode(1);
	root->left=addnode(2);
	root->left->left=addnode(6);
	root->left->right=addnode(8);
	root->right=addnode(3);
	root->right->left=addnode(4);
	root->right->right=addnode(5);
	if (check(root))
    cout << "Leaves are at same level\n";
    else
    cout << "Leaves are not at same level\n";
    
}
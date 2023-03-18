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
int countnodes(node *root)
{   int c=0;
	node *curr=root;
	node *pre;
	while(curr!=NULL)
	{
		if(!curr->left)
		{
			c++;
			curr=curr->right;
		}
		else
		{
			pre=curr->left;
			while(pre->right!=NULL && pre->right!=curr)
			pre=pre->right;
			if(pre->right==NULL)
			{
				pre->right=curr;
				curr=curr->left;
			}
			else
			{
				pre->right=NULL;
				c++;
				curr=curr->right;
			}
		}
	}
	return c;
}
int median(node *root)
{
  int cou=countnodes(root);
  cout<<cou<<endl;
  int c=0;
  node *pre,*prev;
  node *curr=root;
  while(curr!=NULL)
  {
  	if(!curr->left)
  	{
  		c++;
  		if(cou%2!=0 && c==(cou+1)/2)
  		return prev->val;
  		else if(cou%2==0 && c==(cou/2)+1)
  		return(prev->val+curr->val)/2;
  		prev=curr;
  		curr=curr->right;
  	}
  	else
  	{
  	   pre=curr->left;
  	   while(pre->right!=NULL && pre->right!=curr)
  	   pre=pre->right;
  	   if(pre->right==NULL)
  	   {
  	   	pre->right=curr;
  	   	curr=curr->left;
  	   }
  	   else
  	   {
  	   	pre->right=NULL;
  	   	prev=pre;
  	   	c++;
  	   	if(cou%2!=0 && c==(cou+1)/2)
  		return prev->val;
  		else if(cou%2==0 && c==(cou/2)+1)
  		return(prev->val+curr->val)/2;
  		prev=curr;
  		curr=curr->right;
  	   	}
  	}
  }
}
int main()
{
	node *root=NULL;
	root=insert(root,50);
	root=insert(root,40);
	root=insert(root,30);
	root=insert(root,45);
	root=insert(root,47);
	root=insert(root,60);
	root=insert(root,55);
	root=insert(root,65);
	cout<<median(root);
}
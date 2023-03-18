#include<bits/stdc++.h>
using namespace std;
struct node
{
	int val;
	node *prev;
};
node *addnode(int data)
{
	node *t=new node();
	t->val=data;
	t->prev=NULL;
	return t;
}

void multiply(node *&tail,int n)
{
	node *temp=tail,*prevnode=tail;
	int c=0;
	while(temp!=NULL)
	{
		int data=temp->val*n+c;
		temp->val=data%10;
		c=data/10;
		prevnode=temp;
		temp=temp->prev;
	}
	while(c!=0)
	{
		prevnode->prev=addnode(c%10);
		c=c/10;
		prevnode=prevnode->prev;
	}
}
void printnode(node *tail)
{
	if(tail==NULL)
	return;
 printnode(tail->prev);
 cout<<tail->val<<" ";
}

int main()
{
int n=5;
node *tail=addnode(1);
for(int i=2; i<=n; i++)
multiply(tail,i);
printnode(tail);
}
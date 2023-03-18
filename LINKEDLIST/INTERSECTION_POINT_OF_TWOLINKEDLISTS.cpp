#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node *next;
};
int cou(node *head)
{
	int c=0;
	while(head!=NULL)
	{
		c++;
		head=head->next;
	}
	return c;
}

int getintersec(node *head1,node *head2,int d)
{
	node *curr1=head1;
	node *curr2=head2;
	
for(int i=0; i<d; i++)
{
	if(curr1==NULL)
	return -1;
	curr1=curr1->next;
}
while(curr1!=NULL && curr2!=NULL)
{
	if(curr1==curr2)
	return curr1->data;
	
	
curr1=curr1->next;
curr2=curr2->next;	
}
}

int getintersectionnode(node *head1,node *head2)
{   int d;
	int d1=cou(head1);
	int d2=cou(head2);
	if(d1>d2)
	{   d=d1-d2;
		return getintersec(head1,head2,d);
	}
	else
	{
		d=d2-d1;
		return getintersec(head2,head1,d);
	}
	
}

int main()
{
	node *head1=new node();
	head1->data=10;
	node *head2=new node();
	head2->data=3;
	node *newnode;
	
	newnode=new node();
	newnode->data=6;
	head2->next=newnode;
	
	newnode=new node();
	newnode->data=9;
	head2->next->next=newnode;
	
	newnode=new node();
	newnode->data=15;
	head1->next=newnode;
	head2->next->next->next=newnode;
	
	newnode=new node();
	newnode->data=30;
	head1->next->next=newnode;
	head1->next->next->next=NULL;
	cout << "The node of intersection is "<<endl;
	cout<<getintersectionnode(head1,head2);
}

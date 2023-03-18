#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node *next;
	node *prev;
};

void insert(node **head,int newdata)
{
	node *temp=new node();
	temp->data=newdata;
	temp->next=*head;
	temp->prev=NULL;
	if(*head!=NULL)
	{
		(*head)->prev=temp;
	}
	(*head)=temp;
	
}

void pairsum(node *head,int x)
{
	node *first=head;
	node *second=head;
while(second->next!=NULL)
second=second->next;

bool found=false;
while(first!=second && second->next!=first)//when first comes ahead of second
{
	if(first->data+second->data==x)
	{
		found=true;
		cout<<first->data<<" "<<second->data<<endl;
		first=first->next;
		second=second->prev;
	}
	else
	{
		if(first->data+second->data<x)
		first=first->next;
		else
		second=second->prev;
	}
}
if(found==false)
cout<<"NO PAIR FOUND"<<endl;
}

int main()
{
	node *head=NULL;
	insert(&head, 9);
    insert(&head, 8);
    insert(&head, 6);
    insert(&head, 5);
    insert(&head, 4);
    insert(&head, 2);
    insert(&head, 1);
    int x=7;
    pairsum(head,x);
}
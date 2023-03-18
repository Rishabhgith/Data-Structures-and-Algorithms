#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node *next;
	node *prev;
};

void push(node **head,int newdata)
{
	node *temp=new node();
	temp->data=newdata;
	temp->prev=NULL;
	temp->next=*head;
	if(*head!=NULL)
	(*head)->prev=temp;
	*head=temp;
}

void printlist(node *head)
{
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head=head->next;
	}cout<<endl;
}
void reverse(node **head)
{
	node *ptr1=*head;
	node *ptr2=ptr1->next;
	ptr1->next=NULL;
	ptr1->prev=ptr2;
	while(ptr2!=NULL)
	{
		ptr2->prev=ptr2->next;
		ptr2->next=ptr1;
		ptr1=ptr2;
		ptr2=ptr2->prev;
	}
	*head=ptr1;
}

int main()
{
	node *head=NULL;
	 push(&head, 2);
    push(&head, 4);
    push(&head, 8);
    push(&head, 10);
    printlist(head);
    cout<<"REVERSED LINKED LIST"<<endl;
    reverse(&head);
    printlist(head);
}
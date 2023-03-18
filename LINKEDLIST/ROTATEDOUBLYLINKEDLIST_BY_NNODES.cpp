#include<bits/stdc++.h>
using namespace std;
struct node
{
	char data;
	node *next;
	node *prev;
};
void printlist(node *head)
{
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
	cout<<endl;
}
void push(node **head,char newdata)
{
	node *t=new node();
	t->data=newdata;
	t->next=*head;
	t->prev=NULL;
	if((*head)!=NULL)
	(*head)->prev=t;
	*head=t;
}
void rotateby(node** head,int n)
{
	if(n==0)
	return;

node *temp=*head;
while(temp->next!=NULL){
temp=temp->next;}
temp->next=*head;
(*head)->prev=temp;
int count=1;
while(count<=n)
{
	*head=(*head)->next;
	temp=temp->next;
	count++;
}
temp->next=NULL;
(*head)->prev=NULL;
}

int main()
{
	node *head=NULL;
	push(&head,'e');
	push(&head,'d');
	push(&head,'c');
	push(&head,'b');
	push(&head,'a');
	printlist(head);
	int n=2;
	rotateby(&head,n);
	printlist(head);
}
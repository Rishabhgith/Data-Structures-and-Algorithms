#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node *next;
};
void push(node **head,int newdata)
{
	node *t=new node();
	t->data=newdata;
	t->next=*head;
	*head=t;
}
void printlist(node *head)
{
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head=head->next;
	}cout<<endl;
}
node *dividein(node *head)
{
	node *odd=NULL;
	node *even=NULL;
	node *o=NULL;
	node *e=NULL;
   while(head)
   {
   	if(head->data%2==0)
   	{
   		if(even==NULL)
   		{
   			even=head;
   			e=head;
   		}
   		else
   		{
   			e->next=head;
   			e=e->next;
   		}
   	}
   	else
   	{
   		if(odd==NULL)
   		{
   			odd=head;
   			o=head;
   		}
   		else
   		{
   			o->next=head;
   			o=o->next;
   		}
   	
   	}head=head->next;
   }
if(e)
e->next=odd;
if(o)
o->next=NULL;
if(even)
return even;
return odd;
}

int main()
{
	node *head=NULL;
	push(&head, 11);
    push(&head, 10);
    push(&head, 9);
    push(&head, 6);
    push(&head, 4);
    push(&head, 1);
    push(&head, 0);
    printlist(head);
    head=dividein(head);
    printlist(head);
}
#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node *next;
};
void push(node **head,int newdata)
{
	node *ptr=new node();
	ptr->data=newdata;
	ptr->next=*head;
	
if(*head!=NULL)
{
	node *temp=*head;
	while(temp->next!=*head)
	temp=temp->next;
	temp->next=ptr;
}
else
{
	ptr->next=ptr;
}
*head=ptr;
}
void printlist(node *head)
{
	node *temp=head;
do
{
	cout<<temp->data<<" ";
	temp=temp->next;
}while(temp!=head);
cout<<endl;
}

void deletenode(node **head,int key)
{
	if(*head==NULL)//LINKED LIST IS EMPTY
	return;
	
   if((*head)->data==key && (*head)->next==*head)
   {
   	free(*head);
   	*head=NULL;
   	return;
   }
   
  node *last=*head;
  node *d;
  if((*head)->data==key)
  {
  	while(last->next!=*head)
  	{
  		last=last->next;
  	}
  	last->next=(*head)->next;
  	free(*head);
  	*head=last->next;
  	return;
  }
  
  while(last->next!=*head && last->next->data!=key)
  {
  	last=last->next;
  }
  if(last->next->data==key)
  {
  	d=last->next;
  	last->next=d->next;
  	free(d);
  	
  }
  else
  {
  	cout<<"NO SUCH KEYWORD"<<endl;
  }
}
int main()
{
	node *head=NULL;
	push(&head,2);
	push(&head,5);
	push(&head,7);
	push(&head,8);
	push(&head,10);
	printlist(head);
	deletenode(&head,2);
	printlist(head);
}
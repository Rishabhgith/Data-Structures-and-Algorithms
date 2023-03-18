#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node *next;
};
void push(node **head,int newdata)
{
	node *temp=new node();
	temp->data=newdata;
	temp->next=*head;
	*head=temp;
}
void printlist(node *head)
{
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
}

node * middlenode(node *head)
{
	node *slow=head;
	node *fast=head;
  
   while(fast!=NULL && fast->next!=NULL)
   {
   	slow=slow->next;
   	fast=fast->next->next;
   }
   return slow;
}
int main()
{
	node *head=NULL;
	push(&head,6);
	push(&head,5);
	push(&head,4);
	push(&head,3);
	push(&head,2);
	push(&head,1);
	
	node *ans=middlenode(head);
	printlist(ans);
}
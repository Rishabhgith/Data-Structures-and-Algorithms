#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node *next;
};
node *newnode(int newdata)
{
	node *temp=new node();
	temp->data=newdata;
	temp->next=NULL;
	return temp;
}
void printlist(node *head)
{
	node *curr=head;
	do
	{
		cout<<curr->data<<" ";
		curr=curr->next;
	}while(curr!=head);
	cout<<endl;
}
void splitlist(node *head,node** head1,node** head2)
{
	node *slow=head;
	node *fast=head->next;
	while(fast!=head && fast->next!=head)
	{
		slow=slow->next;
		fast=fast->next->next;
	}
  *head1=head;
  *head2=slow->next;
  slow->next=*head1;
  node *current=*head2;
  while(current->next!=head)
  {
  	current=current->next;
  }
  current->next=*head2; 
}

int main()
{
	node *head1=NULL;
	node *head2=NULL;
	node *head=NULL;
	
    head=newnode(11);
    head->next=newnode(2);
    head->next->next=newnode(56);
    head->next->next->next=newnode(12);
    head->next->next->next->next=head;
    
printlist(head);
splitlist(head,&head1,&head2);
printlist(head1);
printlist(head2);
}
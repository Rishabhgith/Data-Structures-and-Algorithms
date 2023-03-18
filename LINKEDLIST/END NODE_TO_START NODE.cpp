#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node *next;
};
void pushnode(node **head,int newdata)
{
	node *temp=new node();
	temp->data=newdata;
	temp->next=*head;
	*head=temp;
}
void printlist(node *t)
{
	while(t!=NULL)
	{
		cout<<t->data<<" ";
		t=t->next;
	}
	cout<<endl;
}
void endtostart(node **head)
{
	node *temp=*head;
	node *prev=NULL;
	
while(temp!=NULL)
{   if(temp->next==NULL)
{
	prev->next=NULL;
	temp->next=*head;
	*head=temp;
	return;
}
	else
	{
		prev=temp;
		temp=temp->next;
	}
}
}

int main()
{
	node *head=NULL;
	pushnode(&head, 5);
    pushnode(&head, 4);
    pushnode(&head, 3);
    pushnode(&head, 2);
    pushnode(&head, 1);
    cout<<"BEFORE- "<<endl;
    printlist(head);
    endtostart(&head);
    cout<<"AFTER- "<<endl;
    printlist(head);
}
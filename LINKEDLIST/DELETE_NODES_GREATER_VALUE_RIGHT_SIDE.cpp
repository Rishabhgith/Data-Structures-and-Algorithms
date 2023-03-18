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
node *reverseit(node **head)
{
	node *prev=NULL;
	node *curr=*head;
	node *next;
	while(curr!=NULL)
	{
		next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
	}
	return prev;
}

void delgr(node **head)
{
	*head=reverseit(&*head);
	int mx=(*head)->data;
	node *prev=*head;
	node *curr=(*head)->next;
	while(curr!=NULL)
	{
		if(mx>curr->data)
		{
			node *temp=curr;
			prev->next=curr->next;
			curr=curr->next;
			delete(temp);
		}
		else
		{
			mx=max(mx,curr->data);
			prev=curr;
			curr=curr->next;
		}
	}
	*head=reverseit(&*head);
}

int main()
{
	node *head=NULL;
	push(&head,11);
	push(&head,10);
	push(&head,18);
	push(&head,20);
	push(&head,14);
	push(&head,15);
	printlist(head);
	delgr(&head);
	printlist(head);
	
}
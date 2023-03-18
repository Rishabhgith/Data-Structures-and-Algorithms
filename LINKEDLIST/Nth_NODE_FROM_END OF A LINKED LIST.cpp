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
node *reverse(node *u)
{
	node *next;
	node *prev=NULL;
	while(u!=NULL)
	{
		next=u->next;
		u->next=prev;
		prev=u;
		u=next;
	}
	return prev;
}
void printreverse(node *head,int x)
{
	node *temp=reverse(head);
	int count=1;
	while(temp!=NULL)
	{
		if(count==x)
		{
			cout<<temp->data;
			return;
		}
		else
		{
			temp=temp->next;
			count++;
		}
		
	}cout<<"Element not found"<<endl;
}
int main()
{
	node *head=NULL;
	push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 35);
    int n=4;
    printreverse(head,n);
    
}
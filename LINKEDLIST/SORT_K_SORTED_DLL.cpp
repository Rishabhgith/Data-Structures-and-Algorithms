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
	node *t=new node();
	t->data=newdata;
	t->prev=NULL;
	t->next=*head;
	if(*head!=NULL)
	(*head)->prev=t;
	*head=t;
}
struct compare {
    bool operator()(struct node* p1, struct node* p2)
    {
        return p1->data > p2->data;
    }
};
node *sortksortedDLL(node *head,int k)
{
	if(head==NULL)
	return head;
	priority_queue<node*,vector<node*>,compare>pq;
	node *newhead=NULL;
	node *last;
	for(int i=0;head!=NULL&&i<=k; i++)
	{
		pq.push(head);
		head=head->next;
	}
while(!pq.empty())
{
	if(newhead==NULL)
	{
		newhead=pq.top();
		newhead->prev=NULL;
		last=newhead;
	}
else
{
	last->next=pq.top();
	pq.top()->prev=last;
	last=pq.top();
}
pq.pop();
if(head!=NULL)
{
	pq.push(head);
	head=head->next;
}

}
last->next=NULL;
return newhead;
}

void printlist(node *head)
{
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head=head->next;
	}cout<<endl;
}

int main()
{
	node *head=NULL;
	push(&head, 8);
    push(&head, 56);
    push(&head, 12);
    push(&head, 2);
    push(&head, 6);
    push(&head, 3);
    int k=2;
    printlist(head);
    head=sortksortedDLL(head,k);
    printlist(head);
}
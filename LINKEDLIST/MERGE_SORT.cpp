//https://www.youtube.com/watch?v=1aPXol8cHcg FLAMY BRUH
#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node *next;
};
node* sortedmerge(node* a, node* b);
void frontbacksplit(node* head,
                    node** front, node** back);
void push(node **a,int newdata)
{
	node *t=new node();
	t->data=newdata;
	t->next=*a;
	*a=t;
}
void mergesort(node **x)
{
	node *head=*x;
	node *a;
	node *b;
	if(head==NULL || head->next==NULL)
	return;
	
frontbacksplit(head,&a,&b);
mergesort(&a);
mergesort(&b);
*x=sortedmerge(a,b);
}
void frontbacksplit(node *head,node**front,node**back)
{
	node *fast;
	node *slow;
	slow=head;
	fast=head->next;
	while(fast!=NULL)
	{
		fast=fast->next;
		if(fast!=NULL)
		{
			fast=fast->next;
			slow=slow->next;
		}
		
	}
	
	*front=head;
	*back=slow->next;
	slow->next=NULL;
}

node *sortedmerge(node *a,node*b)
{
	node *dummy=new node();
	dummy->data=0;
	dummy->next=NULL;
	node *last=dummy;
	while(a!=NULL && b!=NULL)
	{
		if(a->data<b->data)
		{
			last->next=a;
			a=a->next;
			last=last->next;
		}
		else
		{
			last->next=b;
			b=b->next;
			last=last->next;
		}
	}
if(a!=NULL)
last->next=a;
if(b!=NULL)
last->next=b;
return dummy->next;
}
void printlist(node *head)
{
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
	cout<<"\n";
}

int main()
{
	node *z=NULL;
	push(&z, 15);
    push(&z, 10);
    push(&z, 5);
    push(&z, 20);
    push(&z, 3);
    push(&z, 2);
    
mergesort(&z);
printlist(z);
}

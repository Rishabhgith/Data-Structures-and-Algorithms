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
	}
	 cout<<endl;
}

node *gettail(node *curr)
{
	while(curr!=NULL && curr->next!=NULL)
	{
		curr=curr->next;
	}
	return curr;
}
node *partition(node *head,node *tail)
{
	node *pivot=head;
	node *curr=head->next;
	node *prev=head;
	node *last=tail->next;
	while(curr!=last)
	{
		if(pivot->data>curr->data)
		{
			swap(prev->next->data,curr->data);
			prev=prev->next;
		}
		curr=curr->next;
	}
	swap(prev->data,pivot->data);
	return prev;
}

void solvesort(node *head,node*tail)
{
	if(head==NULL || tail==NULL || head==tail)
	return;
	
	node *pivot=partition(head,tail);
	solvesort(head,pivot);
	solvesort(pivot->next,tail);
}

void quicksort(node **headref)
{
	node *head=*headref;
	if(head==NULL || head->next==NULL)
	return;
	node *tail=gettail(head);
	solvesort(head,tail);
	
}
int main()
{
	node *a=NULL;
	push(&a, 5);
    push(&a, 20);
    push(&a, 4);
    push(&a, 3);
    push(&a, 30);
 printlist(a);
 quicksort(&a);
 printlist(a);
}













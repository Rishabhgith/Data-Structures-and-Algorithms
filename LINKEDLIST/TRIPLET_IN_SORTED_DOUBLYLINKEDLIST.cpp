#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node *next;
	node *prev;
};
void insert(node **head,int newdata)
{
	node *t=new node();
	t->data=newdata;
	t->prev=NULL;
	t->next=*head;
	if(*head!=NULL)
	(*head)->prev=t;
*head=t;
}
int countpairs(node *first,node *second,int value)
{
	int count=0;
	while(first!=NULL && second!=NULL && first!=second && second->next!=first)
	{
		if(first->data+second->data==value)
		{
			count++;
			first=first->next;
			second=second->next;
		}
		else
		{
			if(first->data+second->data>value)
			second=second->prev;
			else
			first=first->next;
		}
	}
	return count;
}
int counttriplets(node *head,int x)
{
	if(head==NULL)
	return 0;
	node *current,*first,*last;
	int count=0;
	last=head;
	while(last->next!=NULL)
	last=last->next;
	
for(current=head; current!=NULL; current=current->next)
{
	first=current->next;
	count+=countpairs(first,last,x-current->data);
}
return count;
}
int main()
{
	node *head=NULL;
	insert(&head, 9);
    insert(&head, 8);
    insert(&head, 6);
    insert(&head, 5);
    insert(&head, 4);
    insert(&head, 2);
    insert(&head, 1);
    int x=17;
    cout << "Count = "
         << counttriplets(head, x);
}
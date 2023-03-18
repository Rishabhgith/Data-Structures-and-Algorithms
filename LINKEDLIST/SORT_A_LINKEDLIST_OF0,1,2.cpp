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

void sortlist(node *head)
{
	int count[3]={0,1,2};
	node *ptr=head;
	while(ptr!=NULL)
	{
		count[ptr->data]+=1;
		ptr=ptr->next;
	}
	int i=0;
	ptr=head;
	while(ptr!=NULL)
	{
		if(count[i]==0)
		i++;
		else
		{
			ptr->data=i;
			--count[i];
			ptr=ptr->next;
		}
	}
}
int main()
{
	node *head=NULL;
	push(&head, 0);
    push(&head, 1);
    push(&head, 0);
    push(&head, 2);
    push(&head, 1);
    push(&head, 1);
    push(&head, 2);
    push(&head, 1);
    push(&head, 2);
    printlist(head);
    sortlist(head);
    printlist(head);
}
#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node *next;
};

void push(node **head,int data)
{
	node *temp=new node();
	temp->data=data;
	temp->next=*head;
	*head=temp;
}

void removeduplicates(node *head)
{
	node *current=head;
	node *nextnext;
	if(current==NULL)
	return;
	
while(current->next!=NULL)
{
	if(current->data==current->next->data)
	{
	nextnext=current->next->next;
	free(current->next);
	current->next=nextnext;
	}
else
{
	current=current->next;
}
}
}

void printlist(node *t)
{
	while(t!=NULL)
	{
		cout<<t->data<<" ";
		t=t->next;
	}
	cout<<"\n";
}
int main()
{
	node *head=NULL;
	push(&head, 20); 
    push(&head, 13); 
    push(&head, 13); 
    push(&head, 11); 
    push(&head, 11); 
    push(&head, 11); 
    
     cout<<"Linked list before duplicate removal "; 
    printlist(head); 
    
    removeduplicates(head);
    
    cout<<"Linked List after removal of duplicates"<<endl;
    printlist(head);
}
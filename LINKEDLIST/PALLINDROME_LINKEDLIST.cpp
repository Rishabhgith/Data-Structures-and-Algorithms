//https://www.youtube.com/watch?v=7zzWLuDu7M4
#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node *next;
};

void push(node **head,int newdata)
{
	node *temp=new node();
	temp->data=newdata;
	temp->next=*head;
	*head=temp;
}
bool ispallindrome(node *head)
{
	node *slow=head;
	node *fast=head;
while(fast!=NULL && fast->next!=NULL)
{
	slow=slow->next;
	fast=fast->next->next;
}
node *prev=NULL;
node *next;
node *curr=slow;
while(curr!=NULL)
{
	next=curr->next;
	curr->next=prev;
	prev=curr;
	curr=next;
}
fast=head;
while(prev!=NULL)
{
	if(fast->data!=prev->data)
	return false;
	prev=prev->next;
	fast=fast->next;
}
return true;
}
int main()
{
	node *head=NULL;
	push(&head,1);
	push(&head,2);
	push(&head,3);
	push(&head,2);
	push(&head,1);
	
if(ispallindrome(head))
cout<<"YES IT IS PALLINDROME"<<endl;
else
cout<<"NOT PALLINDROME"<<endl;
}
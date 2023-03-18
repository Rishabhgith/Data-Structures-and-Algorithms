#include<bits/stdc++.h>
using namespace std;
struct node
{
	int key;
	node *next;
	
};

void detectandremoveloop(node *head)
{
	if(head==NULL || head->next==NULL)
	return;
	
	node *slow=head;
	node *fast=head;
	slow=slow->next;
	fast=fast->next->next;
	
while(fast && fast->next)
{
	if(slow==fast)
	break;
	slow=slow->next;
	fast=fast->next->next;
}
if(slow==fast)
{
slow=head;
// this check is needed when slow
        // and fast both meet at the head of the LL
          // eg: 1->2->3->4->5 and then
        // 5->next = 1 i.e the head of the LL
if(slow==fast)                           
{
	while(fast->next!=slow)
	fast=fast->next;
}
else
{
	while(slow->next!=fast->next)
	{
		slow=slow->next;
		fast=fast->next;
	}
}
fast->next=NULL;

}}

node *newnode(int key)
{
	node *temp=new node();
	temp->key=key;
	temp->next=NULL;
	return temp;
}
void printlist(node*head)
{
	while(head!=NULL)
	{
		cout<<head->key<<" ";
		head=head->next;
	}
}

int main()
{
	node *head= newnode(50);
	head->next=head;
	head->next=newnode(20);
	head->next->next=newnode(15);
	head->next->next->next = newnode(4);
    head->next->next->next->next = newnode(10);
    
    head->next->next->next->next->next = head;
    detectandremoveloop(head);
    cout<<"Linked List after removing loop\n";
    printlist(head);

    
}
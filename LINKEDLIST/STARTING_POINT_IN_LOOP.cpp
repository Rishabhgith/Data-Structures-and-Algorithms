#include<bits/stdc++.h>
using namespace std;
struct node
{
	int key;
	node *next;
};
node *newnode(int key)
{
	node *temp=new node();
	temp->key=key;
	temp->next=NULL;
	return temp;
}

node *detectandremoveloop(node *head)
{
	if(head==NULL || head->next==NULL)
	return NULL;
	
	node *slow=head;
	node *fast=head;
	slow=slow->next;
	fast=fast->next->next;
	 while (fast && fast->next) {
        if (slow == fast)
            break;
        slow = slow->next;
        fast = fast->next->next;
    }
    
    if(slow!=fast)
    return NULL;
    
    slow=head;
    while(slow!=fast)
    {
    	slow=slow->next;
    	fast=fast->next;
    }
    return slow;
    
	
}


int main()
{
	node *head= newnode(50);
	head->next=newnode(20);
	head->next->next=newnode(15);
	head->next->next->next=newnode(4);
	head->next->next->next->next=newnode(10);
	
	/* Create a loop for testing */
    head->next->next->next->next->next = head->next->next;
    
    node *res=detectandremoveloop(head);
    if (res == NULL)
        cout << "Loop does not exist";
    else
        cout << "Loop starting node is " << res->key;
        
    return 0;
}
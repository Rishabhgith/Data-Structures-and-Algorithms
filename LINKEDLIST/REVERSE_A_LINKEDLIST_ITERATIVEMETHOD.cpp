#include <iostream>
using namespace std;
  
struct Node
{
	int data;
	Node *next;
	
	Node(int data)
	{
		this->data=data;
		next=NULL;
	}
	
};

struct linkedlist
{
	Node *head;
	linkedlist()
	{
		head=NULL;
	}
	
	void push(int data)
	{
		Node *temp=new Node(data);
		temp->next=head;
		head=temp;
	}
	
void print()
{
	Node *temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}
void reverse()
{
	Node *current=head;
Node *prev=NULL;
Node *next=NULL;
while(current!=NULL)
{
	next=current->next;
	current->next=prev;
	prev=current;
	current=next;
}
head=prev;

}

};

int main()
{
    /* Start with the empty list */
    linkedlist ll;
    ll.push(20);
    ll.push(4);
    ll.push(15);
    ll.push(85);
  
    cout << "Given linked list\n";
    ll.print();
  
    ll.reverse();
  
    cout << "\nReversed Linked list \n";
    ll.print();
    return 0;
}





















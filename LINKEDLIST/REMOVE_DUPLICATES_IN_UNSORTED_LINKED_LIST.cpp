#include<bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node *next;
};

node *newnode(int data)
{
	node *temp=new node();
	temp->data=data;
	temp->next=NULL;
	return temp;
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

void removeduplicates(node *head)
{
	unordered_set<int>seen;
	node *curr=head;
	node *prev=NULL;
	while(curr!=NULL)
	{
		if(seen.find(curr->data)!=seen.end())
		{
			prev->next=curr->next;
			delete(curr);
		}
		else
		{
			seen.insert(curr->data);
			prev=curr;
			
		}curr=prev->next;
	}
}

int main()
{
	 /* The constructed linked list is:
     10->12->11->11->12->11->10*/
     node* head = newnode(10);
    head->next = newnode(12);
    head->next->next = newnode(11);
    head->next->next->next = newnode(11);
    head->next->next->next->next = newnode(12);
    head->next->next->next->next->next = newnode(11);
    head->next->next->next->next->next->next = newnode(10);
    cout<<"Before deletion of duplicate elements"<<"\n";
    printlist(head);
    
    removeduplicates(head);
    cout<<"After deletion of duplicate elements"<<endl;
    printlist(head);
    
}
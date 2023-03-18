#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node *next;
};
node *newnode(int newdata)
{
	node *temp=new node();
	temp->data=newdata;
	temp->next=NULL;
	return temp;
}
bool iscircular(node *head)
{
	if(head==NULL)
	return true;
	
node *curr=head->next;
while(curr!=head && curr!=NULL)
{
	curr=curr->next;
}
if(curr==head)
return true;
else
return false;
}

int main()
{
	node *head= newnode(1);
    head->next = newnode(2);
    head->next->next = newnode(3);
    head->next->next->next = newnode(4);
    
    iscircular(head)? cout<<"YES\n":cout<<"NO\n";
    head->next->next->next->next=head;
    iscircular(head)?cout<<"YES\n":cout<<"NO\n";
    return 0;
}
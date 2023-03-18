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
	temp->next=(*head);
	(*head)=temp;
}
node *newnode(int data)
{
	node *t=new node();
	t->data=data;
	t->next=NULL;
	return t;
}

node *addtwolists(node *first,node *second)
{
	node *res=NULL;
	node *temp,*prev=NULL;
	int carry=0;
	int sum;
while(first!=NULL || second!=NULL)
{
	sum=carry +(first?first->data:0) + (second?second->data:0);
	carry=(sum>=10)?1:0;
	sum=sum%10;
	temp=newnode(sum);
	if(res==NULL){
	res=temp;}
	else{
	prev->next=temp;}
	
	prev=temp;
	
	if(first)
	first=first->next;
	if(second)
	second=second->next;
	
}
if(carry>0)
temp->next=newnode(carry);

return res;
}

node *reverse(node *head)
{
	node *next=NULL;
	node *prev=NULL;
	node *curr=head;
	while(curr!=NULL)
	{
		next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
	}
	return prev;
	
}
void printlist(node *head)
{
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head=head->next;
	}cout<<endl;
}

int main()
{
	node *res=NULL;
	node *first=NULL;
	node *second=NULL;
	
	push(&first, 6);
    push(&first, 4);
    push(&first, 9);
    push(&first, 5);
    push(&first, 7);
    cout<<"FIRST LIST IS"<<endl;
    printlist(first);
    
    cout<<"CREATE SECOND LIST"<<endl;
    push(&second,4);
    push(&second,8);
    
    printlist(second);
   // REVERSE THE LISTS
    first=reverse(first);
    second=reverse(second);
    res=addtwolists(first,second);
    res=reverse(res);
    printlist(res);
}




































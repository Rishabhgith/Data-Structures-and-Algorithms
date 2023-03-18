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
int multiply(node *first,node *second)
{
	int num1=0;
	int num2=0;
	while(first || second)
	{
		if(first)
		{
			num1=num1*10+first->data;
			first=first->next;
		}
		if(second)
		{
			num2=num2*10+second->data;
			second=second->next;
		}
	}
	return num1*num2;
}
int main()
{
	node *first=NULL;
	node *second=NULL;
	push(&first,1);
	push(&first,2);
	push(&first,3);
	push(&second,2);
	push(&second,1);
  cout<<multiply(first,second)<<endl;
}
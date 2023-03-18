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

void printlist(node *head)
{
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
	cout<<endl;
}
void intersectionlist(node *first,node *second)
{
	set<int>s;
	while(first!=NULL)
	{
		s.insert(first->data);
		first=first->next;
	}
	
	vector<int>a;
	while(second !=NULL)
	{
		if(s.find(second->data)!=s.end())
		{
			a.push_back(second->data);
		}
	second=second->next;
	}
	
for(auto j:a)
cout<<j<<" ";
}

int main()
{
	node *first=NULL;
	push(&first,6);
	push(&first,5);
	push(&first,4);
	push(&first,3);
	push(&first,2);
	push(&first,1);
	
	node *second=NULL;
	push(&second,8);
	push(&second,6);
	push(&second,4);
	push(&second,2);
	
	cout<<"FIRST LIST"<<endl;
		printlist(first);
	cout<<"SECOND LIST"<<endl;
	printlist(second);
	
	
	intersectionlist(first,second);
	
}
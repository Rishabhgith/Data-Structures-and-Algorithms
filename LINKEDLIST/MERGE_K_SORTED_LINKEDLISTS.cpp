#include<bits/stdc++.h>
using namespace std;
struct node
{
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
node *sortedmerge(node *a,node *b)
{
	node *result=NULL;
	if(a==NULL)
	return b;
	if(b==NULL)
	return a;
	if(a->data <= b->data)
	{
		result=a;
		result->next=sortedmerge(a->next,b);
	}
	else
	{
		result=b;
		result->next=sortedmerge(a,b->next);
	}
	return result;
}

node *mergelists(node *arr[],int last)
{
	while(last!=0)
	{
		int i=0,j=last;
		while(i<j)
		{
			arr[i]=sortedmerge(arr[i],arr[j]);
			i++,j--;
			if(i>=j)
			last=j;
		}
	}
	return arr[0];
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
	int k=3;
	int n=4;
	node *arr[k];
	arr[0]=newnode(1);
	arr[0]->next=newnode(3);
	arr[0]->next->next=newnode(5);
	arr[0]->next->next->next=newnode(7);
	
	arr[1]=newnode(2);
	arr[1]->next=newnode(4);
	arr[1]->next->next=newnode(6);
	arr[1]->next->next->next=newnode(8);
	
	arr[2]=newnode(0);
	arr[2]->next=newnode(9);
	arr[2]->next->next=newnode(10);
	arr[2]->next->next->next=newnode(11);
	
	node *head= mergelists(arr,k-1);
	printlist(head);
}
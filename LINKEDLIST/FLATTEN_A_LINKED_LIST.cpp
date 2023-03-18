//VERY EASY YOU GOT IT VERY WELL BELIEVE ME
#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data;
	node *right;
	node *down;
};
node *head=NULL;
node *push(node *head,int newdata)
{
	node *newnode=new node();
	newnode->data=newdata;
	newnode->right=NULL;
	newnode->down=head;
	head=newnode;
	return head;
}

void printlist()
{
	node *temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->down;
	}cout<<endl;
}

node *merge(node *a,node *b)
{
	if(a==NULL)
	return b;
	if(b==NULL)
	return a;
	node *result;
	if(a->data<b->data)
	{
		result=a;
		result->down=merge(a->down,b);
	}
	else
	{
		result=b;
		result->down=merge(a,b->down);
	}
	result->right=NULL;
	return result;
}

node *flatten(node *root)
{
	if(root==NULL || root->right==NULL)
	return root;
	root->right=flatten(root->right);
	root=merge(root,root->right);
	return root;
}
int main()
{
	head = push(head, 30);
    head = push(head, 8);
    head = push(head, 7);
    head = push(head, 5);
    head->right = push(head->right, 20);
    head->right = push(head->right, 10);
    head->right->right = push(head->right->right, 50);
    head->right->right = push(head->right->right, 22);
    head->right->right = push(head->right->right, 19);
    head->right->right->right = push(head->right->right->right, 45);
    head->right->right->right = push(head->right->right->right, 40);
    head->right->right->right = push(head->right->right->right, 35);
    head->right->right->right = push(head->right->right->right, 20);
    head=flatten(head);
    printlist();
    return 0;
}
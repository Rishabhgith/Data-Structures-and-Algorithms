#include<bits/stdc++.h>
#define maxchar 256
using namespace std;
struct node
{
	 char a;
	 node *next;
	 node *prev;
};

void appendnode(struct node** head_ref,
                struct node** tail_ref, char x)
{
    struct node* temp = new node;
    temp->a = x;
    temp->prev = temp->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = *tail_ref = temp;
        return;
    }
    (*tail_ref)->next = temp;
    temp->prev = *tail_ref;
    *tail_ref = temp;
}
void removenode(struct node** head_ref,
                struct node** tail_ref, struct node* temp)
{
    if (*head_ref == NULL)
        return;

    if (*head_ref == temp)
        *head_ref = (*head_ref)->next;
    if (*tail_ref == temp)
        *tail_ref = (*tail_ref)->prev;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    delete (temp);
}

void firstnonrepeating()
{   node *indll[maxchar];
    bool repeated[maxchar];
    node *head=NULL;
    node *tail=NULL;
    for(int i=0; i<maxchar; i++)
    {
    	indll[i]=NULL;
    	repeated[i]=false;
    }
    char stream[] = "geeksforgeeksandgeeksquizfor";
    for (int i = 0; stream[i]; i++) {
        char x = stream[i];
        cout << "Reading " << x << " from stream \n";
        if(!repeated[x]){
        if(indll[x]==NULL)
        {
        	appendnode(&head, &tail, stream[i]);
        	indll[x]=tail;
        }
        else
        {
        	removenode(&head, &tail, indll[x]);
        	indll[x]=NULL;
        	repeated[x]=true;
        }}
        if(head!=NULL)
        {
        	cout << "First non-repeating character so far "
                    "is "
                 << head->a << endl;
        }}
        
	
}
int main()
{
	firstnonrepeating();
	return 0;
}
//Insertion and Reversing the Linked List

#include <iostream>
using namespace std;
struct node 
{
	int data;
	struct node* next;
};

void insert(struct node** head, int ndata)
{
	struct node* newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=ndata;
	newnode->next=(*head);
	(*head)=newnode;
}
void printlist(struct node* head)
{
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
}

void reverse(struct node** head)
{
	struct node* prev=NULL;
	struct node* curr=(*head);
	struct node* next;
	while(curr!=NULL)
	{
		next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
	}
	*head=prev;
}

int main() {
	struct node* a=NULL;
	insert(&a,10);
	insert(&a,15);
	insert(&a,20);
	insert(&a,25);
	insert(&a,30);
	printlist(a);
	
	reverse(&a);
	cout<<endl;
	printlist(a);
	
	return 0;
}
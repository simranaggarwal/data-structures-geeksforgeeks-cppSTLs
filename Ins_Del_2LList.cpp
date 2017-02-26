//Insertion and deletion in doubly linked list
//Traversing from both the ends

#include <iostream>
using namespace std;
struct node
{
	int data;
	struct node* next;
	struct node* prev;
};
void insert(struct node** head, int data)
{	
	struct node* newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=data;
	newnode->next=(*head);
	newnode->prev=NULL;
	if(*head!=NULL)
	{
		(*head)->prev=newnode;
	}
	(*head)=newnode;
}
void printlist(struct node* head)
{
	struct node* temp=head;
	while(temp->next!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<temp->data;
	cout<<endl;
	
	while(temp->prev!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->prev;
	}
	cout<<temp->data;
}
void del(struct node** head, int pos)
{
	struct node* temp=(*head);
	struct node* target;
	for(int i=0;i<pos;i++)
	{
		target=temp;
		temp=temp->next;
	}
	target->prev->next=temp;
	temp->prev=target->prev;
}
int main() {
	struct node* head=NULL;
	insert(&head,10);
	insert(&head,15);
	insert(&head,20);
	insert(&head,25);
	insert(&head,30);
	insert(&head,35);
	printlist(head);
	del(&head,3);
	cout<<endl;
	printlist(head);
	return 0;
}
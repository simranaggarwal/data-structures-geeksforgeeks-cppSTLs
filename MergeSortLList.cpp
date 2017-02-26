// Merge Sort in Linked List

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

struct node* merger(struct node* one, struct node* two)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	struct node* head=temp;
	while((one) && (two))
	{
		if(one->data>two->data)
		{	
			struct node* nnode=(struct node*)malloc(sizeof(struct node));
			nnode->data=two->data;
			temp->next=nnode;
			temp=temp->next;
			two=two->next;
		}
		else
		if(one->data<two->data)
		{
			struct node* nnode=(struct node*)malloc(sizeof(struct node));
			nnode->data=one->data;
			temp->next=nnode;
			temp=temp->next;
			one=one->next;
		}
		else
		if(one->data==two->data)
		{
			struct node* nnode1=(struct node*)malloc(sizeof(struct node));
			struct node* nnode2=(struct node*)malloc(sizeof(struct node));
			nnode1->data=one->data;
			nnode2->data=two->data;
			temp->next=nnode1;
			temp=temp->next;
			temp->next=nnode2;
			temp=temp->next;
			one=one->next;
			two=two->next;
		}
	}
		if(one==NULL)
		{
		    while(two!=NULL)
		    {
		        struct node* nnode=(struct node*)malloc(sizeof(struct node));
		        nnode->data=two->data;
		        temp->next=nnode;
		        temp=temp->next;
		        two=two->next;
		    }
		}
		else
		if(two==NULL)
		{
		    while(one!=NULL)
		    {
			    struct node* nnode=(struct node*)malloc(sizeof(struct node));
		        nnode->data=one->data;
		        temp->next=nnode;
		        temp=temp->next;
		        one=one->next;
		    }
		}
	head=head->next;
	return head;
}

void divhalf(struct node *head, struct node** one, struct node** two)
{	
	struct node* prev;
	struct node* temp=head;
	if(head==NULL || head->next==NULL)
	{
		*one=head;
		*two=NULL;
	}
	else
	{
	int length=0;
	while(temp!=NULL)
	{
		length++;
		temp=temp->next;
	}
	temp=head;
	(*one)=temp;
	int l;
	for(int i=0;i<length/2-1;i++)
	{
		temp=temp->next;
	}
	(*two)=temp->next;
	temp->next=NULL;
	}
}

void mergesort(struct node** head)
{
	struct node* one=NULL;
	struct node* two=NULL;
	struct node* temp=*head;
	if(temp==NULL || temp->next==NULL)
	{
		return;
	}
	divhalf(temp, &one, &two);
	mergesort(&one);
	mergesort(&two);
	*head=merger(one,two);
}

void printlist(struct node* head)
{
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
}

int main() {
	struct node* a=NULL;
	insert(&a,10);
	insert(&a,30);
	insert(&a,25);
	insert(&a,30);
	insert(&a,40);
	insert(&a,15);
	insert(&a,24);
	printlist(a);
	cout<<endl;
	mergesort(&a);
	printlist(a);
	return 0;
}
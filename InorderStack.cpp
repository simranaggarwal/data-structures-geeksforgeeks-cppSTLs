//Inorder traversal of binary tree without recursion


#include <iostream>
#include <stack>
using namespace std;

struct node 
{
	int data;
	struct node* left;
	struct node* right;
};

struct node* insert(int data)
{
	struct node* n= (struct node*)malloc(sizeof (struct node));
	n->data=data;
	n->left=NULL;
	n->right=NULL;
	return (n);
}

int main() {
	
	stack <struct node *> s;
	struct node* current;
	struct node* root= insert(1);
	root->left= insert(2);
	root->right=insert(3);
	root->left->left= insert(4);
	root->left->right= insert(5);
	current=root;
	int f=1;
	while(f)
	{
		while(current!=NULL)
		{
			s.push(current);
			current=current->left;
		}
		if(current==NULL && !s.empty())
		{
			cout<<s.top()->data<<" ";
			current=s.top()->right;
			s.pop();
		}else
		f=0;
			
	}
	return 0;
}
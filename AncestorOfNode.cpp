//Find ancestors of a node in binary tree

#include <iostream>
using namespace std;
int current;
struct node 
{
	int data;
	struct node* left;
	struct node* right;
};

struct node* insert(int data)
{
	struct node* n=(struct node*)malloc(sizeof(struct node));
	n->data=data;
	n->left=NULL;
	n->right=NULL;
	return n;
}

void findparent(struct node* root)
{
	if(root==NULL)
		return;
	
	findparent(root->left);
	findparent(root->right);
	
	if((root->left!=NULL && root->left->data==current) || (root->right!=NULL && root->right->data==current))
	{
		cout<<root->data<<" ";
		current=root->data;
	}
}

int main() 
{
	struct node* root=insert(4);
	root->left=insert(8);
	root->right=insert(2);
	root->left->left=insert(6);
	root->left->right=insert(5);
	root->left->left->right=insert(7);
	root->left->right->left=insert(1);
	root->left->right->right=insert(3);
	current=3;
	findparent(root);
	
	return 0;
}
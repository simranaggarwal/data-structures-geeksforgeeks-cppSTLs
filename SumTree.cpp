//Convert a given tree to its Sum Tree

#include <iostream>
#include <map>
using namespace std;

struct node{
	int data;
	struct node* left;
	struct node* right;
};

struct node* insert(int data)
{
	struct node* n=(struct node*)malloc(sizeof(struct node));
	n->data=data;
	n->right=NULL;
	n->left=NULL;
	
	return n;
}

int sumtree(struct node* root)
{
	if(root==NULL)
		return 0;
	int temp=root->data;
	root->data=sumtree(root->left)+sumtree(root->right);
	return root->data+temp;
}

void inorder(struct node* root)
{
	if(root==NULL)
		return;
	inorder(root->left);
	cout<<(root->data)<<" ";
	inorder(root->right);
}

int main() {
	struct node* root=insert(1);
	root->left=insert(2);
	root->right=insert(3);
	
	root->left->left=insert(4);
	root->left->right=insert(5);
	
	root->right->left=insert(6);
	root->right->right=insert(7);
	sumtree(root);
	inorder(root);
	return 0;
}
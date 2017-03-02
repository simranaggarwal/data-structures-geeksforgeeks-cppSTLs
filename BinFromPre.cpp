//Construct a special tree from given preorder traversal

#include <iostream>
#include <string>

using namespace std;
int pre[] = {10, 30, 20, 5, 15};
string preLN="NNLLL";
int i=0;
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

void inorder(struct node* root)
{
	if(root==NULL)
		return;
	inorder(root->left);
	cout<<(root->data)<<" ";
	inorder(root->right);
}

struct node* stree()
{
	if(i==5)
	{
		return NULL;
	}
	struct node* temp=insert(pre[i]);
	if(preLN[i]=='N')
	{
		i=i+1;
		temp->left=stree();
		i=i+1;
		temp->right=stree();
	}
	return temp;
}

int main() 
{
	int ind=0;
	struct node* root=stree();
	inorder(root);
	return 0;
}
//construct tree from given pre order and inorder traversal

#include <iostream>
#include <string>
using namespace std;
int i=0;

struct node
{
	char data;
	node* left;
	node* right;
};

struct node* insert(int data)
{
	struct node* n=(struct node*)malloc(sizeof(struct node));
	n->data=data;
	n->left=NULL;
	n->right=NULL;
	
	return n;
}

struct node* tree(string in, string pre, int instrt, int inend)
{
	if(instrt>inend)
		return NULL;
	struct node* temp=insert(pre[i]);
	i++;
	
	if(instrt==inend)
	{
		return temp;
	}
	
	string str;
	str.push_back(temp->data);
	int ind=in.find(str);
	
	temp->left=tree(in,pre,instrt,ind-1);
	temp->right=tree(in,pre,ind+1,inend);
	
	return temp;
}

void inorder(struct node* root)
{
	if(root==NULL)
		return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

int main() {
	string in="dbeafc";
	string pre="abdecf";
	
	struct node* root=tree(in,pre,0,in.length());
	
	inorder(root);
	return 0;
}
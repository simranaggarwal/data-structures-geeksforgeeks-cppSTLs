//Vertical sum in a given binary tree

#include <iostream>
#include <map>
using namespace std;

map<int,int>mp;

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

void inorder(struct node* root, int hd)
{
	if(root==NULL)
		return;
	
	inorder(root->left,hd-1);
	mp[hd]+=root->data;
	inorder(root->right,hd+1);
}

int main() {
	struct node* root=insert(1);
	root->left=insert(2);
	root->right=insert(3);
	
	root->left->left=insert(4);
	root->left->right=insert(5);
	
	root->right->left=insert(6);
	root->right->right=insert(7);
	inorder(root,0);
	
	map<int, int>::iterator it;
	for(it=mp.begin();it!=mp.end();it++)
	{
		cout<<(*it).second<<" ";
	}
	
	return 0;
}
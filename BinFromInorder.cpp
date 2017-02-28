//Construct Special Binary Tree from given Inorder traversal

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int>vec;
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

struct node* func(int strt,int endd)
{
	if(strt>endd)
	return NULL;
	
	int ind=max_element(vec.begin()+strt,vec.begin()+endd)-vec.begin();
	struct node* temp=insert(vec[ind]);
	
	if(strt==endd)
	return temp;
	
	temp->left=func(strt,ind-1);
	temp->right=func(ind+1,endd);
	return temp;
}

int main() {
	
	vec.push_back(1);
	vec.push_back(5);
	vec.push_back(10);
	vec.push_back(40);
	vec.push_back(30);
	vec.push_back(15);
	vec.push_back(28);
	vec.push_back(20);
	struct node* root=func(0,7);
	
	inorder(root);
	return 0;
}
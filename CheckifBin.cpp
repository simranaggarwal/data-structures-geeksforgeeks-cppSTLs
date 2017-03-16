//Check whether a given Binary Tree is Complete or not

#include <iostream>
#include <queue>
using namespace std;

struct node {
	int data;
	struct node* left;
	struct node* right;
};

struct node* insert(int data)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	
	return temp;
}

bool ifComplete(struct node* root)
{
	queue<struct node*>q;
	q.push(root);
	bool flag=false;
	while(!q.empty())
	{
		struct node* temp=q.front();
		q.pop();
		if(temp->left)
		{
			if(flag==true)
			return false;
			
			q.push(temp->left);
		}
		else
		flag=true;
		if(temp->right)
		{
			if(flag==true)
			return false;
			
			q.push(temp->right);
		}
		else
		flag=true;
	}
	return true;
}

int main() {
	
	struct node *root  = insert(1);
  	root->left         = insert(2);
  	root->right        = insert(3);
  	root->left->left   = insert(4);
  	root->left->right  = insert(5);
  	root->right->left = insert(6);
	
	bool ans=ifComplete(root);
	cout<<ans;
	
	return 0;
}
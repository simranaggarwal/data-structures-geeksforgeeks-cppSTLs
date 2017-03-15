//Level order traversal 

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
	temp->right=NULL;
	temp->left=NULL;
	return temp;
}

void bfs(struct node* temp)
{
	queue<struct node*>q;
	q.push(temp);
	while(!q.empty())
	{
		struct node* n=q.front();
		cout<<n->data<<" ";
		q.pop();
		if(n->left!=NULL)
		q.push(n->left);
		
		if(n->right!=NULL)
		q.push(n->right);
	}
}

int main() {
	struct node *root = insert(1);
    root->left = insert(2);
    root->right = insert(3);
    root->left->left = insert(4);
    root->left->right = insert(5);
    
    bfs(root);
	return 0;
}
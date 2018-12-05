#include <iostream>

using namespace std;

typedef struct _TreeNode {
	int data;
	uint32_t size;
	struct _TreeNode *left;
	struct _TreeNode*right;
} TreeNode;


uint32_t getSize(TreeNode *node)
{
	if(node == NULL) return 0;
	else return node->size;
}
TreeNode * putTree(TreeNode *root, int val)
{
	if(root == NULL) {
		TreeNode *newnode = (TreeNode *) malloc(sizeof(TreeNode));
		newnode->data = val;
		newnode->size = 1;
		newnode->left = NULL;
		newnode->right = NULL;
		return newnode;
	}
	
	if(root->data > val) {
		root->left = putTree(root->left, val);
	} else if(root->data < val) {
		root->right = putTree(root->right, val);
	}
	root->size = 1 + getSize(root->left) + getSize(root->right);
	return root;
}

TreeNode *getTree(TreeNode *root, int val)
{
	if(root == NULL) return NULL;
	if(root->data > val) 
		return getTree(root->left, val);
	else if(root->data < val)
		return getTree(root->right, val);
	else
		return root;
}

int main()
{

	TreeNode *root = NULL;
	for(int i = 1; i <= 10; i++)
		root = putTree(root, i);
	if(root != NULL)
		cout << root->size << endl;
	TreeNode *nn =  getTree(root, 4);
	if(nn != NULL)
		cout << nn->size << " " << nn->data << endl;
	return 0;
}
	

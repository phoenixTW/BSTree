#include "bsTree.h"
#include <stdlib.h>

BSTree createBSTree(void) {
	return (BSTree){NULL, 0};
}

Node_ptr createTreeNode(int data) {
	Node_ptr node;
	node = calloc(sizeof(Node), 1);
	node->data = data;
	return node;
}

int insert (BSTree *tree, int data) {
	BSTree branch = createBSTree();
	Node_ptr node;

	if (tree->root == NULL) {
		tree->root = createTreeNode(data);
	}

	if(tree->root->data > data) {
		(tree->root->left) && (branch.root = tree->root->left) && insert(&branch, data);
		(!tree->root->left) && (node = createTreeNode(data)) && (tree->root->left = node);
	}

	if(tree->root->data < data) {
		(tree->root->right) && (branch.root = tree->root->right) && insert(&branch, data);
		(node = createTreeNode(data)) && (tree->root->right = node);
	}

	tree->count++;
	return 1;
}

Node_ptr find(BSTree tree, int data) {
	BSTree branch = createBSTree();

	if(tree.root == NULL) return NULL;

	if(tree.root->data == data) return tree.root;

	((tree.root->left) && (data < tree.root->data) && (branch.root = tree.root->left));
	((tree.root->right) && (data > tree.root->data) && (branch.root = tree.root->right));

	return find(branch, data);
}
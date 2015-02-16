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

	((tree->root == NULL) && (tree->root = createTreeNode(data)));

	if(tree->root->data > data) {
		(tree->root->left) && (branch.root = tree->root->left) && insert(&branch, data);
		(!tree->root->left) && (node = createTreeNode(data)) && (tree->root->left = node);
	}

	if(tree->root->data < data) {
		(tree->root->right) && (branch.root = tree->root->right) && insert(&branch, data);
		(node = createTreeNode(data)) && (tree->root->right = node);
	}

	tree->count++;

	return tree->count;
}

Node_ptr find(BSTree tree, int data) {
	BSTree branch = createBSTree();

	if(tree.root == NULL) return NULL;

	if(tree.root->data == data) return tree.root;

	((tree.root->left) && (data < tree.root->data) && (branch.root = tree.root->left));
	((tree.root->right) && (data > tree.root->data) && (branch.root = tree.root->right));

	return find(branch, data);
}

int isLeafNode(Node_ptr node) {
	return !node->left && !node->right ? 1 :0;
}

int interchange(Node_ptr node1,Node_ptr node2) {
	int temp;
	temp = node1->data;
	node1->data = node2->data;
	node2->data = temp;
	return 1;
}

Node_ptr delete(BSTree* tree,int data) {
	BSTree branch = createBSTree();
	Node *treeNode = NULL,*root,*rightChild,*leftChild;
	root = tree->root;
	rightChild = root->right;
	leftChild = root->left;
	
	if(root->data == data) {
		!isLeafNode(root) && rightChild && interchange(rightChild,root) && (branch.root = rightChild)
			&& (treeNode = delete(&branch,data));

		isLeafNode(root) && (treeNode = root) && (tree->root = NULL);
		return treeNode;
	}

	if(!treeNode){
		leftChild && data < root->data && (branch.root = leftChild) && (treeNode = delete(&branch,data));
		rightChild && data > root->data && (branch.root = rightChild) && (treeNode = delete(&branch,data));
	}
	
	if(rightChild && data == rightChild->data)
		isLeafNode(root->right) && (treeNode = root->right) && (root->right = NULL);
	
	if(leftChild && data == leftChild->data)
		isLeafNode(root->left) && (treeNode = root->left) && (root->left = NULL);
	
	tree->count--;	
	return treeNode;
}

void traverse(BSTree tree,traverser function) {
	BSTree branch = createBSTree();
	if(tree.root) {
		if(tree.root->left) {
			branch.root = tree.root->left;
			traverse(branch,function);
		}
	
		function(tree.root->data);
	
		if(tree.root->right) {
			branch.root = tree.root->right;
			traverse(branch,function);
		}
	}
}
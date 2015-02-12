#include "bsTree.h"
#include <stdlib.h>

BSTree createBSTree(void) {
	return (BSTree){NULL, 0};
}

Node_ptr createTreeNode(void *data) {
	Node_ptr node;
	node = calloc(sizeof(Node), 1);
	node->data = data;
	return node;
}
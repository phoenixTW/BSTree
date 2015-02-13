#include "bsTree.h"
#include "expr_assert.h"

BSTree tree;
Node_ptr node;

void setup () {
	tree = createBSTree();	
}

void test_createBSTree_should_return_an_empty_bsTree_with_count_0 () {
	assertEqual(tree.root, 0x0);
	assertEqual(tree.count, 0);
}

void test_createTreeNode_should_return_an_empty_treeNode () {
	Node_ptr node;
	int data = 1;
	node = createTreeNode(data);
	assertEqual(node->data, 1);
	assertEqual(node->left, 0x0);
	assertEqual(node->right, 0x0);
}

void test_insert_should_return_the_count_value_after_each_insertion () {
	int data = 1;
	assertEqual(insert(&tree, data), 1);
	assertEqual(tree.count, 1);

	data = 2;
	assertEqual(insert(&tree, data), 1);
	assertEqual(tree.count, 2);

	data = 0;
	assertEqual(insert(&tree, data), 1);
	assertEqual(tree.count, 3);
}
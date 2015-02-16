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
	assertEqual(insert(&tree, data), 2);
	assertEqual(tree.count, 2);

	data = 0;
	assertEqual(insert(&tree, data), 3);
	assertEqual(tree.count, 3);
}

void test_find_should_return_the_node_whose_data_is_matched_with_the_passing_value () {
	int data = 1;
	Node_ptr result;
	insert(&tree, data);

	data = 2;
	insert(&tree, data);

	data = 0;
	insert(&tree, data);

	result = find(tree, 2);
	assertEqual(result->data, 2);

	data = 5;
	insert(&tree, data);

	result = find(tree, 5);
	assertEqual(result->data, 5);
	assertEqual(result->left, 0x0);
}

void test_find_should_return_null_whose_data_isnt_matched_with_the_passing_value () {
	int data = 1;
	Node_ptr result;
	insert(&tree, data);

	data = 2;
	insert(&tree, data);

	data = 0;
	insert(&tree, data);

	result = find(tree, 3);
	assertEqual(result, 0x0);
}

void test_delete_should_return_deleted_node () {
	int data = 1;
	Node_ptr result;
	insert(&tree, data);

	data = 2;
	insert(&tree, data);

	data = 0;
	insert(&tree, data);

	result = find(tree, 2);
	assertEqual(result->data, 2);

	data = 5;
	insert(&tree, data);

	result = delete(&tree, 5);
	assertEqual(result->data, 5);
	assertEqual(tree.count, 3);

	result = find(tree, 5);
	assertEqual(result, 0x0);

	assertEqual(tree.count, 3);
}

void test_delete_should_return_the_leaf_node_from_the_tree () {
	BSTree tree = createBSTree();
	assertEqual(insert(&tree,8),1);
	assertEqual(insert(&tree,7),2);
	assertEqual(insert(&tree,10),3);
	assertEqual(insert(&tree,5),4);
	assertEqual(delete(&tree,10)->data,10);
	assertEqual(tree.root->right,0);
	assertEqual(delete(&tree,5)->data,5);
	assertEqual(tree.root->left->left,0);
}

void test_delete_should_return_the_root_node_from_the_tree () {
	BSTree tree = createBSTree();
	assertEqual(insert(&tree,8),1);
	assertEqual(delete(&tree,8)->data,8);
	assertEqual(tree.root,0);
}

void test_should_return_the_root_node_of_the_tree_but_should_not_remove_the_tree () {
	BSTree tree = createBSTree();
	assertEqual(insert(&tree,8),1);
	assertEqual(insert(&tree,7),2);
	assertEqual(insert(&tree,10),3);
	assertEqual(delete(&tree,8)->data,8);
	assertEqual(tree.root->data,10);
}

// void test_should_return_the_root_node_of_the_tree_for_multilevel_tree () {
// 	BSTree tree = createBSTree();
// 	assertEqual(insert(&tree,8),1);
// 	assertEqual(insert(&tree,7),2);
// 	assertEqual(insert(&tree,10),3);
// 	assertEqual(insert(&tree,11),4);
// 	assertEqual(delete(&tree,10)->data,10);
// 	assertEqual(tree.root->data,8);
// 	assertEqual(tree.root->right->data,11);
// }

int a[] = {0,1,2,3,4,5,6},b[7];

void put(int a) {
	b[a] = a;
}

void test_traverse_should_give_the_values_in_assending_order() {
	BSTree tree = createBSTree();
	assertEqual(insert(&tree,3), 1);
	assertEqual(insert(&tree,1), 2);
	assertEqual(insert(&tree,5), 3);
	assertEqual(insert(&tree,0), 4);
	assertEqual(insert(&tree,2), 5);
	assertEqual(insert(&tree,4), 6);
	assertEqual(insert(&tree,6), 7);

	traverse(tree,put);
	
	assertEqual(a[0],b[0]);
	assertEqual(a[1],b[1]);
	assertEqual(a[2],b[2]);
	assertEqual(a[3],b[3]);
}

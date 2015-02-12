#include "bsTree.h"
#include "expr_assert.h"

void test_createBSTree_should_return_an_empty_bsTree_with_count_0 () {
	BSTree tree;
	tree = createBSTree();
	assertEqual(tree.root, 0x0);
	assertEqual(tree.count, 0);
}

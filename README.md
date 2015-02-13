# BSTree
A binary search tree of data structure in C


##Version 0.1

Create a Binary Search Tree alias BSTree.

```sh

BSTree createBSTree(void);

```

```sh

	1. It creates a BSTree and returns the values of the tree
	2. BSTree constains a root and count.
	3. root holds the reference of root node.
	4. node contains:
		*	data of int type
		*	reference of node on the left hand side
		*	reference of right on the right hand side

```

##Version 0.2

Insert a value into a tree.

```sh

int insert(BSTree*, int);

```

```sh
	
	1.	If root of the tree is null then the data will be the root of the tree.
	2	If root is available then the method will check whether the data is greater than
		or less than the value of the root.
	3.	If less than,
			*	then the it will go to the left hand side and check that whether
				if it is another subtree or not.
				>	If not then the node will inserted on the very place
				>	If it is then no. 2 will be repeated.
	4.	If greater than,
			*	then the it will go to the right hand side and check that whether
			if it is another subtree or not.
				>	If not then the node will inserted on the very place
				>	If it is then no. 2 will be repeated.

```

```sh

	example: BSTree tree = createBSTree();
			insert(&tree, 23);

```

##Version 0.3

Insert a value into a tree.

```sh

Node_ptr find(BSTree, int);

```

```sh
	
	1.	If root of the tree is null then return null.
	2	If root is available then the method will check whether the data is greater than
		or less than the value of the root.
	3.	If less than,
			*	then the it will go to the left hand side and check that whether
				if it is another subtree or not.
				>	If the value is matched then return that node or return null.
				>	If it is then no. 2 will be repeated.
	4.	If greater than,
			*	then the it will go to the right hand side and check that whether
			if it is another subtree or not.
				>	If the value is matched then return that node or return null.
				>	If it is then no. 2 will be repeated.

```

```sh

	example: BSTree tree = createBSTree();
			insert(&tree, 23);
			find(tree, 23); // return the node

```
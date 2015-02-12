typedef struct node Node;
typedef struct tree BSTree;
typedef Node* Node_ptr;

struct node {
	void *data;
	Node_ptr left;
	Node_ptr right;
};

struct tree {
	Node_ptr root;
	int count;	
};

BSTree createBSTree(void);
Node_ptr createTreeNode(void*);
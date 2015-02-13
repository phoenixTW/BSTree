typedef struct node Node;
typedef struct tree BSTree;
typedef Node* Node_ptr;

struct node {
	int data;
	Node_ptr left;
	Node_ptr right;
};

struct tree {
	Node_ptr root;
	int count;	
};

BSTree createBSTree(void);
Node_ptr createTreeNode(int);
int insert(BSTree*, int);
Node_ptr find(BSTree, int);
typedef struct node Node;
typedef struct tree Tree;
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
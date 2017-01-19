class BST{
private:
	struct node{
		int key;
		node* left;
		node* right;
	};

	node* root;
	void addLeafPriv(int key, node* ptr);
	void printInOrderPriv(node* ptr);
	void printpreOrderPriv(node* ptr);
public:

	BST();
	node* createLeaf(int key);
	void addLeaf(int key);
	void printInOrder();
	void printpreOrder();







};

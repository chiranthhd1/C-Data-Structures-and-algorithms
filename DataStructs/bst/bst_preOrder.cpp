#include <iostream>
#include <cstdlib>

//#include "BST.h"

using namespace std;

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
	void printOrder(int value);
	//void printpreOrder();
};
	


BST::BST(){

	root = NULL;
}

BST::node* BST::createLeaf(int key){

	node* n = new node;
	n->key = key;
	n->left = NULL;
	n->right = NULL;

	return n;

}

void BST::addLeaf(int key){

	addLeafPriv(key, root);
}


void BST::addLeafPriv(int key, node* ptr){

	if(root == NULL){
		root = createLeaf(key);
	}
	else if( key < ptr->key){

		if(ptr->left != NULL)
		{
			addLeafPriv(key, ptr->left);
		}
		else{
			ptr->left = createLeaf(key);


		}
	}
	else if( key > ptr->key){

		if(ptr->right != NULL)
		{
			addLeafPriv(key, ptr->right);
		}
		else{
			ptr->right = createLeaf(key);
		}
	}
	else{
		cout << "Key" << key << " has already been added to the tree" << endl;
	}

}

void BST::printOrder(int value){
	if (value == 1){
		printInOrderPriv(root);
	}
	if (value == 2){
		printpreOrderPriv(root);
	}
}



void BST::printInOrderPriv(node* ptr){
	if ( root != NULL){
		if( ptr->left != NULL){
			printInOrderPriv(ptr->left);
		}
		cout << ptr->key << " ";
		if( ptr->right != NULL){
			printInOrderPriv(ptr->right);
		}
	}
	else{
		cout << " The tree is empty " << endl;
	}


}

/*void BST::printpreOrder(){
	printpreOrderPriv(root);

}
*/
void BST::printpreOrderPriv(node* ptr){
	if ( root != NULL){
		
		if( ptr->left != NULL){
			printpreOrderPriv(ptr->left);
		}

		if( ptr->right != NULL){
			printpreOrderPriv(ptr->right);
		}
		cout << ptr->key <<" ";

	}
}


int main(){

	int TreeKeys[16] = {58,76,21,4,32,64,15,52,14,100,83,2,3,78,87,80};
	//int TreeKeys[9] = {1,2,3,4,5,6,7,8,9};
	BST myTree;

	//cout << "Printing the tree in order before adding the members" << endl;
	//myTree.printInOrder();

	for(int i =0; i < 9 ;i++ )
	{
		myTree.addLeaf(TreeKeys[i]);
	}
	cout << " Please select which order you would like to print" <<
			" 1. In order " <<
			" 2. Pre Order" << endl;
	int input;
	cin >> input;
	if(input == 1){
	cout << "Printing the tree in order after adding the members" << endl;
	myTree.printOrder(input);
	}
	if(input == 2){
	cout << "Printing the tree pre order after adding the members" << endl;
	myTree.printOrder(input);
	}
	cout << endl;



}

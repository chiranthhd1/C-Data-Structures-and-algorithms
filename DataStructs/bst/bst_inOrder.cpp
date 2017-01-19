#include <iostream>
#include <cstdlib>

#include "BST.h"

using namespace std;
	


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

void BST::printInOrder(){
	printInOrderPriv(root);

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


int main(){

	int TreeKeys[16] = {58,76,21,4,32,64,15,52,14,100,83,2,3,78,87,80};
	BST myTree;

	cout << "Printing the tree in order before adding the members" << endl;
	myTree.printInOrder();

	for(int i =0; i < 16 ;i++ )
	{
		myTree.addLeaf(TreeKeys[i]);
	}
	cout << "Printing the tree in order after adding the members" << endl;
	myTree.printInOrder();

	cout << endl;



}

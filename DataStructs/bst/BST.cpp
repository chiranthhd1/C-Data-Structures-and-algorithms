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

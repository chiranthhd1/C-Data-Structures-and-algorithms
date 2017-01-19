#include <iostream>
#include <cstdlib>

#include "BST.cpp"

using namespace std;

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
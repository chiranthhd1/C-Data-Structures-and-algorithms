#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>

#define ALPHABETS 26
#define MAX_WORD_SIZE 20
 
using namespace std;
 
class Node
{
    public:
        Node * parent;
        Node * children[ALPHABETS];
        vector<int> occurrences;
};
 
class Trie
{
    public:     
        Node * root;
         
        Trie() {
            //root = (Node *) calloc(1, sizeof(Node));
			root = new Node;
        }
         
        // Inserts a word 'text' into the Trie Tree
        // 'trie_tree' and marks it's occurence as 'index'.
        void insert(string text, int index)
        {
            // Converting the input word 'text'
            // into a vector for easy processing
            //vector<string> word(text);
            Node * temp = root;
            string word;
            word = text;
            int i = 0;
             
            while (i < word.size()) {      // Until there is something to process
                if (temp->children[word[i] - 'a'] == NULL) {
                    // There is no node in 'trie_tree' corresponding to this alphabet
          
                    // Allocate using calloc(), so that components are initialised
                    //temp->children[word[i] - 'a'] = (Node *) calloc(1, sizeof(Node));
					temp->children[word[i] - 'a'] = new Node;	
                    temp->children[word[i] - 'a']->parent = temp; // Assigning parent
                }
          
                temp = temp->children[word[i] - 'a'];
                ++i;   // Next alphabet
            }
          
            temp->occurrences.push_back(index);      //Mark the occurence of the word
        }
         
        // Prints the 'trie_tree' in a Pre-Order or a DFS manner
        // which automatically results in a Lexicographical Order
      /*  void lexicographPrint(Node * trie_tree, vector<string> printUtilVector)
        {
            int i;
            bool noChild = true;
                         
            vector<int>::iterator itr = trie_tree->occurrences.begin();
          
            for (i = 0; i < ALPHABETS; ++i) {
                if (trie_tree->children[i] == NULL) {
                    continue;
                } else {
                    noChild = false;
                    printUtilVector.push_back('a' + i);    // Select a child
          
                    // and explore everything associated with the cild
                    lexicographPrint(trie_tree->children[i], printUtilVector);
                    printUtilVector.pop_back();
                    // Remove the alphabet as we dealt
                    // everything associated with it
                }
            }
          
            if (trie_tree->occurrences.size() != 0) {
                // Condition trie_tree->occurrences.size() != 0,
                // is a neccessary and sufficient condition to
                // tell if a node is associated with a word or not
          
                vector<string>::iterator itr = printUtilVector.begin();
          
                while (itr != printUtilVector.end()) {
                    printf("%c", *itr);
                    ++itr;
                }
                printf(" -> @ index -> ");
          
                vector<int>::iterator counter = trie_tree->occurrences.begin();
                // This is to print the occurences of the word
          
                while (counter != trie_tree->occurrences.end()) {
                    printf("%d, ", *counter);
                    ++counter;
                }
          
                printf("\n");
            }
          
            printUtilVector.pop_back();
        }
        */ 
        // Searches for the occurence of a word in 'trie_tree',
        // if not found, returns NULL,
        // if found, returns poniter pointing to the
        // last node of the word in the 'trie_tree'
        Node * searchWord(Node * trie_tree, char * text)
        {
            // Functions very similar to insert() function
            vector<string> word(text, text + strlen(text));
            Node * temp = trie_tree;
          
            while (word.size() != 0) {
                if (temp->children[word[0] - 'a'] != NULL) {
                    temp = temp->children[word[0] - 'a'];
                    word.erase(word.begin());
                } else {
                    break;
                }
            }
          
            if (word.size() == 0 && temp->occurrences.size() != 0) {
                // Word found
                return temp;
            } else {
                // Word not found
                return NULL;
            }
        }
         
        // Searches the word first, if not found, does nothing
        // if found, deletes the nodes corresponding to the word
        void removeWord(Node * trie_tree, string word)
        {
            Node * temp = searchWord(trie_tree, word);
          
            if (temp == NULL) {
                // Word not found
                return;
            }
          
            temp->occurrences.pop_back();    // Deleting the occurence
          
            // 'noChild' indicates if the node is a leaf node
            bool noChild = true;
          
            int childCount = 0;
            // 'childCount' has the number of children the current node
            // has which actually tells us if the node is associated with
            // another word .This will happen if 'childCount' >= 2.
            int i;
          
            // Checking children of current node
            for (i = 0; i < ALPHABETS; ++i) {
                if (temp->children[i] != NULL) {
                    noChild = false;
                    ++childCount;
                }
            }
          
            if (!noChild) {
                // The node has children, which means that the word whose
                // occurrence was just removed is a Suffix-Word
                // So, logically no more nodes have to be deleted
                return;
            }
          
            Node * traverse;     // variable to assist in traversal
          
            while (temp->occurrences.size() == 0 && temp->parent != NULL && childCount < 2) {
                // temp->occurrences.size() -> tells if the node is associated with another
            // word
                //
                // temp->parent != NULL -> is the base case sort-of condition, we simply ran
                // out of nodes to be deleted, as we reached the root
                //
                // childCount -> does the same thing as explained in the beginning, to every
                // node we reach
          
                traverse = temp->parent;
          
                for (i = 0; i < ALPHABETS; ++i) {
                    if (temp == traverse->children[i]) {
                        traverse->children[i] = NULL;
                        break;
                    }
                }
          
                free(temp);
                temp = traverse;
          
                for (i = 0; i < ALPHABETS; ++i) {
                    if (temp->children[i] != NULL) {
                        ++childCount;
                    }
                }
            }
        }
};
 
int main(){
	/*
	Trie trie;
	fstream myFile("dict.txt", ios_base::in);
	if(myFile.is_open()){
		
		int i =0;
		while (getline(myFile,in,'\n'){
			trie.insert(words[i], i + 1);
			++i;
		}
			
		
		
		
		
	}
	
	
	*/
    int n, i, j;
  
    printf("Enter the number of words-\n");
    scanf("%d", &n);
  
    //char words[n][MAX_WORD_SIZE];
	string word;
	/*
    for (i = 0; i < n; ++i) {
        scanf("%s", words[i]);
    }
	*/
    // Creating the Trie Tree using calloc so that the components
    // are initialised
    // Always initialize
    //struct node * trie_tree = (struct node *) calloc(1, sizeof(struct node));
  
    Trie trie;
     
    for (i = 0; i < n; ++i) {
        trie.insert(words, i + 1);
    }
	Node* p;
    vector<string> util;
    printf("\n");   // Just to make the output more readable
    trie.lexicographPrint(trie.root, util);
    //trie.removeWord(trie.root, wo);
	//char c[] = 'chiranth'
	p = trie.searchWord(trie.root,"chi") ;
	cout << " serached parent : " << p->parent << endl;
    cout << " serached child : " << p->children << endl;
	printf("\n");   // Just to make the output more readable
    trie.lexicographPrint(trie.root, util);
  
    return 0;
	//*/
}
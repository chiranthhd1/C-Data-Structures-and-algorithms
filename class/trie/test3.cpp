#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>

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
        void insert(char text[], int index)
        {
            // Converting the input word 'text'
            // into a vector for easy processing
            vector<char> word(text, text + strlen(text));
            Node * temp = root;
             
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
       
        bool searchWord(Node * trie_tree, char * text)
        {
            // Functions very similar to insert() function
            vector<char> word(text, text + strlen(text));
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
                return true;
            } else {
                // Word not found
                return false;
            }
        }
         
       
};
 
int main(){
	///*
	Trie trie;
	char words[975][MAX_WORD_SIZE];
	//char words[213557][MAX_WORD_SIZE];
	string in;
	fstream inFile("dict2.txt", ios_base::in);
	if(inFile.is_open()){
		
		int i =0;
		cout << "FM" << endl;
		//while (getline(myFile,in,'\n'){
		while ( inFile >> words[i]){

			trie.insert(words[i], i + 1);
			//cout << words[i] << endl;
			++i;
		}
			
		
		
	}

	char words1[10][MAX_WORD_SIZE];
	fstream chckFile("hw6a.dat", ios_base::in);
	if(chckFile.is_open()){
		
		int i =0;
		cout << "FM" << endl;
		//while (getline(myFile,in,'\n'){
		while ( chckFile >> words1[i]){
			bool ch;
		//	ch = trie.searchWord(trie.root,words1[i]) ;
		//	if ( ch == 1){
			cout << words1[i] << endl;
			if(trie.searchWord(trie.root,words1[i])){
				cout << " True" << endl;
			}
			else{
				cout << "False" << endl;
			}
			
			++i;
		}
			
		
		
	}
	
	
	//*/
	/*
    int n, i, j;
  
    printf("Enter the number of words-\n");
    scanf("%d", &n);
  
    char words[n][MAX_WORD_SIZE];
  
    for (i = 0; i < n; ++i) {
        scanf("%s", words[i]);
    }
  
    // Creating the Trie Tree using calloc so that the components
    // are initialised
    // Always initialize
    //struct node * trie_tree = (struct node *) calloc(1, sizeof(struct node));
  
    Trie trie;
     
    for (i = 0; i < n; ++i) {
        trie.insert(words[i], i + 1);
    }
	Node* p;
    vector<char> util;
    printf("\n");   // Just to make the output more readable
    //trie.lexicographPrint(trie.root, util);
    //trie.removeWord(trie.root, words[0]);
	//char c[] = 'chiranth'
	//p = trie.searchWord(trie.root,words[1]) ;
	//cout << " serached parent : " << p->parent << endl;
    //cout << " serached child : " << p->children << endl;
   */// cout << " searched child : " << words[2] << " is " << trie.searchWord(trie.root,words[2]) ;
	//cout << " searched child : " << words[200] << " is " << trie.searchWord(trie.root,words[200]) ;
//	cout << " searched child : " << trie.searchWord(trie.root,);
    printf("\n");   // Just to make the output more readable
    //trie.lexicographPrint(trie.root, util);
  
    return 0;
	//*/
}

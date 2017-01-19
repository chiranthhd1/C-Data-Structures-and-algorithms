#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <fstream>


#define ALPHABETS 26
#define MAX_WORD_SIZE 20
 
using namespace std;
 
 
class Trie
{
private:
	class Node
	{
    public:
        Node * parent;
        Node * children[ALPHABETS];
        vector<int> occurrences;
	};
public:     
        Node * root;
         
        Trie() {
			root = new Node;
        }

        void add(char text[],int index)
        {
            vector<char> word(text, text + strlen(text));
            Node * temp = root;
             
            int i = 0;
             
            while (i < word.size()) {
                if (temp->children[word[i] - 'a'] == NULL) {
					temp->children[word[i] - 'a'] = new Node;	
                    temp->children[word[i] - 'a']->parent = temp; 
                }
          
                temp = temp->children[word[i] - 'a'];
                ++i;
                
            }
            temp->occurrences.push_back(index); 
          
        }
       
        bool isWord( char * text)
        {
            vector<char> word(text, text + strlen(text));
            Node * temp = root;
          
            while (word.size() != 0) {
                if (temp->children[word[0] - 'a'] != NULL) {
                    temp = temp->children[word[0] - 'a'];
                    word.erase(word.begin());
                } else {
                    break;
                }
            }
          
            if (word.size() == 0 && temp->occurrences.size() != 0) {
              
                return true;
            } else {
                
                return false;
            }
        }
		
        bool startsWith(char * text)
        {
            vector<char> word(text, text + strlen(text));
            int tempSize = word.size();
            Node * temp = root;
            bool flga = false;
          	int i =0;
            while (word.size() != 0) {
                if (temp->children[word[0] - 'a'] != NULL) {
                    temp = temp->children[word[0] - 'a'];
                    word.erase(word.begin());
                    i++;
                } else {
                    break;
                }
            }
            if (i == tempSize){
            	return true;
            }
            else{
            	return false;
            }
        }
         
       
};
 
int main(){
	///*
	Trie trie;

    char words[213560][MAX_WORD_SIZE];   
    string in;
	fstream inFile("dict.txt", ios_base::in);
	if(inFile.is_open()){
		
		int i =0;
		while ( inFile >> words[i]){

			trie.add(words[i], i + 1);
			++i;
		}
	}
	else{
		cout << "please check the file name. code works with only dict.txt file" << endl; 
	}

	char words1[10][MAX_WORD_SIZE];
	fstream chckFile("hw6a.dat", ios_base::in);
	if(chckFile.is_open()){
		int i =0;
		while ( chckFile >> words1[i]){
			cout << words1[i] << " " ;
			if(trie.startsWith(words1[i])){
				cout << "\t\tYes" << endl;
			}
			else{
				cout << "\t\tNo" << endl;
			}
// Works when both isword and startswith functions are needed/.
			/*if(trie.isWord(words1[i])){
				cout << "\t\tYes" << endl;
			}
			else{
				if(trie.startsWith(words1[i])){
					cout << "\t\t Starts With: Yes" << endl;
				}
				else{
					cout << "\t\tNo" << endl;
				}
			}
			*/
			
			++i;
		}	
	}
	else{
		cout << "please check the file name. code works with only hw6a.dat file" << endl; 
	}
    return 0;
}


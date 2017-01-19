#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
#include <cstring>



#define ALPHABETS 26
#define MAX_WORD_SIZE 20
#define M 4
#define N 4

int totalWords = 0; 
 
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
                    ++i;
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


bool isWordB(string &str, Trie &trie)
{
    char *cstr = &str[0u];
        if (trie.isWord(cstr))
          return true;
    return false;
}
 
void findWordsUtil(char boggle[M][N], bool checked[M][N], int i,
                   int j, string &str, Trie &trie)
{
    
    checked[i][j] = true;
    str = str + boggle[i][j];   
    if (isWordB(str, trie)){
      if (str.length()>2){
          cout << str << endl;
          totalWords++;
        }
    }
    for (int row=i-1; row<=i+1 && row<M; row++){
      for (int col=j-1; col<=j+1 && col<N; col++){
        if (row>=0 && col>=0 && !checked[row][col])
          findWordsUtil(boggle,checked, row, col, str,trie);
      }
    }
    
    str.erase(str.length()-1);
    checked[i][j] = false;
}
 
void findWords(char boggle[M][N], Trie &trie)
{
    bool checked[M][N] = {{false}};
    string str = "";
 
    for (int i=0; i<M; ++i){
      for (int j=0; j<N; ++j){
        findWordsUtil(boggle, checked, i, j, str, trie);
      }
    }
}
  
int main(){
  Trie trie;

    char words[340000][MAX_WORD_SIZE];   
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

  fstream inBoggle("boggle.dat", ios_base::in);
  char a;
  if (inBoggle.is_open()){
    inBoggle >> a;
    int k = (int )a - 48;
    char boggle[M][N];
    for (int j = 0 ; j < k ; ++j){
      for ( int f =0 ; f < k; ++f){
          inBoggle >> a;
          a = tolower(a);
          boggle[j][f] = a;
      }
    }
    cout << "The Words are : " << endl;
    findWords(boggle, trie);
    cout << endl;
    cout << " Total Number of words generated are :" << totalWords << endl;
  }
  else{
    cout << "please check the file name. code works with only boogle.dat file" << endl; 
  }
  return 0;
}

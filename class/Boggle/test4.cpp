#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/*
#define BIN_SEARCH(dict, size, needle, res, prefix)                     \
    do {                                                                \
        assert((dict) != NULL);                                         \
        assert((size) > 0);                                             \
        int l = 0, r = (size)-1;                                        \
        (res) = -1;                                                     \
        while (l <= r) {                                                \
            int rc;                                                     \
            int m = l + ((r - l) / 2);                                  \
            if (prefix)                                                 \
                rc = strncmp((dict)[m], (needle), strlen((needle)));    \
            else                                                        \
                rc = strcmp((dict)[m], (needle));                       \
            if (rc == 0) {                                              \
                (res) = m;                                              \
                break;                                                  \
            }                                                           \
            if (rc > 0)                                                 \
                r = m-1;                                                \
            else                                                        \
                l = m+1;                                                \
        }                                                               \
    } while (0)
*/
 
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

static void boggle(char **dict, int nwords, char board[4][4], char word[],
                   int k, int row, int col)
{
    if (row >= 0 && row < 4 && col >= 0 && col < 4 && board[row][col] != '\0') {
        int idx, i;
        word[k++] = board[row][col];
        word[k] = '\0';

        if (k >= 3) {
            BIN_SEARCH(dict, nwords, word, idx, 0);
            if (idx != -1)
                printf("%s\n", word);
        }

        BIN_SEARCH(dict, nwords, word, idx, 1); /* search prefix */
        if (idx != -1) {
            char c = board[row][col];
            board[row][col] = '\0';
            boggle(dict, nwords, board, word, k, row-1, col-1);
            boggle(dict, nwords, board, word, k, row-1, col);
            boggle(dict, nwords, board, word, k, row-1, col+1);
            boggle(dict, nwords, board, word, k, row, col-1);
            boggle(dict, nwords, board, word, k, row, col+1);
            boggle(dict, nwords, board, word, k, row+1, col-1);
            boggle(dict, nwords, board, word, k, row+1, col);
            boggle(dict, nwords, board, word, k, row+1, col+1);
            board[row][col] = c;
        }
    }
}

int main(int argc, char **argv)
{
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
    int nwords, i, j;
    char word[17];
    char board[4][4] = {
        {'A', 'E', 'M', 'P'},
        {'R', 'S', 'O', 'T'},
        {'F', 'A', 'L', 'D'},
        {'E', 'S', 'T', 'O'}
    };

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            boggle(trie, nwords, board, word, 0, i, j);
        }
    }

    for (i = 0; i < nwords; i++)
        free(dict[i]);
    free(dict);
    return 0;
}

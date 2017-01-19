Skip to content
 
 
Search…
All gists
GitHub
New gist @chiranthhd1
  Star 1
  Fork 0
  @davidreynoldsdavidreynolds/boggle.c
Created 5 years ago
Embed  
<script src="https://gist.github.com/davidreynolds/2865498.js"></script>
  Download ZIP
 Code  Revisions 4  Stars 1
Boggle Backtracking Algorithm
Raw
 boggle.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

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

static char **load_dictionary(int *n)
{
    int dsize = (1<<20), nwords = 0;
    char **dict = malloc(sizeof(char *) * dsize);
    char word[64];
    FILE *fp = fopen("/usr/share/dict/words", "r");
    while (fgets(word, sizeof word, fp)) {
        /* ignore capitalized words */
        if (word[0] >= 65 && word[0] <= 90)
            continue;
        if (nwords >= dsize) {
            dict = realloc(dict, dsize*2 * sizeof(char *));
            dsize *= 2;
        }
        word[strlen(word)-1] = '\0'; /* strip newline */
        dict[nwords] = malloc(strlen(word)+1);
        strncpy(dict[nwords], word, strlen(word));
        nwords++;
    }
    *n = nwords;
    return dict;
}

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
    int nwords, i, j;
    char **dict;
    char word[17];
    char board[4][4] = {
        {'a', 'b', 'c', 'd'},
        {'e', 'f', 'g', 'h'},
        {'i', 'j', 'k', 'l'},
        {'m', 'n', 'o', 'p'}
    };

    dict = load_dictionary(&nwords);

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            boggle(dict, nwords, board, word, 0, i, j);
        }
    }

    for (i = 0; i < nwords; i++)
        free(dict[i]);
    free(dict);
    return 0;
}
 @chiranthhd1
  
         
Write  Preview

Leave a comment
Attach files by dragging & dropping,  Choose Files selecting them, or pasting from the clipboard.
 Styling with Markdown is supported
Comment
Contact GitHub API Training Shop Blog About
© 2016 GitHub, Inc. Terms Privacy Security Status Help


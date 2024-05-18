#ifndef __TRIE__
#define __TRIE__
#define ALPHABET_SIZE 26
#define START_ALPHABET_SYMBOL 'A'

typedef enum bool{ false, true } bool;

typedef struct Node {
  bool isKey;
  int frequency;
  struct Node* child[ALPHABET_SIZE];
} Trie;

/**
 * Time Complexity O(L)
 */
Trie* insert(Trie* root, const char* word);

/**
 * Time Complexity O(L)
 */
bool search(Trie* root, const char* word);

/**
 * Time Complexity O(L)
 */
Trie* remove_word(Trie* root, const char* word, int depth);

/**
 * Time Complexity O(N)
 */
void print_trie(Trie* root);

/**
 * Time Complexity O(L)
 */
void longest_prefix(Trie* root, char* lcp);  // longest common prefix

/**
 * Time Complexity O(N)
 */
int max_occurrence(Trie* root, char* word);

#endif
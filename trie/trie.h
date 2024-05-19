#ifndef __TRIE__
#define __TRIE__
#define ALPHABET_SIZE 26
#define START_ALPHABET_SYMBOL 'a'
#define PREFIX_MAX_LENGHT 100

typedef enum bool { false, true } bool;

typedef struct Node {
  bool isKey;
  int frequency;
  struct Node* children[ALPHABET_SIZE];
} Trie;

/**
 * Time Complexity O(1)
 */
Trie* create_node();

/**
 * Time Complexity O(L)
 */
void insert_word(Trie* root, const char* word);

/**
 * Time Complexity O(L)
 */
bool find_word(Trie* root, const char* word);

/**
 * Time Complexity O(L)
 */
int remove_word(Trie* root, const char* word);

/**
 * Time Complexity O(N)
 */
void print_words(Trie* root);

/**
 * Time Complexity O(L)
 */
void longest_prefix(Trie* root, char* lcp);  // longest common prefix

/**
 * Time Complexity O(N)
 */
int max_occurrence(Trie* root, char* word);

#endif
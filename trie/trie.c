#include "./trie.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int char2index(char c) { return tolower(c) - START_ALPHABET_SYMBOL; }

static char index2char(int index) { return index + START_ALPHABET_SYMBOL; }

Trie* create_node() {
  Trie* root = (Trie*)malloc(sizeof(Trie));
  root->frequency = 0;
  root->isKey = false;
  for (int i = 0; i < ALPHABET_SIZE; i++) root->children[i] = NULL;

  return root;
}

void insert_word(Trie* root, const char* word) {
  Trie* aux = root;

  while (*word) {
    int i = char2index(*word);
    if (!aux->children[i]) {
      aux->children[i] = create_node();
    }
    aux = aux->children[i];
    word++;
  }

  aux->frequency++;  // CULPA DO LUKENYYYYY
  aux->isKey = true;
}

bool find_word(Trie* root, const char* word) {
  Trie* aux = root;

  while (*word) {
    int i = char2index(*word);
    if (!aux->children[i]) return 0;

    aux = aux->children[i];
    word++;
  }

  return aux->isKey;
}

static int is_leaf(Trie* root) {
  for (int i = 0; i < 26; i++) {
    if (root->children[i]) {
      return 0;
    }
  }
  return 1;
}

int remove_word(Trie* root, const char* word) {
  if (root == NULL) return 0;
  int i = 0;
  if (*word) {
    i = char2index(*word);
    if (root->children[i]) {
      int leaf = remove_word(root->children[i], word + 1);
      if (leaf) {
        leaf = !root->isKey && is_leaf(root);
        free(root->children[i]);
        root->children[i] = NULL;
        return leaf;
      }
      root->frequency--;
    }
  } else {
    root->isKey = false;
    return is_leaf(root);
  }
  return 0;
}

static int print_alphabetically(Trie* root, char* prefix, int length) {
  if (!root) return 0;

  int count = 0;

  if (root->isKey) {
    prefix[length] = '\0';
    printf("[%d] ", root->frequency);
    puts(prefix);
    count++;
  }

  for (int i = 0; i < ALPHABET_SIZE; ++i) {
    if (!root->children[i]) continue;

    prefix[length] = index2char(i);
    count += print_alphabetically(root->children[i], prefix, length + 1);
  }

  return count;
}

void print_words(Trie* root) {
  if (!root) {
    puts("There's nothing to print!");
    return;
  }

  char prefix[PREFIX_MAX_LENGHT];

  int c = print_alphabetically(root, prefix, 0);
  if (c == 0)
    puts("Nothing to print");
  else
    printf("\nTotal %d\n", c);
}

void longest_prefix(Trie* root, char* lcp) {
  int length = 0;
  Trie* current = root;
  while (current && !current->isKey) {
    int children = 0;
    int next_index = -1;

    for (int i = 0; i < ALPHABET_SIZE; ++i) {
      if (current->children[i]) {
        children++;
        next_index = i;
      }
    }

    if (children != 1) break;

    lcp[length++] = index2char(next_index);
    current = current->children[next_index];
  }
  lcp[length] = '\0';
}

static int max_occurrence_of_word(Trie* root, char* prefix, int* max_freq, char* result, int length) {
  if (!root) return 0;

  if (root->isKey && (root->frequency > *max_freq)) {
    *max_freq = root->frequency;
    strncpy(result, prefix, length);
    result[length] = '\0';
  }

  for (int i = 0; i < ALPHABET_SIZE; i++) {
    if (!root->children[i]) continue;

    prefix[length] = index2char(i);
    max_occurrence_of_word(root->children[i], prefix, max_freq, result, length + 1);
  }

  return *max_freq;
}

int max_occurrence(Trie* root, char* word) {
  int freq = 0;
  char prefix[PREFIX_MAX_LENGHT] = {0};

  max_occurrence_of_word(root, prefix, &freq, word, 0);
  return freq;
}
#include "./trie.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_alphabetically(Trie* root, char* prefix, int length) {
  if (!root) return;

  if (root->isKey) {
    prefix[length] = '\0';
    puts(prefix);
  }

  for (int i = 0; i < ALPHABET_SIZE; ++i) {
    if (!root->child[i]) continue;

    prefix[length] = i + START_ALPHABET_SYMBOL;
    print_alphabetically(root->child[i], prefix, length + 1);
  }
}

void print_trie(Trie* root) {
  if (!root) {
    puts("There's nothing to print!");
    return;
  }

  char prefix[100];

  print_alphabetically(root, prefix, 0);
}

void longest_prefix(Trie* root, char* lcp) {
  int length = 0;
  Trie* current = root;
  while (current && !current->isKey) {
    int children = 0;
    int next_index = -1;

    for (int i = 0; i < ALPHABET_SIZE; i++) {
      if (current->child[i]) {
        children++;
        next_index = i;
      }
    }

    if (children != 1) break;

    lcp[length++] = START_ALPHABET_SYMBOL + next_index;
    current = current->child[next_index];
  }
  lcp[length] = '\0';
}


void max_occurrence_of_prefix(Trie* root, char* word, int* max_freq, char* result, int length) {
  if (!root) return;

  if (root->isKey && root->frequency > *max_freq) {
    *max_freq = root->frequency;
    strncpy(result, word, length);
    result[length] = '\0';
  }

  for (int i = 0; i < ALPHABET_SIZE; i++) {
    if (root->child[i]) {
      word[length] = START_ALPHABET_SYMBOL + i;
      max_occurrence_of_prefix(root->child[i], word, max_freq, result, length + 1);
    }
  }
}

int max_occurrence(Trie* root, char* word) {
  if (!root) return -1;

  int freq = 0;
  char prefix[100];
  max_occurrence_of_prefix(root, prefix, &freq, word, 0);

  return freq;
}
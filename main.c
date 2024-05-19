#include <stdio.h>
#include <stdlib.h>

#include "trie/trie.h"
#include "utils/utils.h"

int print_options() {
  puts("======= R-WAY TRIE ========");
  const char* options[] = {"Insert", "Remove", "Search", "Print", "Longest Common Prefix", "Max Occurrence"};

  return show_options(options, sizeof(options) / sizeof(options[0]));
}

int main() {
  Trie* root = create_node();

start: {
  int option = menu(print_options);

  switch (option) {
    case 1: {
      puts("========= INSERT ===========");
      char word[PREFIX_MAX_LENGHT];
      printf("Insert the word: ");
      fflush(stdin);
      scanf("%99[^ \n]", word);
      insert_word(root, word);

      pause("");
    } break;
    case 2: {
      puts("========= REMOVE ===========");
      char word[PREFIX_MAX_LENGHT];
      printf("Insert the word: ");
      fflush(stdin);
      scanf("%99[^ \n]", word);
      remove_word(root, word);
      pause("");
    } break;
    case 3: {
      puts("========= SEARCH ===========");
      char word[PREFIX_MAX_LENGHT];
      printf("Insert the word: ");
      fflush(stdin);
      scanf("%99[^ \n]", word);
      printf("Word %s: %s\n", word, find_word(root, word) ? "Found" : "Not Found");
      pause("");
    } break;
    case 4: {
      puts("========= PRINT ===========");
      print_words(root);
      pause("");
    } break;
    case 5: {
      puts("========= LONGEST COMMON PREFIX ===========");
      char lcp[PREFIX_MAX_LENGHT];
      longest_prefix(root, lcp);
      if (lcp[0])
        printf("Longest common prefix is %s\n", lcp);
      else
        puts("Nothing to show!");
      pause("");
    } break;
    case 6: {
      puts("========= MAX OCURRANCE ===========");

      char word[PREFIX_MAX_LENGHT];
      int freq = max_occurrence(root, word);
      if (freq > 0)
        printf("The maximum occurring word is %s \n Its count is %d\n", word, freq);
      else
        puts("Nothing to show!");
      pause("");
    } break;
    default:
      puts("Obrigado ;)\nBy: Grupo 2");
      puts("Matateu André - 20212549🤓");
      puts("Lukeny Silva - 20220718😎");
      puts("Kélsio Mateus -  20221473🧑‍💻");
      pause("");
      goto end;
  }
  goto start;
}
end:
  return 0;
}
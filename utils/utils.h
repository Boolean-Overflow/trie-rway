#ifndef __TRIE_R_WAY_UTILS
#define __TRIE_R_WAY_UTILS

int menu(int(*show_options)());
int show_options(const char** options, int options_count);
void validate_option(int* option, int min, int max, char* error_message);

#endif
#ifndef _TREE_H_
#define _TREE_H_
#define allKids ((int)26)
typedef enum {NO=0, YES=1} boolean;

typedef struct node{
 char letter;
 long int count;
 boolean word, kid;
 struct node *children[allKids];
}node;

typedef struct trie {
 node *children[allKids], *current;
 boolean empty;
 int maxLength;
 char *word;
}trie;

node* createN(char letter);
void free_node(node *n);
trie* createT(void);
int read_character(trie *root, int c);
trie* read_text();
void print_words_reverse(trie *root);
void print_trie_reverse(trie *root);
void print_words(trie *root);
void print_trie(trie *root);
void free_trie(trie *t);
boolean Reverse(int argc, char *argv[]);
#endif
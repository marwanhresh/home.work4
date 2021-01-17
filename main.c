#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main(int argc, char* argv[]){

trie* root;
boolean reverse=NO;
reverse = Reverse(argc,argv);
root = read_text();
if(reverse) print_trie_reverse(root);
else
print_trie(root);
free_trie(root);
return 0;
}
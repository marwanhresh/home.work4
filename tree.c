#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "tree.h"


trie* createT(){
trie *creatrie=(trie*)malloc(sizeof(trie));
if(!creatrie){
 printf("Allocation didn't succeed\n");
 exit(1);
}
for(int i=0; i<allKids; ++i){
creatrie->children[i]=NULL;
}
creatrie->current=NULL;
creatrie->empty=YES;
creatrie->maxLength=0;
return creatrie;
}


node *createN(char letter){
node *creatNode=((node*)malloc(sizeof(node)));
if(!creatNode){
  printf("Allocation didn't succeed\n");
  exit(1);
}
 creatNode->letter = letter;
 creatNode->count = 0;
 creatNode->word = NO;
 creatNode->kid = NO;
 for (int i=0; i<allKids; ++i){
 (creatNode->children)[i] = NULL;
 }
 return creatNode;
}


void free_node(node *n){
if(n==NULL) return;
if (0==(n->kid)) free(n);
else{
for (int i=0; i<allKids; ++i){
free_node((n->children)[i]);
}
}
return;
}


int read_character(trie *root, int c){
int index, wordLength=0;
if(!isalpha(c)){
if(root->current == NULL) return 0;
root->current->count++;
root->current->word = YES;
root->current=NULL;
return wordLength;
}
 wordLength++;
 c=tolower(c);
 index= c-'a';
 if(root->current==NULL){
 if(root->children[index] == NULL) root->children[index] = createN(c);
 root->current = root->children[index];
 root->empty=NO;
 }
 else{
 root->current->kid = YES;
 if(root->current->children[index] == NULL)
 root->current->children[index] = createN(c);
 root->current=root->current->children[index];
 }
 return wordLength;
}


void print_words_reverse(trie* root){
static int p=0;
node* current;
root->word[p++]=root->current->letter;
if(root->current->kid){
for(int i=allKids-1; i>=0; --i){
if(root->current->children[i] == NULL) continue;
current = root->current;
root->current = root->current->children[i];
print_words_reverse(root);
root->current = current;
 }
 } 
else{
 if(root->current->word){
 root->word[p]='\0';
 printf("%s %ld\n",root->word,root->current->count);
 }
 --p;
 return;
 }
 if(root->current->word){
 root->word[p]='\0';
 printf("%s %ld\n",root->word,root->current->count);
 }
 --p;
}


void print_words(trie* root){
static int p=0;
node* current;
root->word[p++]=root->current->letter;
if (root->current->word){
root->word[p]='\0';
printf("%s %ld\n",root->word,root->current->count);
}
 if (root->current->kid){
 for(int i=0; i<allKids; ++i){
 if (root->current->children[i] == NULL) continue;
current = root->current;
 root->current = root->current->children[i];
 print_words(root);
 root->current = current;
 }
 } 
 else{
 --p;
 return;
 }
 --p;
}


boolean Reverse(int argc, char* argv[]){
if(argc > 2){
 printf("USAGE:\n\t%s: Wrong number of arguments.\n\n",argv[0]);
 exit(1);
}
if((argc == 2) && (argv[1][0]=='r' || argv[1][0]=='R')) return YES;
if (argc == 1) return NO;
printf("USAGE:\n\t%s: Bad command line arguments.\n\n",argv[0]);
exit(1);
return NO;
}


trie* read_text(){
int c, word_length;
trie* root = createT();
while((c=getchar())!=EOF){
word_length=read_character(root,c);
if(word_length>root->maxLength) root->maxLength=word_length;
}
if(!(root->word=(char*)malloc(sizeof(char)*(root->maxLength)))){
    printf("Allocation didn't succeed!\n");
    exit(1);
}
free(root->word);
return root;
}


void print_trie_reverse(trie* root){
if(root == NULL) return;
if(root->empty) return;
for(int i=allKids-1; i>=0; --i){
if(root->children[i] == NULL) continue;
root->current = root->children[i];
print_words_reverse(root);
}
}

void print_trie(trie* root){
 if(root == NULL) return;
 if(root->empty) return;
 for(int i=0; i<allKids; ++i){
 if(root->children[i] == NULL) continue;
 root->current = root->children[i];
 print_words(root);
 }
}


void free_trie(trie* t){
if(t == NULL) return;
for(int i=0;i<allKids; ++i){
free_node(t->children[i]);
}
free(t);
}
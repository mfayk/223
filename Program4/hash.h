#ifndef HASH_H_
#define HASH_H_



#include <fcntl.h>
#include <stdio.h>
#include <strings.h>
#include "list.h"

#define WSZ 256
#define HSZ 8191

struct hash_table{
	list *table;
	int size;
};

struct book_word
{
	char word[WSZ];
	int count[2];
};

//find the index for the hash table
int ha(char *p, int m);

//add a word to the hash table
int hash_insert(struct hash_table *h, char *key, int bookNum);

//search through the hash table for duplicits
struct book_word *hash_search(struct hash_table *h, char *key);

//initalize the hash table
struct hash_table *hash_init();

//free and remove all memory in the table
void hash_destroy(struct hash_table *h);

#endif
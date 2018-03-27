#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "hash.h"
#include "list.h"


//this function calculates the hash number
int ha(char *p, int m)
{
    int flip = 0;
    int len = 0;
    int s = 0;
    int shortcnt = 0;
    unsigned short *sp = NULL;

    len = strnlen(p, WSZ);
    shortcnt = len / 2;
    sp = (unsigned short *)p;
    unsigned short hval = 0x5ab6;

    /* folding the string by twos */
    for (s = 0; s < shortcnt; s++)
    {
        unsigned short newv;
        newv = *sp;
        if (flip)
        {
            newv <<= 1;
        }
        flip = !(flip);
        hval ^= newv;
        sp++;
    }
    /* if odd size string double up last char */
    if (len & 0x0001)
    {
        hval ^= ((((short)(p[len-1])) << 8) | (short)(p[len-1]));
    }
    return (int)hval % m;
}


//here i initalize the has_table
struct hash_table *hash_init(){
	int i =0;
	struct hash_table *h = calloc(1,sizeof(struct hash_table));
	if (h == NULL){
		return NULL;
	}
	h->table = calloc(HSZ,sizeof(list));
	if (h->table == NULL){
		return NULL;
	}
	//set aside memory for the array of list
	for(i = 0; i<HSZ; i++){
		h->table[i] = list_init();
		if(h->table[i] == NULL){
			return NULL;
		}
	}
	h->size = 0;
	return h;
}

int hash_insert(struct hash_table *h, char *key, int bookNum){
	//first i find the hash index
	int hash_index = ha(key, HSZ);
	//i look through the current hash table for duplicits
	struct book_word *dataCheck = hash_search(h,key);
	if(dataCheck == NULL){
		//if the word isnt found i allocate a new book node and insert
		struct book_word *Bdata = calloc(1,sizeof(struct book_word));
		if(Bdata == NULL){
			return -1;
		}
		strcpy(Bdata->word,key);
		Bdata->count[bookNum] = 1;
		dataCheck = list_insert(h->table[hash_index],Bdata);
	}
	else{
		//if it is a duplicit the count increments
		++(dataCheck->count[bookNum]);
		h->size++;		
	}

	return 0;

}

//i search through the hash table to check for duplicits
struct book_word *hash_search(struct hash_table *h, char *key){
	int hash_index = ha(key, HSZ);
	struct book_word *dataCheck = NULL;
	//search through the list
	dataCheck = list_first(h->table[hash_index]);
	while(dataCheck != NULL && strcmp(dataCheck->word,key)!=0){
		dataCheck = list_next(h->table[hash_index]);
	}	
	return dataCheck;
}

//free and finalize all calloced memory
void hash_destroy(struct hash_table *h){
	int i=0;
	struct book_word *wrd = NULL;
	for(i=0;i<HSZ;i++){
		wrd = list_first(h->table[i]);
		while(wrd != NULL){
			free(wrd);
			wrd = NULL;
			wrd = list_next(h->table[i]);
		}
		list_finalize(h->table[i]);	
	}	
	free(h->table);
	free(h);
	h = NULL;
}
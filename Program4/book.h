#ifndef BOOK_H_
#define BOOK_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "hash.h"

struct stats
{
	struct book_word *longest[5];
	struct book_word *most_used[15];
	struct book_word *least_used[5];
};

struct book_stats{
	struct stats book1;
	struct stats book2;
	struct stats both;
};


//here i calculate all of the longest/shortest/frequent
void calculate(struct hash_table *h, struct book_stats *stat);

//print out the values that i calculated
void printing(struct hash_table *h, struct book_stats *stat, int book);


#endif
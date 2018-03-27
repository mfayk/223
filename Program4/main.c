/*************************
*Max Faykus
*ECE 2230
*Programming Assignment 4
*mfaykus
**************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include "hash.h"
#include "list.h"
#include "book.h"



int main(int argc, char *argv[]){
//initalize values
	struct book_stats stat = {{NULL,NULL,NULL}};
	char word[WSZ];
	char new1;
	char new2;
	int linecnt1 = 0;
	int linecnt2 = 0;
	int cnt1 =0;
	int cnt2 =0;
	int i=0;
	struct book_word *wrd;
	struct hash_table *h = hash_init();
	int uniquecnt[3];

	int flags =0;
	char Bdrac[25] = "\0";
	char Bfrank[25] = "\0";

	//check the user read the README
	if(argc != 5){
		printf("please compile properly use the README\n");
		return 0;
	}

	//set up the arguments for the executable
	while((flags = getopt(argc,argv, "d:f:")) != -1){
		switch (flags){
			case 'd':
				strcpy(Bdrac, optarg);
				break;
			case 'f':
				strcpy(Bfrank, optarg);
				break;
			default:
				break;
		}
	}



// here i open the dracula file and get the words and newlines
	FILE *drac = fopen(Bdrac,"r");
	while(!feof(drac)){
		fscanf(drac, "%s", word);
		cnt1++;
		hash_insert(h,word,0);
	}
	rewind(drac);
	
	new1 = fgetc(drac);	
	while(new1 != EOF){

		if(new1=='\n'){
			linecnt1++;
		}
		new1 = fgetc(drac);
	}

//here i open the frankenstein file and get the words and the newlines
	FILE *frank = fopen(Bfrank,"r");
	while(!feof(frank)){
		fscanf(frank, "%s", word);
		cnt2++;
		hash_insert(h,word,1);
	}
	rewind(frank);
	
	new2 = fgetc(frank);
	while(new2 != EOF){
		if(new2=='\n'){
			linecnt2++;
		}
		new2 = fgetc(frank);
	}

//here i calculate the unique values
	uniquecnt[0]=0;
	uniquecnt[1]=0;
	uniquecnt[2]=0;
	for(i=0;i<HSZ;i++){
		wrd = list_first(h->table[i]);
		while(wrd != NULL){
			if(wrd->count[0]>0){
				uniquecnt[0]++;
			}
			if(wrd->count[1]>0){
				uniquecnt[1]++;
			}
			if(wrd->count[1]>0 && wrd->count[0]>0){
				uniquecnt[2]++;
			}
			wrd = list_next(h->table[i]);
		}
	}
	//this is my call to calculate the values
	calculate(h,&stat);
	
//here i print out the expected output
	printf("\nECE2230 Fall 2017 Text Hashing Project\n");
	printf("Max Faykus\n\n");

	printf("Dracula\n\n");
	printf("Number of lines processed\t\t%d\n",linecnt1);
	printf("Number of words processed\t\t%d\n",cnt1);
	printf("Number of Unique words\t\t\t%d\n\n",uniquecnt[0]);
	
	printing(h,&stat,1);

	printf("\nFrankenstine\n\n");
	printf("Number of lines processed\t\t%d\n",linecnt2);
	printf("Number of words processed\t\t%d\n",cnt2);
	printf("Number of Unique words\t\t\t%d\n\n",uniquecnt[1]);
	printing(h,&stat,2);

	printf("\nCommon vocabulary\n\n");
	printf("Number of unique words\t\t\t%d\n\n",uniquecnt[2]);
	printing(h,&stat,3);

	//cleanup
	hash_destroy(h);
	fclose(drac);
	fclose(frank);
	free(wrd);
	wrd = NULL;
	return 0;
}
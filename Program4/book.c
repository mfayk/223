#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include "list.h"
#include "hash.h"
#include "book.h"


void calculate(struct hash_table *h, struct book_stats *stat){
	//initalize the values
	int i=0; 
	int k=0;
	int t=0;
	int w=0;
	struct book_word *temp;
	struct book_word *wrd = NULL;
	//this loop calculated the values for the longest words in book1
	for(i=0;i<HSZ;i++){
		wrd = list_first(h->table[i]);
		//check if word exist
		while(wrd != NULL){
			if(wrd->count[0] > 0){
				//fills array if empty
				if(stat->book1.longest[4]->word == NULL){
					k=0;
					while(stat->book1.longest[k]->word != NULL && k!=-1){
						
						k++;
					}
					if(stat->book1.longest[k]->word==NULL){
							stat->book1.longest[k]=wrd;
						}
				}
				else{
					if(strlen(wrd->word) > strlen(stat->book1.longest[4]->word)){
						stat->book1.longest[4]=wrd;
					}

				}
				//bubble sort
				if(stat->book1.longest[4]->word != NULL){
					for(t=0;t<4;t++){
						for(w=0;w<4-t;w++){
							if(strlen(stat->book1.longest[w]->word) < strlen(stat->book1.longest[w+1]->word)){
								temp = stat->book1.longest[w];
								stat->book1.longest[w]=stat->book1.longest[w+1];
								stat->book1.longest[w+1]=temp;
							}
						}
					}
				}
			}



			wrd = list_next(h->table[i]);
		}
	}
//this is calculation for the longest words for book two same process as loop above
	for(i=0;i<HSZ;i++){
		wrd = list_first(h->table[i]);
		while(wrd != NULL){
			if(wrd->count[1] > 0){
				//fills array if empty
				if(stat->book2.longest[4]->word == NULL){
					k=0;
					while(stat->book2.longest[k]->word != NULL && k!=-1){
						
						k++;
					}
					if(stat->book2.longest[k]->word==NULL){
							stat->book2.longest[k]=wrd;
						}
				}
				else{
					if(strlen(wrd->word) > strlen(stat->book2.longest[4]->word)){
						stat->book2.longest[4]=wrd;
					}

				}
				if(stat->book2.longest[4]->word != NULL){
					//bubble sort
					for(t=0;t<4;t++){
						for(w=0;w<4-t;w++){
							if(strlen(stat->book2.longest[w]->word) < strlen(stat->book2.longest[w+1]->word)){
								temp = stat->book2.longest[w];
								stat->book2.longest[w]=stat->book2.longest[w+1];
								stat->book2.longest[w+1]=temp;
							}
						}
					}
				}
			}



			wrd = list_next(h->table[i]);
		}
	}

//here i solve for the longest word in both files;
	for(i=0;i<HSZ;i++){
		wrd = list_first(h->table[i]);
		while(wrd != NULL){
			if(wrd->count[1] > 0 && wrd->count[0] > 0){
				//fills array if empty
				if(stat->both.longest[4]->word == NULL){
					k=0;
					while(stat->both.longest[k]->word != NULL && k!=-1){
						
						k++;
					}
					if(stat->both.longest[k]->word==NULL){
							stat->both.longest[k]=wrd;
						}
				}
				else{
					if(strlen(wrd->word) > strlen(stat->both.longest[4]->word)){
						stat->both.longest[4]=wrd;
					}

				}
				if(stat->both.longest[4]->word != NULL){
					//bubble sort	
					for(t=0;t<4;t++){
						for(w=0;w<4-t;w++){
							if(strlen(stat->both.longest[w]->word) < strlen(stat->both.longest[w+1]->word)){
								temp = stat->both.longest[w];
								stat->both.longest[w]=stat->both.longest[w+1];
								stat->both.longest[w+1]=temp;
							}
						}
					}
				}
			}



			wrd = list_next(h->table[i]);
		}
	}

//here i solve for the most used words in book1
	for(i=0;i<HSZ;i++){
		wrd = list_first(h->table[i]);
		while(wrd != NULL){
			if(wrd->count[0] > 0){
				//fill array if empty
				if(stat->book1.most_used[14]->word == NULL){
					k=0;
					while(stat->book1.most_used[k]->word != NULL && k!=-1){
						
						k++;
					}
					if(stat->book1.most_used[k]->word==NULL){
							stat->book1.most_used[k]=wrd;
						}
				}
				else{
					if((wrd->count[0]) > (stat->book1.most_used[14]->count[0])){
						stat->book1.most_used[14]=wrd;
					}

				}
				if(stat->book1.most_used[14]->word != NULL){
					//bubble sort
					for(t=0;t<14;t++){
						for(w=0;w<14-t;w++){
							if((stat->book1.most_used[w]->count[0]) < (stat->book1.most_used[w+1]->count[0])){
								temp = stat->book1.most_used[w];
								stat->book1.most_used[w]=stat->book1.most_used[w+1];
								stat->book1.most_used[w+1]=temp;
							}
						}
					}
				}

			}



			wrd = list_next(h->table[i]);
		}
	}
//this is the calculation for the most used words in book2
	for(i=0;i<HSZ;i++){
			wrd = list_first(h->table[i]);
			while(wrd != NULL){
				if(wrd->count[1] > 0){
					//fills array if empty
					if(stat->book2.most_used[14]->word == NULL){
						k=0;
						while(stat->book2.most_used[k]->word != NULL && k!=-1){
							
							k++;
						}
						if(stat->book2.most_used[k]->word==NULL){
								stat->book2.most_used[k]=wrd;
							}
					}
					else{
						if((wrd->count[1]) > (stat->book2.most_used[14]->count[1])){
							stat->book2.most_used[14]=wrd;
						}

					}
					if(stat->book2.most_used[14]->word != NULL){
					//bubble sort
						for(t=0;t<14;t++){
							for(w=0;w<14-t;w++){
								if((stat->book2.most_used[w]->count[1]) < (stat->book2.most_used[w+1]->count[1])){
									temp = stat->book2.most_used[w];
									stat->book2.most_used[w]=stat->book2.most_used[w+1];
									stat->book2.most_used[w+1]=temp;
									}
								}
							}
						}
				}

			wrd = list_next(h->table[i]);
		}
	}

//this is the calculation for the most used words that are in both of the books
for(i=0;i<HSZ;i++){
		wrd = list_first(h->table[i]);
		while(wrd != NULL){
			if(wrd->count[1] > 0 && wrd->count[0] > 0){
				//fills array if empty
				if(stat->both.most_used[14]->word == NULL){
					k=0;
					while(stat->both.most_used[k]->word != NULL && k!=-1){
						
						k++;
					}
					if(stat->both.most_used[k]->word==NULL){
							stat->both.most_used[k]=wrd;
						}
				}
				else{
					if((wrd->count[1] + wrd->count[0]) > (stat->both.most_used[14]->count[1] + stat->both.most_used[14]->count[0])){
						stat->both.most_used[14]=wrd;
					}

				}
				if(stat->both.most_used[14]->word != NULL){
					//bubble sort
					for(t=0;t<14;t++){
						for(w=0;w<14-t;w++){
							if((stat->both.most_used[w]->count[1]+stat->both.most_used[w]->count[0]) < (stat->both.most_used[w+1]->count[1]+stat->both.most_used[w+1]->count[0])){
								temp = stat->both.most_used[w];
								stat->both.most_used[w]=stat->both.most_used[w+1];
								stat->both.most_used[w+1]=temp;
							}
						}
					}
				}
			}

			wrd = list_next(h->table[i]);
		}
	}

//this is a calculation for the least used words in book1
	for(i=0;i<HSZ;i++){
		wrd = list_first(h->table[i]);
		while(wrd != NULL){
			if(wrd->count[0] > 0){
				//fills array if empty
				if(stat->book1.least_used[4]->word == NULL){
					k=0;
					while(stat->book1.least_used[k]->word != NULL && k!=-1){
						
						k++;
					}
					if(stat->book1.least_used[k]->word==NULL){
							stat->book1.least_used[k]=wrd;
						}
				}
				else{
					if((wrd->count[0]) < (stat->book1.least_used[4]->count[0]) || wrd->count[0] == 1){
						stat->book1.least_used[4]=wrd;
					}

				}
				if(stat->book1.least_used[4]->word != NULL){
					//here i do a bubble sort in descending order
					for(t=0;t<4;t++){
						for(w=0;w<4-t;w++){
							if((stat->book1.least_used[w]->count[0]) > (stat->book1.least_used[w+1]->count[0])){
								temp = stat->book1.least_used[w];
								stat->book1.least_used[w]=stat->book1.least_used[w+1];
								stat->book1.least_used[w+1]=temp;
								}
							}
						}
					}
			}



			wrd = list_next(h->table[i]);
		}
	}

//this is a calculation for the least used values in book2
	for(i=0;i<HSZ;i++){
			wrd = list_first(h->table[i]);
			while(wrd != NULL){
				if(wrd->count[1] > 0){
					//fills array if empty
					if(stat->book2.least_used[4]->word == NULL){
						k=0;
						while(stat->book2.least_used[k]->word != NULL && k!=-1){
							
							k++;
						}
						if(stat->book2.least_used[k]->word==NULL){
								stat->book2.least_used[k]=wrd;
							}
					}
					else{
						if((wrd->count[1]) < (stat->book2.least_used[4]->count[1]) || wrd->count[1] == 1){
							stat->book2.least_used[4]=wrd;
						}

					}
					if(stat->book2.least_used[4]->word != NULL){
						//this is a bubble sort in descending order
						for(t=0;t<4;t++){
							for(w=0;w<4-t;w++){
								if((stat->book2.least_used[w]->count[1]) > (stat->book2.least_used[w+1]->count[1])){
									temp = stat->book2.least_used[w];
									stat->book2.least_used[w]=stat->book2.least_used[w+1];
									stat->book2.least_used[w+1]=temp;
									}
								}
							}
						}
				}
				wrd = list_next(h->table[i]);
			}
		}

//this is the calculation for the least used words in both of the books
	for(i=0;i<HSZ;i++){
			wrd = list_first(h->table[i]);
			while(wrd != NULL){
				if(wrd->count[1] > 0 && wrd->count[0] > 0){
					//fills array if empty
					if(stat->both.least_used[4]->word == NULL){
						k=0;
						while(stat->both.least_used[k]->word != NULL && k!=-1){
							
							k++;
						}
						if(stat->both.least_used[k]->word==NULL){
								stat->both.least_used[k]=wrd;
							}
					}
					else{
						if(((wrd->count[1] + wrd->count[0]) < (stat->both.least_used[4]->count[1] + stat->both.least_used[4]->count[0])) || (wrd->count[1]+wrd->count[0]) == 2){
							stat->both.least_used[4]=wrd;
						}

					}
					if(stat->both.least_used[4]->word != NULL){
						//this is a reverse bubble sort that goes in descending order
						for(t=0;t<4;t++){
							for(w=0;w<4-t;w++){
								if((stat->both.least_used[w]->count[1]+stat->both.least_used[w]->count[0]) > (stat->both.least_used[w+1]->count[1]+stat->both.least_used[w+1]->count[0])){
									temp = stat->both.least_used[w];
									stat->both.least_used[w]=stat->both.least_used[w+1];
									stat->both.least_used[w+1]=temp;
									}
								}
							}
						}
				}



				wrd = list_next(h->table[i]);
			}
		}
}

void printing(struct hash_table *h, struct book_stats *stat, int book){
	int  i =0;
	//here i print the values for the first book
	if(book == 1){
		printf("\n5 largest words\n");
		for(i=0;i<5;i++){
			printf("%15s\t\t\ttimes used: %d\n",stat->book1.longest[i]->word,stat->book1.longest[i]->count[0]);
		}

		printf("\n15 most frequently used words\n");
		for(i=0;i<15;i++){
			printf("%15s\t\t\ttimes used: %d\n",stat->book1.most_used[i]->word,stat->book1.most_used[i]->count[0]);
		}
		printf("\n5 least frequently used words\n\n");
		for(i=0;i<5;i++){
			printf("%15s\t\t\ttimes used: %d\n",stat->book1.least_used[i]->word,stat->book1.least_used[i]->count[0]);
		}		
	}
	//here i print the values for the second book
	if(book == 2){
		printf("\n5 largest words\n");
		for(i=0;i<5;i++){
			printf("%15s\t\t\ttimes used: %d\n",stat->book2.longest[i]->word,stat->book2.longest[i]->count[1]);
		}
		printf("\n15 most frequently used words\n");
		for(i=0;i<15;i++){
			printf("%15s\t\t\ttimes used: %d\n",stat->book2.most_used[i]->word,stat->book2.most_used[i]->count[1]);
		}
		printf("\n5 least frequently used words\n");
		for(i=0;i<5;i++){
			printf("%15s\t\t\ttimes used: %d\n",stat->book2.least_used[i]->word,stat->book2.least_used[i]->count[1]);
		}
	}
	//here i print the values that pertain to both of the books
	if(book == 3){
		printf("\n5 largest words\n");
		for(i=0;i<5;i++){
			printf("%15s\t\t\ttimes used: %d\n",stat->both.longest[i]->word,stat->both.longest[i]->count[1] + stat->both.longest[i]->count[0]);
		}		
		
		printf("\n15 most frequently used words\n");
		for(i=0;i<15;i++){
			printf("%15s\t\t\ttimes used: %d\n",stat->both.most_used[i]->word,((stat->both.most_used[i]->count[1]+stat->both.most_used[i]->count[0])));
		}	

		printf("\n15 least frequently used words\n");
		for(i=0;i<5;i++){
			printf("%15s\t\t\ttimes used: %d\n",stat->both.least_used[i]->word,((stat->both.least_used[i]->count[1]+stat->both.least_used[i]->count[0])));
		}
	}

}
#include <stdio.h>
#include <stdlib.h>
#include "list.h"


struct list
{
	struct list_node *head;
	struct list_node *tail;
	struct list_node *current;
};

struct list_node
{
	struct list_node *prev;
	struct list_node *next;
	list_data data;
};

//this function allocates the list and returns the list
list list_init(void){
	struct list* lst = malloc(sizeof(struct list));
	if(lst == NULL){
		return NULL;
	}
	lst->head = NULL;
	lst->tail = NULL;
	lst->current = NULL;
	return lst;

}

//here is where i free the list and remove its contents
void list_finalize(list lst){
	list_first(lst);
	while(lst->head != NULL && lst->tail != NULL){
		list_remove(lst);
	}
	free(lst);
}

//in this funciton i add an new node to the front of the list
list_data list_insert(list lst, list_data data){
	struct list_node *newnode;
//here i chekc to see if the ist is empty
	if(lst->head == NULL && lst->tail == NULL){
		newnode = malloc(sizeof(struct list_node));
		newnode->data = data;
		newnode->prev = NULL;
		newnode->next = NULL;
		lst->head = newnode;
		lst->tail = lst->head;
		lst->current = lst->head;
		return lst->current->data;
	}
//if its not empty i rearrange the pointers in the list and add a newnode
	newnode = malloc(sizeof(struct list_node));
	newnode->data = data;
	newnode->prev = NULL;
	newnode->next = lst->head;
	lst->head->prev = newnode;
	lst->head = newnode;
	if(lst->head->next == NULL && lst->head->prev == NULL){
		lst->tail= lst->head;
	}
	while(lst->head->prev != NULL){
		lst->head = lst->head->prev;
	}
	lst->current = lst->head;
	return lst->current->data;
}

//in this function i add a node to the end of a list
list_data list_append(list lst, list_data data){

	struct list_node* newnode;
//here i check to see if the list is empty
	if(lst->head == NULL && lst->tail == NULL){
		newnode = malloc(sizeof(struct list_node));
		newnode->data = data;
		newnode->prev = NULL;
		newnode->next = NULL;
		lst->head = newnode;
		lst->tail = lst->head;
		lst->current = lst->head;
		return lst->current->data;
	}
//if the list is not empty i do some pointer malipulation to properly add it
	newnode = malloc(sizeof(struct list_node));
	newnode->data = data;
	newnode->next = NULL;
	newnode->prev = lst->tail;
	lst->tail->next = newnode;
	lst->tail = newnode;

	if(lst->tail->prev == NULL){
		lst->head = lst->tail;
	}
	lst->current = lst->tail;
	return lst->current->data;

}

list_data list_insert_before(list lst, list_data data){
//if current is null i cant insert before it
	if(lst->current == NULL){
		return NULL;
	}
//here is make the new node and add it to the list 
	struct list_node* newnode;
	newnode = malloc(sizeof(struct list_node));
	newnode->data = data;
	newnode->prev = lst->current->prev;
	newnode->next = lst->current;
	if(lst->current->prev != NULL){
		lst->current->prev->next = newnode;
	}
	lst->current->prev = newnode;
	lst->current = newnode;
//here i check to see if i just made a new head of the list
	while(lst->head->prev != NULL){
		lst->head=lst->head->prev;
	}
	return lst->current->data;
}

//this is where i add a value to the list after the current if NULL
//i return NULL
list_data list_insert_after(list lst, list_data data){
	if(lst->current == NULL){
		return NULL;
	}
//here i allocate and put the node in propper place
	struct list_node *newnode = malloc(sizeof(struct list_node));
	newnode->data = data;
	newnode->next = lst->current->next;
	newnode->prev = lst->current;
	if(lst->current->next != NULL){
		lst->current->next->prev = newnode;
	}
	lst->current->next = newnode;
	lst->current = newnode;
//here i checked if the item i inputed is the new tail
	while(lst->tail->next != NULL){
		lst->tail = lst->tail->next;
	} 
	return lst->current->data;
}

//here i remove items from the list
list_data list_remove(list lst){
//current NULL check
	if(lst->current == NULL){
		return NULL;
	}
//this is where i do some pointer changing to take items out of the list
	struct list_node *temp=lst->current;
	list_data tempData = lst->current->data;
	//this is if i remove the last item
	if(lst->head == lst->current && lst->head == lst->tail){
		free(temp);
		lst->head = NULL;
		lst->current = NULL;
		lst->tail = NULL;
		return tempData;
	}
	//this is if i remove the head
	if(lst->head == lst->current){
		lst->head = lst->head->next;
		lst->current->next->prev = NULL;
		lst->current = lst->current->next;
		free(temp);
		return tempData;
	}
	//this is if i remove the tail
	else if(lst->tail == lst->current){
		lst->tail = lst->tail->prev;
		lst->current->prev->next = NULL;
		free(temp);
		lst->current = NULL;
		return tempData;
	}
	lst->current->prev->next = lst->current->next;
	lst->current->next->prev = lst->current->prev;
	lst->current = lst->current->next;
	free(temp);
	return tempData;
}

//here i return the first item in the list
list_data list_first(list lst){
	//error check
	if(lst->head == NULL){
		return NULL;
	}
	lst->current = lst->head;
	return lst->current->data;
}

//here i return the next item in the list
list_data list_next(list lst){
	//error checks
	if(lst->current == NULL){
		return NULL;
	}
	if(lst->current->next == NULL){
		return NULL;
	}
	lst->current = lst->current->next;
	return lst->current->data;

}

//here i return the previous item in the list
list_data list_prev(list lst){
	//error checks
	if(lst->current == NULL){
		return NULL;
	}
	if(lst->current->prev == NULL){
		return NULL;
	}
	lst->current = lst->current->prev;
	return lst->current->data;
}

//here i return the last item in the list
list_data list_last(list lst){
	//error checks
	if(lst->tail == NULL){
		return NULL;
	}
	lst->current = lst->tail;
	return lst->current->data;
}

//here i return the current item in the list
list_data list_curr(list lst){
	//error checks
	if(lst->current == NULL){
		return NULL;
	}
	return lst->current->data;
}
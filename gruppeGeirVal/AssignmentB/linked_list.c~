#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"

list_t list_create()
{	
	printf("start of creation");
	list_t list = malloc(sizeof(struct list));
	list -> head = null;
	list -> tail = null;
	list -> length = 0;
	printf("end of creation");
	return list;
}

void list_delete(list_t list)
{
	struct node* currentNode = list->head;
	struct node* nextNode = currentNode->next;

	while(currentNode != null){
		free(currentNode);
		currentNode = nextNode;
		nextNode = currentNode->next;	
	}
	
	free(nextNode);
	
	free(list);
}

void list_insert(list_t list, int index, int data){
	
	printf("append valued %i\n",index);
	struct node* newNode;
	struct node* currentNode = list -> head;

	newNode -> data = data;
	if(index == list -> length){
		if(list -> tail != null){
			list -> tail -> next = newNode ;
			newNode -> prev = list -> tail;
		}else{
			list -> head = newNode;
		}
		list -> tail = newNode ;
		

	}else if(index==0){
		newNode -> next = list -> head;
		list -> head -> prev = newNode;
		list -> head = newNode ;

	}else{
	
		int i = 0;
		while(i+1 < index){
			currentNode = currentNode -> next;
			i++;
		}
	
		newNode -> next = currentNode -> next;
		newNode -> prev = currentNode;

		currentNode -> next = newNode;
		newNode -> next -> prev = newNode;
	}
	list -> length = list -> length +1;		
}

void list_append(list_t list, int data)
{

}

void list_print(list_t list)
{

}

long list_sum(list_t list)
{

}

int list_get(list_t list, int index)
{

}

int list_extract(list_t list, int index)
{

}

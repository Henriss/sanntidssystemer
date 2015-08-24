#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"

list_t list_create()
{
	list_t newList = malloc(sizeof(struct list));
	(*newList).head = NULL;
	(*newList).length = 0;
	(*newList).tail = NULL;

	return newList;
}

void list_delete(list_t list)
{
	node_t deleteNode = list->head;
	while(deleteNode->next != NULL){
		deleteNode = deleteNode->next;
		free(deleteNode->prev);
	}
	free(deleteNode);
	free(list);
}

void list_insert(list_t list, int index, int data)
{
	if(index == 0 && list) {
		node_t newNode = malloc(sizeof(struct node));
		newNode->data = data;
		newNode->next = list->head;
		newNode->prev = NULL;
		if(list->head != NULL) {
			list->head->prev = newNode;
			list->head = newNode;
		}

	} else if(index > list->length) {
		list_append(list,data);
	} else if(index < 0) {
		list->length -= 1;
		// do nothing eroor eoror
	} else {
		node_t newNode = malloc(sizeof(struct node));
		node_t currentNode = list->head;
		int i = 0;
		for (; i < index-1; i++) {
			currentNode = currentNode->next;
		}
		newNode->next = currentNode->next;
		currentNode->next = newNode;
		newNode->prev = currentNode;
		newNode->data = data;
		newNode->next->prev = newNode;
	}
	list->length += 1;
}

void list_append(list_t list, int data)
{
	if(list->length == 0) {
		node_t firstNode = malloc(sizeof(struct node));
		firstNode->data = data;
		firstNode->next = NULL;
		firstNode->prev = NULL;
		list->head = firstNode;
		list->tail = firstNode;
		list->length = 1;
	} else {
		node_t newNode = malloc(sizeof(struct node));
		newNode->data = data;
		newNode->next = NULL;
		newNode->prev = list->tail;
		list->tail->next = newNode;
		list->tail = newNode;
		list->length += 1;
	}
}

void list_print(list_t list)
{
	if(list->length >0){
		node_t printNode = list->head;
	printf("%i ", printNode->data );

	while(printNode->next != NULL){
		printNode = printNode->next;
		printf("%i ", printNode->data);
	}
	}
	printf("\n");
}

long list_sum(list_t list)
{
	node_t sumNode = list->head;
	long sum = sumNode->data;
	while (sumNode->next != NULL) {
		sumNode = sumNode->next;
		sum += sumNode->data;
	}
	return sum;
}

int list_get(list_t list, int index)
{
	node_t currentNode = list->head;
	int i = 0;
	for(; i < index; i++){
		currentNode = currentNode->next;
	}
	return currentNode->data;
}

int list_extract(list_t list, int index)
{
	node_t currentNode = list->head;
	int i = 0;
	int data;
	if(index >= list->length) {
		currentNode = list->tail;
		list->tail = currentNode->prev;
		data = currentNode->data;
		free(currentNode);
		list->length -= 1;
		return data;
	} else if(index <= 0){
		currentNode = list->head;
		list->head = currentNode->next;
		data = currentNode->data;
		free(currentNode);
		list->length -= 1;
		return data;
	}
	for(; i < index; i++){
		currentNode = currentNode->next;
	}
	currentNode->prev->next = currentNode->next;
	currentNode->next->prev = currentNode->prev;
	data = currentNode->data;
	free(currentNode);
	list->length -= 1;
	return data;

}

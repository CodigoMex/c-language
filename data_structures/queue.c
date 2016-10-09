#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

struct Queue* init_queue()
{
	struct Queue *queue = malloc(sizeof(struct Queue));

	if(!queue){
		printf("Error: can't allocate memory to queue! %s\n",
				strerror(errno));
		return NULL;
	}

	queue->Head = NULL;
	queue->Tail = NULL;
	queue->size = 0;

	return queue;
}

void free_queue(struct Queue *queue)
{
	if(!queue)
		return;

	if(queue->size <= 0){
		free(queue);
		return;
	}

	struct Item *item;
	item = queue->Head;

	while(queue->size >= 0){
		struct Item *item;
		item = dequeue(queue);
		if(!item){
			free(item);
			queue->size--;
		}
	}
}

int enqueue(struct Queue *queue, int value)
{
	if(!queue){
		printf("Error: can't enqueue in a null queue!\n");
		return -1;
	}

	// The queue is full
	if( queue->size == MAX_ITEMS ) {
		printf("Info: the queue is FULL\n");
		return -1;
	}

	struct Item *item = malloc(sizeof(struct Item));

	if (!item) {
		return -1;
	}

	item->value = value;
	item->next = NULL;

	// The queue is empty
	if( queue->Head == NULL && queue->Tail == NULL ) {
		queue->Tail = item;
		queue->Head = item;
		queue->size++;
	}
	// The queue has space for more items
	else {
		struct Item *temp;
		temp = queue->Tail;
		queue->Tail = item;
		temp->next = item;
		queue->size++;
	}

	return 0;
}

struct Item *dequeue(struct Queue *queue)
{
	// The queue is null
	if(!queue){
		printf("Error: can't enqueue in a null queue!\n");
		return NULL;
	}

	struct Item *item;
	item = queue->Head;

	// The queue is empty
	if( queue->Head == NULL && queue->Tail == NULL ) {
		return NULL;
	}
	// The queue has only one item
	if( queue->Head == queue->Tail) {
		queue->Head = NULL;
		queue->Tail = NULL;
		queue->size--;
	}
	// The queue has more than one item
	else {
		queue->Head = item->next;
		queue->size--;
	}

	return item;
}

#ifndef _QUEUE_H_
#define _QUEUE_H_

#define MAX_ITEMS 50

struct Item {
	int value;
	struct Item *next;
};

struct Queue {
	struct Item *Head;
	struct Item *Tail;
	int size;
};

struct Queue* init_queue();
void free_queue(struct Queue *queue);
int enqueue(struct Queue *queue, int value);
struct Item *dequeue();

#endif

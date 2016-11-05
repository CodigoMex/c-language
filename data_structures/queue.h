#ifndef _QUEUE_H_
#define _QUEUE_H_

#define MAX_ITEMS 50

enum STATE_QUEUE {
    EMPTY,
    HAS_DATA,
    FULL
};

struct Item {
	int value;
	struct Item *next;
};

struct Queue {
	struct Item *Head;
	struct Item *Tail;
	int size;
    enum STATE_QUEUE state;
};

struct Queue* init_queue();
void free_queue(struct Queue *queue);
int enqueue(struct Queue *queue, int value);
struct Item *dequeue();

#endif

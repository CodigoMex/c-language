#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main()
{
	struct Queue *q;
	q = init_queue();
	enqueue(q, 5);
	enqueue(q, 4);
	enqueue(q, 6);
	struct Item *i;
	i = dequeue(q);
	printf("Data: %d\n", i->value);
	free(i);
	i = dequeue(q);
	printf("Data: %d\n", i->value);
	free(i);
	i = dequeue(q);
	printf("Data: %d\n", i->value);
	free(i);
	free_queue(q);

	return 0;
}

all: queue.out

queue.out: queue.c main.c
	gcc -g queue.c main.c -o queue.out

test: test.c queue.c
	gcc -o test.out test.c queue.c -lcunit
	./test.out

clean:
	rm *.out

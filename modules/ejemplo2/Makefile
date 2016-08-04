all: counter.out

counter.out: counter.c main.c
	gcc -c counter.c -o counter.o
	gcc -c main.c -o main.o
	gcc counter.o main.o -o counter.out

clean:
	rm *.o
	rm *.out


all: test.out

test.out: arp.c ip.c test.c
	cc -c arp.c
	cc -c ip.c
	cc test.c arp.o ip.o -o test.out

clean:
	rm *.o
	rm *.out

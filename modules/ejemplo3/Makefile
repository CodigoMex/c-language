CFLAGS = -g
OBJ=ia.o hist.o

all: hist.out

hist.out: $(OBJ)
	$(CC) $(CFLAGS) -o hist.out $(OBJ)

hist.o:ia.h hist.c

ia.o:ia.h ia.c

run: hist.out data
	./hist.out data
clean:
	rm *.out

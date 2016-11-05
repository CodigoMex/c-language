all: help

COV-FLAGS := -fprofile-arcs -ftest-coverage
C-FLAGS := -Wall -Wextra

help:
	@echo "usage:"
	@echo "make target"
	@echo "targets are: build debug test coverage indent valgrind-test valgrind-debug clean"

valgrind-test:
	valgrind --leak-check=full --leak-resolution=high ./test/test_runner.out

valgrind-debug:
	valgrind --leak-check=full --leak-resolution=high ./debug/queue.out

indent:
	indent -kr -nut *.c

build: queue.c
	mkdir -p build
	gcc -o build/queue.o ${C-FLAGS} -c queue.c
	ar rcs build/libqueue.a build/queue.o

debug: queue.c main.c
	mkdir -p debug
	gcc -o debug/queue.o ${C-FLAGS} -g -c queue.c
	ar rcs debug/libqueue.a debug/queue.o
	gcc -o debug/queue.out ${C-FLAGS} -g main.c debug/libqueue.a

test: test.c queue.c
	mkdir -p test
	gcc -o test/queue.o ${C-FLAGS} -g -c queue.c
	ar rcs test/libqueue.a test/queue.o
	gcc -o test/test_runner.out ${C-FLAGS} -g test.c test/libqueue.a -lcunit
	./test/test_runner.out

coverage: queue.c test.c
	mkdir -p coverage
	gcc -o coverage/queue.o -g ${COV-FLAGS} ${C-FLAGS} -c queue.c
	ar rcs coverage/libqueue.a coverage/queue.o
	gcc -o coverage/test_runner.out -g ${COV-FLAGS} ${C-FLAGS} test.c coverage/libqueue.a -lcunit
	./coverage/test_runner.out
	mv *.gcda coverage
	mv *.gcno coverage
	lcov --capture --directory coverage --output-file coverage/testcov.info
	genhtml coverage/testcov.info --output-directory coverage

clean:
	@echo "Cleaning"
	@rm -rf build
	@rm -rf debug
	@rm -rf test
	@rm -rf coverage
	@rm *~

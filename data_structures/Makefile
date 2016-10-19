all: build debug test coverage

COV-FLAGS := -fprofile-arcs -ftest-coverage

build: queue.c
	mkdir -p build
	gcc -c queue.c -o build/queue.o
	ar rcs build/libqueue.a build/queue.o

debug: queue.c main.c
	mkdir -p debug
	gcc -o debug/queue.o -g -c queue.c
	ar rcs debug/libqueue.a debug/queue.o
	gcc -o debug/queue.out -g main.c debug/libqueue.a

test: test.c queue.c
	mkdir -p test
	gcc -o test/queue.o -g -c queue.c
	ar rcs test/libqueue.a test/queue.o
	gcc -o test/test_runner.out -g test.c test/libqueue.a -lcunit
	./test/test_runner.out

coverage: queue.c test.c
	mkdir -p coverage
	gcc -o coverage/queue.o -g ${COV-FLAGS} -c queue.c
	ar rcs coverage/libqueue.a coverage/queue.o
	gcc -o coverage/test_runner.out -g ${COV-FLAGS} test.c coverage/libqueue.a -lcunit
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

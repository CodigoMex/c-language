#include <stdio.h>

typedef struct {
	void* fn;		//pointer void
	void (*fn2)(void);	//pointer to a function
	void* param;
} event;

void print()
{
	printf("Hello\n");
}

int main()
{
	event e;
	e.fn = &print;		//pointing to the function

	//this also work, if you know why write a better comment
	//e.fn = print;
	((void(*)())e.fn)();	//calling the function

	e.fn2 = &print;		//pointing to the function
	(*e.fn2)();		//calling the function

	return 0;
}

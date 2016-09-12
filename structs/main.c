#include <stdio.h>
#include <string.h>

struct message {
	char text[40];
	int integer;
};

struct message create_message()
{
	struct message msg;

	strcpy(msg.text, "Este es el mensaje");
	msg.integer = 23;

	return msg;
}

int main()
{
	struct message msg = create_message();

	printf("msg: %s\n",msg.text);
	printf("integer: %d\n", msg.integer);

	return 0;
}
